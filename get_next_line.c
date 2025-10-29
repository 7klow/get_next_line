/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontrem <ncontrem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 08:56:48 by ncontrem          #+#    #+#             */
/*   Updated: 2025/10/29 11:11:24 by ncontrem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_line(char *str)
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

static char	*str_clean(char *str)
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
	char		*buff;
	ssize_t		bytes;

	bytes = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	while (str == NULL || (!ft_strchr(str, '\n') && bytes > 0))
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes < 0)
			return (free(buff), NULL);
		buff[bytes] = '\0';
		str = ft_strjoin(str, buff);
		if (!str)
			return (free(buff), NULL);
	}
	str_line = get_line(str);
	str = str_clean(str);
	return (free(buff), str_line);
}

/* int main(void)
{
    char *str;
    int line = 0;

    while (line < 11)
    {
        str = get_next_line(0);
        if (!str)
            return (1);
        printf("%s", str);
        free(str);
        line++;
    }
    return (0);
} */