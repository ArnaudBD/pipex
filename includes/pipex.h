/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiju-du <abiju-du@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 20:58:27 by abiju-du          #+#    #+#             */
/*   Updated: 2022/01/19 20:58:31 by abiju-du         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# define BUFFER_SIZE 15
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <errno.h>
# include <string.h>
# include <stdlib.h>
# include <paths.h>
# include <fcntl.h>

typedef struct s_list
{
	char	*path;
	char	**cmd;
	int		pid[2];
	int		i;
	int		fd[3];
}	t_list;

// UTILS
int		ft_strlen(char const *str);
void	ft_child1(t_list *param, char *envp[], char *argv[]);
void	ft_child2(t_list *param, char *envp[], char *argv[]);
int		cmd_interpreter(t_list *param, char *argvx, char *envp[]);
char	*pathfinder(char *envp[], char *cmd);

//GNL 
int		get_next_line(int fd, char **line);
char	*mv_next_line(char **line_dest, char *str);
int		n_search(char *str);
void	ft_putnbr_fd(int nb, int fd);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strjoin(char const *s1, char const *s2, int need2free);
char	*first_line(char *str);
char	*cut_first_line(char *str);
int		mv_first_line(char *str, char **dest);
char	*sup_first_line(char *str);
void	*ft_memmove(void *dst, const void *src, size_t len);

// SPLIT
char	**ft_split(char const *s, char c);
char	**ft_malloc_split(char const *s, char c, char **tab, int i);
char	**filling_good(char const *s, char **tab, char c);
int		nb_words(char const *s, char c);
char	**freedom(char **tab, int j);

// PARSING
char	**path_list(char *env[]);
int		path_tester(char *path);
void	arg_ok(int argc);
void	init(t_list *param);

#endif
