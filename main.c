#include "includes/pipex.h"

int main(int argc, char *argv[], char *envp[])
{
	char	*path;
	char	**cmd;
	int		pid[2];
	int		i;
	int		fd[3];

	if (argc != 5)
	{
		printf("You have to follow this patern: 'file1 \"cmd1\" \"cmd2\" file2'\n");
		return (EXIT_FAILURE);
	}
	if (pipe(fd) == -1)
		return (EXIT_FAILURE);
	i = cmd_interpreter(&cmd, &path, argv[2], envp);
	pid[0] = fork();
	if (pid[0] == -1)
		return (EXIT_FAILURE);
	if (pid[0] == 0)
		ft_child1(fd, path, cmd, envp, i, argv);
	freedom(cmd, i);
	free(path);
	i = cmd_interpreter(&cmd, &path, argv[3], envp);
	pid[1] = fork();
	if (pid[1] == -1)
		return (EXIT_FAILURE);
	if (pid[1] == 0)
		ft_child2(fd, path, cmd, envp, i, argv);
	close(fd[0]);
	close(fd[1]);
	wait(NULL);
	wait(NULL);
	freedom(cmd, i);
	free(path);
	return (0);
}