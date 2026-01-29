/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhua <mhua@student.42london.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-01 19:58:18 by mhua              #+#    #+#             */
/*   Updated: 2025-12-01 19:58:18 by mhua             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Returns the number of nodes in a singly linked list.
 *
 * @details function traverses a linked list starting from the node referenced
 * by `lst`. For every valid node encountered, it increments an internal
 * counter. The traversal continues by following the `next` pointer until
 * it reaches a NULL pointer, which marks the end of the list. Returns 0 if `lst`
 * is NULL.
 *
 * @param lst A pointer to the first element of the linked list.
 *
 * @note
 * This function assumes that each node of the list is of type `t_list`
 * and that the list is properly terminated with `next == NULL`.
 */
int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}
