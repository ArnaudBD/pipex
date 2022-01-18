#include "includes/pipex.h"

char	*pathfinder(char *envp[], char *cmd)
{
	char	**paths;
	char	*tmp;
	char	*res;
	int		i;

	i = 0;
	paths = path_list(envp);
	while (cmd && cmd[i])
	{
		if (cmd[i] == ' ')
		{
			cmd[i] = 0;
			break ;
		}
		i++;
	}
	i = 0;
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/", 0);
		res = ft_strjoin(tmp, cmd, 0);
		free(tmp);
		if (path_tester(res) == 1)
			break ;
		free(res);
		i++;
	}
	i = 0;
	while (paths[i])
		free(paths[i++]);
	free(paths);
	printf("path found by pathfinder is '%s'\n", res);
	return (res);
}

int main(int argc, char *argv[], char *envp[])
{
	char	*path;
	char	**cmd;
	int		pid[2];
	int		i;
	int		pipefd[2];
(void)argc;
	// if (argc != 5)
	// {
	// 	printf("You have to use the following mode: 'file1 cmd1 cmd2 file2'\n");
	// 	exit (EXIT_FAILURE);
	// }
	cmd = ft_split(argv[1], ' ');
	path = pathfinder(envp, cmd[0]);
	i = 0;
	while (cmd[i])
		i++;
	printf("cmd: %s\n", *cmd);
	printf("Path: %s\n", path);
	if (pipe(pipefd) == -1)
		exit (EXIT_FAILURE);
	pid[0] = fork();
	if (pid[0] == -1)
		printf("fork() Error\n");
	if (pid[0] == 0)
	{
		printf("Child 1 process just started\n");
		// Child1 Process (cmd1)
		dup2(pipefd[1], 1);
		close(pipefd[0]);
		execve(path, cmd, envp);
		close(pipefd[1]);
		freedom(cmd, i);
		free(path);
	}
	wait(NULL);
	freedom(cmd, i);
	free(path);
	cmd = ft_split(argv[2], ' ');
	path = pathfinder(envp, cmd[0]);
	while (cmd[i])
		i++;
	pid[1] = fork();
	if (pid[1] == -1)
		printf("Error\n");
	if (pid[1] == 0)
	{
		printf("Child 2 process just started\n");
		// Child2 Process (cmd2)
		dup2(pipefd[0], STDIN_FILENO);
		close(pipefd[1]);
		execve(path, cmd, envp);
		close(pipefd[0]);
		freedom(cmd, i);
		free(path);
		close(pipefd[0]);
	}
	// Parent Process
	close(pipefd[0]);
	close(pipefd[1]);
	// waitpid(pid[0], NULL, 0);
	waitpid(pid[1], NULL, 0);
	freedom(cmd, i);
	free(path);
	printf("\nSuccess\n");
	return (0);
}