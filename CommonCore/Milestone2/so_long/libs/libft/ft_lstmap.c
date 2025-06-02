/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdaniel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:51:30 by tdaniel-          #+#    #+#             */
/*   Updated: 2024/11/07 11:32:32 by tdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*temp_list;
	void	*set;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		set = f(lst->content);
		temp_list = ft_lstnew(set);
		if (temp_list == NULL)
		{
			del(set);
			ft_lstclear(&new_list, (*del));
			return (new_list);
		}
		ft_lstadd_back(&new_list, temp_list);
		lst = lst->next;
	}
	return (new_list);
}

/*
To not change anything in the original list im creating a temporary one,
applying f there and then copying into the new 
iterates each node in the list applies function f to the content
creates a new list, and returns it.

ft_lstadd_back - Adds the node at the end of the list
ft_lstclear - Deletes and frees the given node and every successor of that node
ft_lstnew - Creates a new node

void *(*f)(void *) almost like previous but returns void pointer
void function call that has void as a parameter

Parameters
lst: The address of a pointer to a node.
f: The address of the function used to iterate on the list.
del: The address of the function used to delete 
the content of a node if needed.
Return value
The new list.
NULL if the allocation fails.
Description 
Iterates the list ’lst’ and applies the function ’f’ on the content
of each node. 
Creates a new list resulting of the successive applications of the
function ’f’. 
The ’del’ function is used to delete the content of a node if needed.
*/