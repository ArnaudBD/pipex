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

	cmd = argv[1];
	path = pathfinder(argv, envp, cmd);
	printf("Path: %s\n", path);
	execve(path, &argv[1], envp);
	return (0);
}