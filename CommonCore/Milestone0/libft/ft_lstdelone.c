/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdaniel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:51:30 by tdaniel-          #+#    #+#             */
/*   Updated: 2024/11/07 11:04:32 by tdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
/*
use function del to delete the content inside the node 
and then free the node

Parameters
lst: The node to free.
del: The address of the function used to delete the content.
Description
Takes as a parameter a node and frees the memory of the node’s content using 
the function ’del’ given as a parameter and free the node. 
The memory of ’next’ must not be freed.
*/