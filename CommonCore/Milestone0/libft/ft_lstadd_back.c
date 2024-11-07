/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdaniel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:51:30 by tdaniel-          #+#    #+#             */
/*   Updated: 2024/11/07 10:54:09 by tdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp_list;

	if (new == NULL)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	temp_list = ft_lstlast(*lst);
	temp_list->next = new;
}
/*
check if list is empty to make the new node the head if is empty
use ft_lstlast to get last node in list
the last node is the one that currently has a next pointer set to null
if the node is the last one in the list next is set to null

Parameters 
lst: The address of a pointer to the first link of a list.
new: The address of a pointer to the node to be added to the list.
Description
Adds the node ’new’ at the end of the list.
*/