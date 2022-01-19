/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiju-du <abiju-du@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 20:55:55 by abiju-du          #+#    #+#             */
/*   Updated: 2022/01/19 20:55:59 by abiju-du         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	ft_child1(t_list *param, char *envp[], char *argv[])
{
	param->i = cmd_interpreter(param, argv[2], envp);
	param->fd[2] = open(argv[1], O_RDONLY);
	dup2(param->fd[2], 0);
	dup2(param->fd[1], 1);
	close(param->fd[0]);
	execve(param->path, param->cmd, envp);
	close(param->fd[2]);
	close(param->fd[1]);
	freedom(param->cmd, param->i);
	free(param->path);
	free(param);
	exit (EXIT_FAILURE);
}

void	ft_child2(t_list *param, char *envp[], char *argv[])
{
	param->i = cmd_interpreter(param, argv[3], envp);
	param->fd[2] = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	dup2(param->fd[2], 1);
	dup2(param->fd[0], STDIN_FILENO);
	close(param->fd[1]);
	execve(param->path, param->cmd, envp);
	close(param->fd[0]);
	freedom(param->cmd, param->i);
	free(param->path);
	free(param);
	exit (EXIT_FAILURE);
}

int	cmd_interpreter(t_list *param, char *argvx, char *envp[])
{
	int	i;

	param->cmd = ft_split(argvx, ' ');
	param->path = pathfinder(envp, param->cmd[0]);
	if (param->cmd == NULL || param->path == NULL)
		exit (EXIT_FAILURE);
	i = 0;
	while ((param->cmd)[i])
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
