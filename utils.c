#include "includes/pipex.h"


int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		i++;
	}
	return (i);
}

void ft_child1(int *fd, char *path, char **cmd, char *envp[], int i, char *argv[])
{
	(void)i;

	fd[2] = open(argv[1], O_RDONLY);
	dup2(fd[2], 0);
	dup2(fd[1], 1);
	close(fd[0]);
	execve(path, cmd, envp);
	close(fd[2]);
	close(fd[1]);
	freedom(cmd, i);
	free(path);
	exit (EXIT_FAILURE);
}

void ft_child2(int *fd, char *path, char **cmd, char *envp[], int i, char *argv[])
{
	(void)i;
	fd[2] = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	dup2(fd[2], 1);
	dup2(fd[0], STDIN_FILENO);
	close(fd[1]);
	execve(path, cmd, envp);
	close(fd[0]);
	freedom(cmd, i);
	free(path);
	exit (EXIT_FAILURE);
}

int cmd_interpreter(char ***cmd, char **path, char *argvx, char *envp[])
{
	int i;

	*cmd = ft_split(argvx, ' ');
	*path = pathfinder(envp, *cmd[0]);
	if (*cmd == NULL || *path == NULL)
		exit (EXIT_FAILURE);
	i = 0;
	while ((*cmd)[i])
		i++;
	return (i);
}

char	*pathfinder(char *envp[], char *cmd)
{
	char	**paths;
	char	*tmp;
	char	*res;
	int		i;

	i = 0;
	paths = path_list(envp);
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/", 0);
		res = ft_strjoin(tmp, cmd, 0);
		free(tmp);
		if (path_tester(res) == 1)
			break ;
		free(res);
		res = NULL;
		i++;
	}
	i = 0;
	while (paths[i])
		free(paths[i++]);
	free(paths);
	if (res == NULL)
		res = strdup(cmd);
	return (res);
}
