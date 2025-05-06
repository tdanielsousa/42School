/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdaniel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 03:07:29 by tdaniel-          #+#    #+#             */
/*   Updated: 2025/05/05 16:01:56 by tdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// fixed list size to index with -1
// use bitwise to right shift 1000 100 10 0 =4
int	bits_required_for_max(t_elem *a)
{
	int	highest_index;
	int	bit_count;

	bit_count = 0;
	highest_index = list_size(a) - 1;
	while ((highest_index >> bit_count) != 0)
	{
		bit_count++;
	}
	return (bit_count);
}

//reset processed and size after possibly pushing into b
//sorts by bit 1, sorts by bit 2, .. etc until all is sorted
//index >> 0 & 1 checks the rightmost bit (right left - lsb)
//with  >> 1 & 1 shifts the bit to the right by one position
//so penultimate becomes the rightmost, etc
//push by bit, then each pass will sort higher nrs
void	radix_sort(t_elem **a, t_elem **b)
{
	int		bit_pos;
	int		stack_size;
	int		processed;

	bit_pos = 0;
	while (bit_pos < bits_required_for_max(*a))
	{
		processed = 0;
		stack_size = list_size(*a);
		while (processed < stack_size)
		{
			if ((((*a)->index >> bit_pos) & 1) == 0)
				pb(b, a);
			else
				ra(a);
			processed++;
		}
		while (*b != NULL)
			pa(a, b);
		bit_pos++;
	}
}
