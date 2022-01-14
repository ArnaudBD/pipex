#include "includes/pipex.h"

char	*pathfinder(char *argv[], char *envp[], char *cmd)
{
	(void)argv;
	(void)envp;
	char	*path;
	int		i;

	i = 0;
	path = "/bin/";
	while (cmd && cmd[i])
	{
		if (cmd[i] == ' ')
		{
			cmd[i] = 0;
			break ;
		}
		i++;
	}
	
	path = ft_strjoin(path, cmd, 0);


	return (path);
}

int main(int argc, char *argv[], char *envp[])
{
	(void)argc;
	char	*path;
	char	*cmd;
	int		pid;

	cmd = argv[1];
	path = pathfinder(argv, envp, cmd);
	printf("Path: %s\n", path);
	pid = fork();
	if (pid == -1)
		printf("fork() Error\n");
	if (pid == 0)
	{
		// Child Process
		execve(path, &argv[1], envp);
	}
	else
	{
		wait(NULL);
		// Parent Process 
		printf("\nSuccess\n");
		return (0);

	}
}