/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontrem <ncontrem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 19:50:38 by ncontrem          #+#    #+#             */
/*   Updated: 2025/10/22 20:17:46 by ncontrem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_last_line(char *str)
{
	char	*line;
	int		len;
	int		index;

	index = 0;
	len = ft_strlen(str);
	while (str[len] != '\n' && len != 0)
		len--;
	len++;
	line = malloc((ft_strlen(str) - len) + 1);
	if (!line)
		return (NULL);
	while (str[len++])
	{
		line[index] = str[len];
		index++;
	}
	line[index] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*current_line;
	char		buff[BUFFER_SIZE + 1];
	int			result;

	while (!ft_strchr(buff, '\n'))
	{
		result = read(fd, buff, BUFFER_SIZE);
		if (result == -1)
			return (NULL);
		buff[BUFFER_SIZE] = '\0';
		str = ft_strjoin(str, buff);
		if (!str)
			return (NULL);
	}
	current_line = get_last_line(str);
	return (current_line);
}

int	main(void)
{
	char	*str;
	int		line;

	line = 0;
	while (line < 4)
	{
		str = get_next_line(0);
		printf("%s", str);
		line++;
	}
	return (0);
}