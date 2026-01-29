/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhua <mhua@student.42london.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-11-24 20:38:16 by mhua              #+#    #+#             */
/*   Updated: 2025-11-24 20:38:16 by mhua             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Copy memory area handling overlapping regions.
 *
 * @details `n` bytes from memory area `src` to memory area `dest`.
 * If `dest` is at a lower address than `src`, the copy is done forward.
 * If `dest` is at a higher address than `src`, the copy is done backward.
 *
 * @param dest Destination memory area.
 * @param src  Source memory area.
 * @param n    Number of bytes to copy.
 *
 * @return The pointer `dest`, or NULL if both `dest` and `src` are NULL.
 */
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	if (!dest && !src)
		return (NULL);
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (d < s)
		ft_memcpy(dest, src, n);
	else
	{
		i = n;
		while (i > 0)
		{
			i--;
			d[i] = s[i];
		}
	}
	return (dest);
}
