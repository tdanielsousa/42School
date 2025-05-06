/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdaniel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 03:07:29 by tdaniel-          #+#    #+#             */
/*   Updated: 2025/05/05 12:57:42 by tdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//temp to save first node, make second node head of list
//last to find end of node, make last the first(currently in temp)
//fixed error: set to null to trminate list
/////////////////////////////////////////////////////////
//ra (rotate a): Shift up all elements of stack a by 1.
//The first element becomes the last one.
////////////////////////////////////////////////////////
void	ra(t_elem **a)
{
	t_elem	*temp_first_node;
	t_elem	*last_node_finder;

	if (*a == NULL || (*a)->next == NULL)
	{
		return ;
	}
	temp_first_node = *a;
	*a = (*a)->next;
	last_node_finder = *a;
	while (last_node_finder->next != NULL)
	{
		last_node_finder = last_node_finder->next;
	}
	last_node_finder->next = temp_first_node;
	temp_first_node->next = NULL;
	write(1, "ra\n", 3);
}

//in the end penultime becomes the last
//and last node becomes A which is the new first
/////////////////////////////////////////////////////////
//rra (reverse rotate a): Shift down all elements of stack a by 1.
//The last element becomes the first one
////////////////////////////////////////////////////////
void	rra(t_elem **a)
{
	t_elem	*last_node;
	t_elem	*penultimate_node;

	if (*a == NULL || (*a)->next == NULL)
	{
		return ;
	}
	penultimate_node = *a;
	while (penultimate_node->next && penultimate_node->next->next)
	{
		penultimate_node = penultimate_node->next;
	}
	last_node = penultimate_node->next;
	penultimate_node->next = NULL;
	last_node->next = *a;
	*a = last_node;
	write(1, "rra\n", 4);
}

//like ft_swap from piscine just trade the values w a temp
/////////////////////////////////////////////////////////
//sa (swap a): Swap the first 2 elements at the top of stack a.
//Do nothing if there is only one element or none
////////////////////////////////////////////////////////
void	sa(t_elem **a)
{
	t_elem	*temp;

	if (*a != NULL && (*a)->next != NULL)
	{
		temp = (*a)->next;
		(*a)->next = temp->next;
		temp->next = *a;
		*a = temp;
		write(1, "sa\n", 3);
	}
}
