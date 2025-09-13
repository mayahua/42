/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhua <mhua@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-11 12:38:13 by mhua              #+#    #+#             */
/*   Updated: 2025-09-11 12:38:13 by mhua             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	fst_ltr;

	i = 0;
	fst_ltr = 1;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		if (fst_ltr == 1 && str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] -= 32;
			fst_ltr = 0;
		}
		else if ((str[i] >= 'a' && str[i] <= 'z')
			|| (str[i] >= 'A' && str[i] <= 'Z')
			|| (str[i] >= '0' && str[i] <= '9'))
			fst_ltr = 0;
		else
			fst_ltr = 1;
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
	int i = 0;
	while (s[i] != '\0')
	{
		ft_putchar(s[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc > 1)
		ft_putstr(ft_strcapitalize(argv[1]));
	ft_putchar('\n');
	return (0);
}
