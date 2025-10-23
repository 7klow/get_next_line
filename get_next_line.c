#include "get_next_line.h"

char	*get_line(char *str)
{
	char	*line;
	int		index;
	int		j;

	index = 0;
	j = 0;
	if (!str || !*str)
		return (NULL);
	while (str[index] && str[index] != '\n')
		index++;
	line = malloc(index + (str[index] == '\n') + 1);
	if (!line)
		return (NULL);
	while (str[j] && str[j] != '\n')
	{
		line[j] = str[j];
		j++;
	}
	if (str[j] == '\n')
		line[j++] = '\n';
	line[j] = '\0';
	return (line);
}

char	*str_clean(char *str)
{
	char	*next_str;
	int		index;
	int		j;

	index = 0;
	j = 0;
	if (!str)
		return (NULL);
	while (str[index] != '\n' && str[index])
		index++;
	if (str[index] == '\n')
		index++;
	if (!str[index])
		return (free(str), NULL);
	next_str = malloc(ft_strlen(&str[index]) + 1);
	if (!next_str)
		return (free(str), NULL);
	while (str[index])
		next_str[j++] = str[index++];
	next_str[j] = '\0';
	return (free(str), next_str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*str_line;
	char		buff[BUFFER_SIZE + 1];
	int			bytes;

	bytes = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (str == NULL || (!ft_strchr(str, '\n') && bytes > 0))
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes < 0)
			return (NULL);
		buff[bytes] = '\0';
		str = ft_strjoin(str, buff);
		if (!str)
			return (NULL);
	}
	str_line = get_line(str);
	str = str_clean(str);
	return (str_line);
}

int main(void)
{
    char *str;
    int line = 0;

    while (line < 5)
    {
        str = get_next_line(0);
        if (!str)
            return (1);
        printf("%s", str);
        free(str);
        line++;
    }
    return (0);
}