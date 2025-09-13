/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhua <mhua@student.42london.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-08 20:25:04 by mhua              #+#    #+#             */
/*   Updated: 2025-09-08 20:25:04 by mhua             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int main(void)
{
    int x = 5;
    int y = 10;

    printf("Before: x = %d, y = %d\n", x, y);
    ft_swap(&x, &y);
    printf("After: x = %d, y = %d\n", x, y);

    return 0;
}
