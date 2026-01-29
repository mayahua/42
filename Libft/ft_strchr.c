/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhua <mhua@student.42london.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-11-20 16:37:38 by mhua              #+#    #+#             */
/*   Updated: 2025-11-20 16:37:38 by mhua             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Locates the first occurrence of a character in a string.
 *
 * @details
 * Scans the string `s` for the first occurrence of the character `c`.
 * The terminating null byte is considered part of the string, so
 * if `c` is `'\0'`, the function will return a pointer to the null-terminator.
 *
 * @param s The null-terminated string to search in.
 * @param c The character to locate (converted to `char` internally).
 * @return A pointer to the first occurrence of `c` in `s`,
 *         or NULL if the character is not found.
 */
char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return ((char *)s);
}

/*
//Alternative implementation
char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}
*/