#include <stdio.h>
#include <unistd.h>
#include <paths.h>
#include "includes/pipex.h"


// char **path_list(char *env[])
// {
// 	int	i;
// 	int	j;
// 	char	*path;
// 	char	**tab_paths;
	
// 	i = 0;
// 	path = "PATH=";
// 	i = 0;
// 	j = 0;
// 	while (env[i])
// 	{
// 		if (env[i][j] == path[j])
// 		{
// 			j++;
// 		}
// 		else if (j == 5)
// 			break ;
// 		else
// 		{
// 			j = 0;
// 			i++;
// 		}
// 	}
// 	path = &env[i][j];
// 	tab_paths = ft_split(path, ':');

// 	i = 0;
	
// 	return tab_paths;
	
// 	// ft_split(path)
// }

void imodifier(int *i)
{
*i = 12;
}

int	main(int argc, char *argv[], char *env[])
{
	int i = 0;
	imodifier(&i);
	printf("i = %d\n", i);
	// char **paths = path_list(env);
	// while (paths[i])	
	// {
	// 	printf("|==> %s <==|\n", paths[i]);
	// 	i++;
	// }
}