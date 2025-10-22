#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 3
#endif

char	*get_next_line(int fd);
int		ft_strlen(const char *str);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);

#endif