/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhua <mhua@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 19:02:53 by mhua              #+#    #+#             */
/*   Updated: 2025/12/05 20:13:15 by mhua             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	numlen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

/**
 * @brief Converts an integer to a newly allocated string.
 *
 * @details
 * Handles negative numbers, zero, and integer limits by working with a long
 * copy of the input value. The function calculates the required length,
 * allocates memory, and fills the string from the end by extracting digits.
 *
 * @param n The integer to convert.
 * @return A null-terminated string representing the number,
 *         or NULL if memory allocation fails.
 */
char	*ft_itoa(int n)
{
	char	*str;
	long	num;
	int		len;

	num = n;
	len = numlen(n);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (num < 0)
		num = -num;
	if (n == 0)
		str[0] = '0';
	while (num > 0)
	{
		str[--len] = (num % 10) + '0';
		num /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
