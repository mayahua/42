/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhua <mhua@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-09-25 15:29:34 by mhua              #+#    #+#             */
/*   Updated: 2025-09-25 15:29:34 by mhua             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest + i);
}

char	*malloc_empty(void)
{
	char	*str;

	str = (char *)malloc(1);
	if (str)
		str[0] = '\0';
	return (str);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	char	*strcp;	
	int		str_len;
	int		i;

	if (size == 0)
		return (malloc_empty());
	str_len = (size - 1) * ft_strlen(sep);
	i = 0;
	while (i < size)
		str_len += ft_strlen(strs[i++]);
	str = (char *)malloc(str_len + 1);
	if (!str)
		return (0);
	i = 0;
	strcp = str;
	while (i < size)
	{
		strcp = ft_strcpy(strcp, strs[i++]);
		if (i < size)
			strcp = ft_strcpy(strcp, sep);
	}
	return (str);
}

/*
int main(int argc, char **argv)
{
    char *result;
    char *sep = ",";

	if (argc > 1)
	{
		result = ft_strjoin(argc - 1, argv + 1, sep);
		if (result)
		{
			printf("%s\n", result);
			free(result);
		}
	}
    return (0);
}
//*/