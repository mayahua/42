/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhua <mhua@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 19:11:15 by mhua              #+#    #+#             */
/*   Updated: 2025/12/05 19:50:37 by mhua             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Allocates memory for an array of `count` elements of `size` bytes each
 *  and initializes all bytes to zero.
 * 
 * @return A pointer to the newly allocated zero-initialized memory.
 *         NULL if the allocation fails or if the requested size
 *         overflows SIZE_MAX.
 * 
 * @note (size_t)(-1) == SIZE_MAX
 */
void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	if (size != 0 && count > (size_t)(-1) / size)
		return (NULL);
	p = malloc(count * size);
	if (!p)
		return (NULL);
	ft_bzero(p, count * size);
	return (p);
}
