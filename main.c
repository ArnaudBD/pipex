/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiju-du <abiju-du@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 20:42:09 by abiju-du          #+#    #+#             */
/*   Updated: 2022/01/19 20:42:12 by abiju-du         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_list	*param;

	arg_ok(argc);
	param = malloc(sizeof(*param));
	init(param);
	if (pipe(param->fd) == -1)
		return (EXIT_FAILURE);
	param->pid[0] = fork();
	if (param->pid[0] == -1)
		return (EXIT_FAILURE);
	if (param->pid[0] == 0)
		ft_child1(param, envp, argv);
	free(param->path);
	param->pid[1] = fork();
	if (param->pid[1] == -1)
		return (EXIT_FAILURE);
	if (param->pid[1] == 0)
		ft_child2(param, envp, argv);
	close(param->fd[0]);
	close(param->fd[1]);
	wait(NULL);
	wait(NULL);
	free(param->path);
	free(param);
	return (0);
}
