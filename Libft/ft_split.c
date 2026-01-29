/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhua <mhua@student.42london.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-11-30 17:17:14 by mhua              #+#    #+#             */
/*   Updated: 2025-11-30 17:17:14 by mhua             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Counts the number of substrings in a string separated by a delimiter.
 */
static int	count(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

/**
 * @brief Allocates and returns a substring from a string.
 * 
 * @param start The starting index of the substring (inclusive).
 * @param end The ending index of the substring (exclusive).
 */
static char	*copy(const char *s, int start, int end)
{
	char	*substr;
	int		i;

	substr = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!substr)
		return (NULL);
	i = 0;
	while (start < end)
		substr[i++] = s[start++];
	substr[i] = '\0';
	return (substr);
}

/**
 * @brief Frees all strings in a NULL-terminated array and the array itself.
 *
 * @details
 * Iterates through each element of the array, frees it, and then frees
 * the array pointer itself. Designed to be used when a partial allocation
 * fails to prevent memory leaks.
 */
static void	free_all(char **result)
{
	int	i;

	i = 0;
	while (result[i])
		free(result[i++]);
	free(result);
}

/**
 * @brief Fills the result array with substrings split by a delimiter.
 *
 * @param result The pre-allocated array of string pointers to store substrings.
 */
static int	newstr(char **result, const char *s, char c)
{
	int	i;
	int	j;
	int	start;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			start = i;
			while (s[i] && s[i] != c)
				i++;
			result[j] = copy(s, start, i);
			if (!result[j])
				return (0);
			j++;
		}
		else
			i++;
	}
	result[j] = NULL;
	return (1);
}

/**
 * @brief Splits a string into an array of substrings using a delimiter.
 *
 * @details
 * Allocates memory for an array of strings. Each element contains a substring
 * from the original string `s` separated by the character `c`. The array is
 * terminated with a NULL pointer. Uses helper functions internally.
 *
 * @param s The input string to split.
 * @param c The delimiter character.
 * @return A heap-allocated array of null-terminated strings, or NULL on failure.
 */
char	**ft_split(char const *s, char c)
{
	char	**result;

	if (!s)
		return (NULL);
	result = (char **)malloc(sizeof(char *) * (count(s, c) + 1));
	if (!result)
		return (NULL);
	if (!newstr(result, s, c))
	{
		free_all(result);
		return (NULL);
	}
	return (result);
}
