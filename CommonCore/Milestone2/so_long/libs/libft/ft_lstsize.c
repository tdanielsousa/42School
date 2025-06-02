/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdaniel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:51:30 by tdaniel-          #+#    #+#             */
/*   Updated: 2024/11/07 10:44:30 by tdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*temp_list;

	temp_list = lst;
	i = 0;
	while (temp_list)
	{
		temp_list = temp_list->next;
		i++;
	}
	return (i);
}

/*
with each iterarion, temp lists gets updated to point to next node
temp_list->next is a pointer
example it gets adress of 1 which in the list has the adress of 2 
to "increment the while"
Parameters
lst: The beginning of the list.
Return value
The length of the list
Description
Counts the number of nodes in a list.
*/
