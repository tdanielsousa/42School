/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdaniel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 03:07:29 by tdaniel-          #+#    #+#             */
/*   Updated: 2025/05/05 09:11:57 by tdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	choose_sorting(t_elem **a, t_elem **b)
{
	if (list_size(*a) == 2)
		sa(a);
	else if (list_size(*a) == 3)
		sort_three(a);
	else if (list_size(*a) == 4)
		sort_four(a, b);
	else if (list_size(*a) == 5)
		sort_five(a, b);
	else
		radix_sort(a, b);
}

// if first is the smallest, swap it with second and rotate
// if first is in the middle, just swap it with second
// if first is the largest, reverse rotate it to the bottom
// if first is the largest and second is smaller than third
void	sort_three_comparisons(t_elem **a, int first, int second, int third)
{
	if (first < second && first < third)
	{
		sa(a);
		ra(a);
	}
	else if (first > second && first < third)
		sa(a);
	else if (first < second && first > third)
		rra(a);
	else if (first > second && first > third)
	{
		if (second < third)
			ra(a);
		else
		{
			sa(a);
			rra(a);
		}
	}
}

void	sort_three(t_elem **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->index;
	second = (*a)->next->index;
	third = (*a)->next->next->index;
	sort_three_comparisons(a, first, second, third);
}

// find min, move to top, sort the rest with sort3
void	sort_four(t_elem **a, t_elem **b)
{
	int	min;

	min = find_min(*a);
	move_to_top(a, min);
	pb(b, a);
	if (is_sorted(a) == true)
	{
		pa(a, b);
	}
	else
	{
		sort_three(a);
		pa(a, b);
	}
}

// find min x2, move to top x2, sort the rest with sort3
void	sort_five(t_elem **a, t_elem **b)
{
	int	i;
	int	min;

	i = 0;
	while (i < 2)
	{
		min = find_min(*a);
		move_to_top(a, min);
		pb(b, a);
		i++;
	}
	if (is_sorted(a) == true)
	{
		pa(a, b);
		pa(a, b);
	}
	else
	{
		sort_three(a);
		pa(a, b);
		pa(a, b);
	}
}
