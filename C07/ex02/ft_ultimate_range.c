/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhua <mhua@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-25 14:59:42 by mhua              #+#    #+#             */
/*   Updated: 2025-09-25 14:59:42 by mhua             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*arr;
	int	i;
	int	size;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	size = max - min;
	arr = (int *)malloc(sizeof(int) * size);
	if (!arr)
		return (-1);
	i = 0;
	while (i < size)
	{
		arr[i] = min + i;
		i++;
	}
	*range = arr;
	return (size);
}

/*
void	ft_putnbr(int nb)
{
	char	c;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		nb = -nb;
		write(1, "-", 1);
	}
	if (nb >= 10)
		ft_putnbr(nb / 10);
	c = nb % 10 + '0';
	write(1, &c, 1);
}

int	main(int argc, char **argv)
{
	int	*cp;
	int	size;
	int	i;

	if (argc == 3)
	{
		size = ft_ultimate_range(&cp, atoi(argv[1]), atoi(argv[2]));
		write(1, "size = ", 7);
		ft_putnbr(size);
		write(1, "\n", 1);

		if (size > 0)
		{
			i = 0;
			while (i < size)
			{
				ft_putnbr(cp[i]);
				write(1, " ", 1);
				i++;
			}
			write(1, "\n", 1);
			free(cp);
		}
	}
	return (0);
}
//*/