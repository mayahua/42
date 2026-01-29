/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhua <mhua@student.42london.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-11-30 19:34:06 by mhua              #+#    #+#             */
/*   Updated: 2025-11-30 19:34:06 by mhua             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Iterates over a string `s` and applies a function `f` to 
 * each character of the string.
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
