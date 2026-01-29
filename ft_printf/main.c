/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhua <mhua@student.42london.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-22 19:32:39 by mhua              #+#    #+#             */
/*   Updated: 2025-12-22 19:32:39 by mhua             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	int	ret_ft;
	int	ret_real;

	printf("===== BASIC TEST =====\n");
	ret_ft = ft_printf("ft_printf : Hello %s!\n", "world");
	ret_real = printf("printf    : Hello %s!\n", "world");
	printf("Return ft = %d | real = %d\n\n", ret_ft, ret_real);

	printf("===== CHAR & STRING =====\n");
	ret_ft = ft_printf("Char: %c | String: %s\n", 'A', "42");
	ret_real = printf("Char: %c | String: %s\n", 'A', "42");
	printf("Return ft = %d | real = %d\n\n", ret_ft, ret_real);

	printf("===== INT & UNSIGNED =====\n");
	ret_ft = ft_printf("Int: %d | Unsigned: %u\n", -42, 42);
	ret_real = printf("Int: %d | Unsigned: %u\n", -42, 42);
	printf("Return ft = %d | real = %d\n\n", ret_ft, ret_real);

	printf("===== HEX =====\n");
	ret_ft = ft_printf("Hex lower: %x | Hex upper: %X\n", 255, 255);
	ret_real = printf("Hex lower: %x | Hex upper: %X\n", 255, 255);
	printf("Return ft = %d | real = %d\n\n", ret_ft, ret_real);

	printf("===== POINTER =====\n");
	ret_ft = ft_printf("Pointer: %p\n", (void *)&ret_ft);
	ret_real = printf("Pointer: %p\n", (void *)&ret_ft);
	printf("Return ft = %d | real = %d\n\n", ret_ft, ret_real);

	printf("===== PERCENT =====\n");
	ret_ft = ft_printf("100%% success\n");
	ret_real = printf("100%% success\n");
	printf("Return ft = %d | real = %d\n\n", ret_ft, ret_real);

	printf("===== EDGE CASES =====\n");
	ret_ft = ft_printf("NULL string: %s\n", (char *)NULL);
	ret_real = printf("NULL string: %s\n", (char *)NULL);
	printf("Return ft = %d | real = %d\n\n", ret_ft, ret_real);

	printf("===== EDGE CASES 2 =====\n");
	ret_ft = ft_printf("nil string: %p\n", (void *)NULL);
	ret_real = printf("nil string: %p\n", (void *)NULL);
	printf("Return ft = %d | real = %d\n\n", ret_ft, ret_real);
	return (0);
}
