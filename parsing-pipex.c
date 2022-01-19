#include "includes/pipex.h"

char **path_list(char *env[])
{
	int	i;
	int	j;
	char	*path;
	char	**tab_paths;
	
	i = 0;
	path = "PATH=";
	i = 0;
	j = 0;
	while (env[i])
	{
		if (env[i][j] == path[j])
			j++;
		else if (j == 5)
			break ;
		else
		{
			j = 0;
			i++;
		}
	}
	path = &env[i][j];
	tab_paths = ft_split(path, ':');
	return tab_paths;
}

int	path_tester(char *path)
{
	if (access(path, X_OK) == -1)
		return (-1);
	return (1);
}
