/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhua <mhua@student.42london.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-01 18:51:04 by mhua              #+#    #+#             */
/*   Updated: 2025-12-01 18:51:04 by mhua             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Creates a new linked list node.
 *
 * @details
 * Allocates (with malloc) and returns a new node. The node's content is set
 * to the value of the parameter `content`. 
 * The next pointer is initialized to NULL.
 *
 * @param content A pointer to the data to store in the new node.
 * @return A pointer to newly created node, or NULL if memory allocation fails.
 */
t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}
