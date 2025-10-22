/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontrem <ncontrem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 19:50:42 by ncontrem          #+#    #+#             */
/*   Updated: 2025/10/22 19:48:03 by ncontrem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		index;
	int		j;
	char	*final_string;

	index = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	final_string = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!final_string)
		return (NULL);
	while (s1[index++])
		final_string[index] = s1[index];
	while (s2[j++])
		final_string[j + index] = s2[j];
	final_string[j + index] = '\0';
	free(s1);
	return (final_string);
}

char	*ft_strchr(const char *s, int c)
{
	int	index;

	index = 0;
	while (s[index])
	{
		if (s[index] == (char)c)
			return ((char *)&s[index]);
		index++;
	}
	if ((char)c == '\0')
		return ((char *)&s[index]);
	return (NULL);
}