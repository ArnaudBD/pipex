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
	int		pid;
	int		i;

	if (argc != 5)
		return (1);
	cmd = ft_split(argv[1], ' ');
	path = pathfinder(envp, cmd[0]);
	i = 0;
	while (cmd[i])
		i++;
	printf("cmd: %s\n", *cmd);
	printf("Path: %s\n", path);
	pid = fork();
	if (pid == -1)
		printf("fork() Error\n");
	if (pid == 0)
	{
		// Child Process
		execve(path, cmd, envp);
		freedom(cmd, i);
		free(path);
		
	}
	else
	{
		free(path);
		// Parent Process 

		wait(NULL);
		freedom(cmd, i);
		printf("\nSuccess\n");
		return (0);

	}
}