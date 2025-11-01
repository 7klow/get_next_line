/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontrem <ncontrem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 11:03:04 by ncontrem          #+#    #+#             */
/*   Updated: 2025/11/01 11:06:01 by ncontrem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char	*str[MAX_FD];
	char		*str_line;
	char		*buff;
	ssize_t		bytes;

	bytes = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	while (str[fd] == NULL || (!ft_strchr(str[fd], '\n') && bytes > 0))
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes < 0)
			return (free(buff), free(str[fd]), str[fd] = NULL, NULL);
		buff[bytes] = '\0';
		str[fd] = ft_strjoin(str[fd], buff);
		if (!str[fd])
			return (free(buff), free(str[fd]), str[fd] = NULL, NULL);
	}
	str_line = get_line(str[fd]);
	str[fd] = str_clean(str[fd]);
	return (free(buff), str_line);
}