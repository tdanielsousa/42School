/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdaniel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:51:30 by tdaniel-          #+#    #+#             */
/*   Updated: 2024/11/07 11:09:34 by tdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp_list;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp_list = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp_list;
	}
}

/*
**lst pointer to the head of the list
In the while save the next node location, delete the node, 
give adress of next node so loop can continue

Parameters
lst: The address of a pointer to a node.
del: The address of the function used to delete the content of the node.
Description
Deletes and frees the given node and every successor of that node,
using the function ’del’ and free(3).
Finally, the pointer to the list must be set to NULL.
*/