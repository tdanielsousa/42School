/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdaniel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:51:30 by tdaniel-          #+#    #+#             */
/*   Updated: 2024/11/07 11:33:07 by tdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*temp_list;

	temp_list = lst;
	if (!lst)
		return (NULL);
	while (temp_list->next)
		temp_list = temp_list->next;
	return (temp_list);
}

/*
example it gets adress of 1 which in the list has the adress of 2 
to "increment the while"
returns the last node

Parameters
lst: The beginning of the list.
Return value 
Last node of the list
Description
Returns the last node of the list.
*/
