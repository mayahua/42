/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhua <mhua@student.42london.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-26 16:33:05 by mhua              #+#    #+#             */
/*   Updated: 2025-12-26 16:33:05 by mhua             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s && s[len])
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s != (char)c)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return ((char *)s);
}

char	*strjoin_free(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	i;
	size_t	j;
	char	*s;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	s = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[j])
		s[i++] = s1[j++];
	j = 0;
	while (s2 && s2[j])
		s[i++] = s2[j++];
	s[i] = '\0';
	free(s1);
	return (s);
}

char	*get_line(char *str)
{
	size_t	i;
	size_t	j;
	char	*line;

	i = 0;
	if (!str || str[i] == '\0')
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	j = 0;
	while (j < i)
	{
		line[j] = str[j];
		j++;
	}
	line[i] = '\0';
	return (line);
}

char	*remainder_update(char *str)
{
	size_t	i;
	size_t	j;
	char	*new_rem;

	i = 0;
	while (str && str[i] && str[i] != '\n')
		i++;
	if (!str || !str[i])
	{
		free (str);
		return (NULL);
	}
	i++;
	new_rem = malloc(sizeof(char) * (ft_strlen(str + i) + 1));
	if (!new_rem)
		return (NULL);
	j = 0;
	while (str[i])
		new_rem[j++] = str[i++];
	new_rem[j] = '\0';
	free(str);
	return (new_rem);
}
