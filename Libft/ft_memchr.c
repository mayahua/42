/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhua <mhua@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 18:09:44 by mhua              #+#    #+#             */
/*   Updated: 2025/11/25 18:59:51 by mhua             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Locate a byte in a memory block.
 *
 * Scans the first `n` bytes of `s` for the byte `c` (as `unsigned char`).
 *
 * @param s The memory area to search.
 * @param c The byte value to find.
 * @param n Number of bytes to examine.
 *
 * @return Pointer to the first occurrence of `c`, or NULL if not found.
 */
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*p;
	unsigned char		ch;

	p = (const unsigned char *)s;
	ch = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (p[i] == ch)
			return ((void *)(p + i));
		i++;
	}
	return (NULL);
}
