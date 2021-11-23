#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# include <stdlib.h>
# include <unistd.h>
int		get_next_line(int fd, char **line);
int		ft_stlen(const char *s);
int		ft_str_chr(const char *s);
char	*ft_join(char *s1, char *s2);
char	*ft_mini_join(const char *s1, const char *s2, char *dst);
char	*ft_push_to_line(char *temp);
char	*ft_remove_to_n(char *temp);
#endif
