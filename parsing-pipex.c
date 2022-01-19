/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing-pipex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiju-du <abiju-du@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 20:45:58 by abiju-du          #+#    #+#             */
/*   Updated: 2022/01/19 20:46:00 by abiju-du         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"

char	**path_list(char *env[])
{
	int		i;
	int		j;
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
	return (tab_paths);
}

int	path_tester(char *path)
{
	if (access(path, X_OK) == -1)
		return (-1);
	return (1);
}

void	arg_ok(int argc)
{
	if (argc != 5)
	{
		printf("You have to follow this patern: 'file1 \"cmd1\" \"cmd2\" file2'\n");
		exit (EXIT_FAILURE);
	}
}

void	init(t_list *param)
{
	param->cmd = 0;
	param->fd[0] = 0;
	param->fd[1] = 0;
	param->fd[2] = 0;
	param->pid[0] = -1;
	param->pid[1] = -1;
}

