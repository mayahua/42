/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhua <mhua@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 20:39:21 by mhua              #+#    #+#             */
/*   Updated: 2025/11/29 14:58:25 by mhua             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Duplicates a string by allocating memory on the heap.
 *
 * @details
 * Allocates enough memory to store a copy of the string `s` (including the
 * null-terminator) and copies each character from `s` into the new memory.
 * The caller is responsible for freeing the returned string when done.
 *
 * @return A pointer to a newly allocated null-terminated string containing
 *         the same content as `s`, or NULL if memory allocation fails.
 */
char	*ft_strdup(const char *s)
{
	int		i;
	int		len;
	char	*dup;

	len = ft_strlen(s);
	dup = malloc(len + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

/*
int	main(int argc, char **argv)
{
	char	*cp;
	int		i;

	if (argc == 2)
	{
		cp = ft_strdup(argv[1]);
		if (cp)
		{
			i = 0;
			while (cp[i])
			{
				write(1, &cp[i], 1);
				i++;
			}
			free(cp);
		}
	}
	return (0);
}
//*/