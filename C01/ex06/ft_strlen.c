/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhua <mhua@student.42london.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-08 20:44:53 by mhua              #+#    #+#             */
/*   Updated: 2025-09-08 20:44:53 by mhua             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str != '\0')
	{
		i++;
		str++;
	}
	return (i);
}

int main(void)
{
    printf("Length of \"abcde\" = %d\n", ft_strlen("abcde"));
    printf("Length of \"42\" = %d\n", ft_strlen("42"));
    printf("Length of \"\" = %d\n", ft_strlen(""));
    
    return 0;
}
