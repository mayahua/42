/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhua <mhua@student.42london.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-11-24 19:43:04 by mhua              #+#    #+#             */
/*   Updated: 2025-11-24 19:43:04 by mhua             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Copy `n` bytes from `src` to `dest`.
 *
 * @details `n` bytes from the memory area `src` to the memory area `dest`.
 * The function casts the void pointers to `unsigned char *` to safely copy
 * one byte at a time, avoiding illegal dereferencing of `void *`.
 * 
 * @param dest The address of the destination block
 * @param src The address of the source block
 * @param n The number of bytes to copy
 */
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	if (!dest && !src)
		return (NULL);
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
