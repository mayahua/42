/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhua <mhua@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 19:53:01 by mhua              #+#    #+#             */
/*   Updated: 2025/12/05 20:06:38 by mhua             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Adds the node `new` at the beginning of the list `lst`.
 *
 * This function inserts the node `new` as the first element of the list
 * referenced by `lst`. The current first node (if any) becomes the second
 * node, because `new->next` is set to point to the former head. Finally,
 * the list head (`*lst`) is updated to point to `new`.
 */
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
