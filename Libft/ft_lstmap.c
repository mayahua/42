/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhua <mhua@student.42london.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 15:21:55 by mhua              #+#    #+#             */
/*   Updated: 2025/12/05 20:17:44 by mhua             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief Iterates through the list `lst` and applies the function `f` 
 * to the content of each node.
 * Creates a new list resulting from the successive applications of `f`.
 * The `del` function is used to delete the content of a node if needed.
 * @param lst Pointer to the first node of the list.
 * @param f Function pointer to apply to the content of each node.
 * @param del Function pointer used to delete the content of a node if needed.
 * @return Pointer to first node of new list, or NULL if allocation fails.
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*newnd;

	if (!lst || !f || !del)
		return (NULL);
	newlst = NULL;
	while (lst)
	{
		newnd = ft_lstnew(f(lst->content));
		if (!newnd)
		{
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		ft_lstadd_back(&newlst, newnd);
		lst = lst->next;
	}
	return (newlst);
}
