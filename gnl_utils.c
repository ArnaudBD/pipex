/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiju-du <abiju-du@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 20:42:44 by abiju-du          #+#    #+#             */
/*   Updated: 2022/01/19 20:42:48 by abiju-du         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"

int	n_search(char *str)
{
	int	i;

	if (str == NULL)
		return (-1);
	i = 0;
	while (str[i] != '\n' && str[i] != 0)
		i++;
	if (str[i] == '\n')
		return (i);
	else
		return (-1);
}

int	mv_first_line(char *str, char **dest)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		dest[0] = malloc(1);
		dest[0][0] = 0;
		return (0);
	}
	while (str[i] != '\n' && str[i] != 0 && str[i] != EOF)
		i++;
	dest[0] = malloc(sizeof(char) * i + 1);
	if (!dest[0])
		return (-1);
	dest[0][i--] = 0;
	while (i >= 0)
	{
		dest[0][i] = str[i];
		i--;
	}
	return (1);
}

char	*sup_first_line(char *str)
{
	int		i;
	int		j;
	int		len;
	char	*new_str;

	i = 0;
	j = 0;
	new_str = NULL;
	while (str[i] != '\n' && str[i] != 0)
		i++;
	len = ft_strlen(str) - i - 1;
	if (len >= 0)
	{
		new_str = malloc(sizeof(*new_str) * len + 1);
		if (!new_str)
			return (0);
		i++;
		while (j < len)
			new_str[j++] = str[i++];
		new_str[j] = 0;
	}
	free(str);
	return (new_str);
}
