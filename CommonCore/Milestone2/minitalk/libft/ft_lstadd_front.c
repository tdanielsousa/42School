/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdaniel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:51:30 by tdaniel-          #+#    #+#             */
/*   Updated: 2024/11/07 10:34:20 by tdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst == NULL && new == NULL)
		return ;
	new->next = *lst;
	*lst = new;
}
/*
** pointer to a pointer to the head of the list
new->next = *lst; sends the one in current 1 position to pos2
*lst = new; and this gives value to the new pos1
If there's a node already it pushes it down the list

May be useful to manipulate something that requires non contiguous memory

Parameters 
lst: The address of a pointer to the first link of a list.
new: The address of a pointer to the node to be added to the list.

Description
Adds the node ’new’ at the beginning of the list.
*/