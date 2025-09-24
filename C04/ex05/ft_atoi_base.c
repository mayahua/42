/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhua <mhua@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-18 15:01:55 by mhua              #+#    #+#             */
/*   Updated: 2025-09-18 15:01:55 by mhua             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

int	ft_sign(char *str, int *i)
{
	int	s;

	s = 1;
	while (str[*i] == ' ' || (str[*i] >= 9 && str[*i] <= 13))
		(*i)++;
	while (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			s = -s;
		(*i)++;
	}
	return (s);
}

int	ft_isnbr(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	base_len;
	int	i;
	int	s;
	int	r;	
	int	n;

	if (!str || !base || !ft_isbase(base))
		return (0);
	base_len = ft_strlen(base);
	i = 0;
	s = ft_sign(str, &i);
	r = 0;
	n = ft_isnbr(str[i], base);
	while (n != -1)
	{
		r = r * base_len + n;
		i++;
		n = ft_isnbr(str[i], base);
	}
	return (s * r);
}

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
	if (argc > 1)
		ft_putnbr(ft_atoi_base(argv[1], argv[2]));
	return (0);
}
