/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhua <mhua@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-17 14:24:59 by mhua              #+#    #+#             */
/*   Updated: 2025-09-17 14:24:59 by mhua             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}

int	ft_isbase(char *base)
{
	int				base_len;
	int				i;
	int				j;

	base_len = ft_strlen(base);
	if (base_len < 2)
		return (0);
	i = 0;
	while (i < base_len)
	{
		if (base[i] == '+' || base[i] == '-' || base[i] <= 32 || base[i] > 126)
			return (0);
		j = i + 1;
		while (j < base_len)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int				base_len;
	unsigned int	n;

	base_len = ft_strlen(base);
	if (!ft_isbase(base))
		return ;
	if (nbr < 0)
	{
		ft_putchar('-');
		n = (unsigned int)(-(long)nbr);
	}
	else
		n = (unsigned int)nbr;
	if (n >= (unsigned int)base_len)
		ft_putnbr_base(n / base_len, base);
	ft_putchar(base[n % base_len]);
}

int	main(int argc, char **argv)
{
	if (argc > 2)
		ft_putnbr_base(atoi(argv[1]), argv[2]);
	return (0);
}
