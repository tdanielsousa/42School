/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdaniel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 03:07:29 by tdaniel-          #+#    #+#             */
/*   Updated: 2025/05/05 12:57:38 by tdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sorted(t_elem **a)
{
	t_elem	*temp;

	temp = *a;
	while (temp->next)
	{
		if (temp->num > temp->next->num)
			return (false);
		temp = temp->next;
	}
	return (true);
}

//t_elem **a    is a pointer to the list
//t_elem *a     is a pointer to the node
int	list_size(t_elem *a)
{
	int	size;

	size = 0;
	while (a != NULL)
	{
		size++;
		a = a->next;
	}
	return (size);
}

int	find_min(t_elem *a)
{
	int	min;

	if (a == NULL)
		return (0);
	min = a->num;
	while (a != NULL)
	{
		if (a->num < min)
		{
			min = a->num;
		}
		a = a->next;
	}
	return (min);
}

//used to send 1 or 2 smallest first in sort 4 or 5
//check if min node is in first half or second half of stack send to top
void	move_to_top(t_elem **a, int min)
{
	int	position;
	int	size;

	position = get_min_position(*a, min);
	size = list_size(*a);
	if (position <= size / 2)
	{
		while ((*a)->num != min)
		{
			ra(a);
		}
	}
	else
	{
		while ((*a)->num != min)
		{
			rra(a);
		}
	}
}

// traverse stack find index of min node, -1 for error
int	get_min_position(t_elem *a, int min)
{
	int	position;

	position = 0;
	while (a != NULL)
	{
		if (a->num == min)
			return (position);
		position++;
		a = a->next;
	}
	return (-1);
}
