/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncontrem <ncontrem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 08:56:44 by ncontrem          #+#    #+#             */
/*   Updated: 2025/10/29 10:05:55 by ncontrem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	index;

	if (!str)
		return (0);
	index = 0;
	while (str[index])
		index++;
	return (index);
}

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	index;

	index = 0;
	str = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!str)
		return (NULL);
	while (s[index])
	{
		str[index] = s[index];
		index ++;
	}
	str[index] = '\0';
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*final_string;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	final_string = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!final_string)
		return (free(s1), NULL);
	while (s1[i])
	{
		final_string[i] = s1[i];
		i++;
	}
	while (s2[j])
		final_string[i++] = s2[j++];
	final_string[i] = '\0';
	return (free(s1), final_string);
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
