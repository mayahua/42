/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhua <mhua@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-09 19:48:15 by mhua              #+#    #+#             */
/*   Updated: 2025-09-09 19:48:15 by mhua             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	int i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
}

int main(int argc, char **argv)
{
	if (argc > 1)
	{
		char	dest[100];

		ft_putstr(ft_strncpy(dest, argv[1], (unsigned int)atoi(argv[2])));
		ft_putchar('\n');
	}
	return (0);
}
