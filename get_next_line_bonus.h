#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);

ssize_t	read_buff(int fd, char **buff, ssize_t *read_ret);
void	handle_buff(char **stat_str, char **buff);
char	*final_line(char **stat_str);

size_t	ft_strlen(char const *s);
char	*ft_strchr(char const *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strldup(char const *s, int len);
void	ft_handleptr(char **ptr, int mode);

#en