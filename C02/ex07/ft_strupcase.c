/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhua <mhua@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-11 12:22:07 by mhua              #+#    #+#             */
/*   Updated: 2025-09-11 12:22:07 by mhua             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] = str[i] - 32;
		}
		i++;
	}
	return (str);
}

void	ft_putchar(char c) 
{ 
	write(1, &c, 1); 
}

void	ft_putstr(char *s)
{ 
	while (*s) 
		write(1, s++, 1); 
}

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		ft_putstr(ft_strupcase(argv[1]));
		ft_putchar('\n');
	}
	return (0);
}
