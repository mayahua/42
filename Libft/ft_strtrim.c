/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhua <mhua@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 15:35:40 by mhua              #+#    #+#             */
/*   Updated: 2025/11/29 16:01:11 by mhua             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Removes all characters found in `set` from both the start and the end
 * of the string `s1`.
 *
 * @param s1  The original string to be trimmed.
 * @param set The set of characters to remove from the start and end of `s1`.
 *
 * @return A newly allocated trimmed string, or NULL if memory allocation fails 
 * or if invalid parameters are provided.
 *
 * @note The returned string must be freed by the caller.
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	return (ft_substr(s1, start, end - start));
}
