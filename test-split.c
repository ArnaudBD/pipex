#include <stdio.h>
#include <unistd.h>
#include <paths.h>
#include "includes/pipex.h"


int	main(int argc, char *argv[], char *env[])
{
	int	i;
	int	j;
	char	*path;
	char	**tab_paths;
	
	i = 0;
	path = "PATH=";
	while (i < argc)
	{
		printf("%s\n", argv[i]);
		i++;
	}
	i = 0;
	j = 0;
	while (env[i])
	{
		printf("line == %s\n", env[i]);
		if (env[i][j] == path[j])
		{
			printf("env letter is  %c\n", env[i][j]);
			printf("path letter is %c\n", path[j]);
			printf("j == %d\n", j++);
		}
		else if (j == 5)
			break ;
		else
		{
			j = 0;
			i++;
		}
	}
	path = &env[i][j];
	printf("new path == %s", path);
	tab_paths = ft_split(path, ':');

	i = 0;
	while (tab_paths[i])
	{
		printf("%s\n", tab_paths[i]);
		i++;
	}
	
	return 0;
	
	// ft_split(path)
}