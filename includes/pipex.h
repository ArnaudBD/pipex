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



// UTILS
int		ft_strlen(char const *str);
void ft_child1(int *fd, char *path, char **cmd, char *envp[], int i, char *argv[]);
void ft_child2(int *fd, char *path, char **cmd, char *envp[], int i, char *argv[]);
int cmd_interpreter(char ***cmd, char **path, char *argvx, char *envp[]);
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
int	nb_words(char const *s, char c);
char	**freedom(char **tab, int j);

// PARSING
char **path_list(char *env[]);
int	path_tester(char *path);


#endif