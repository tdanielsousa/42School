/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdaniel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 03:07:29 by tdaniel-          #+#    #+#             */
/*   Updated: 2025/05/05 09:25:48 by tdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//temp saves the secnd node in a to be new head of list
//top of a is moved to the top of b by gving adress
void	pb(t_elem **b, t_elem **a)
{
	t_elem	*temp;

	if (*a == NULL)
		return ;
	temp = (*a)->next;
	(*a)->next = *b;
	*b = *a;
	*a = temp;
	write(1, "pb\n", 3);
}

//temp saves the secnd node in b to be new head of list
//top of b is moved to the top of a by gving adress
void	pa(t_elem **a, t_elem **b)
{
	t_elem	*temp;

	if (*b == NULL)
		return ;
	temp = (*b)->next;
	(*b)->next = *a;
	*a = *b;
	*b = temp;
	write(1, "pa\n", 3);
}
