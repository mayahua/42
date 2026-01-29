/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhua <mhua@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 19:27:52 by mhua              #+#    #+#             */
/*   Updated: 2025/11/28 21:51:23 by mhua             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Extract a substring from a string.
 *
 * @details Allocates and returns a new string containing up to `len` characters
 * from the string `s`, starting at index `start`.
 *
 * @param s     The original string.
 * @param start The starting index of the substring.
 * @param len   Maximum number of characters to include.
 *
 * @return A newly allocated, null-terminated substring, 
 * or NULL if allocation fails or `s` is NULL. If `start` is beyond
 * the end of `s`, an empty string is returned.
 *
 * @note The returned string must be freed by the caller.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_calloc(1, 1));
	if (len > s_len - start)
		len = s_len - start;
	substr = (char *)ft_calloc(len + 1, sizeof(char));
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, s + start, len + 1);
	return (substr);
}
