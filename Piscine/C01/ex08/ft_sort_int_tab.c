/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdaniel- <tdaniel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 12:46:31 by tdaniel-          #+#    #+#             */
/*   Updated: 2024/09/09 16:37:06 by tdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	sorted;

	if (size < 2)
	{
		return ;
	}
	sorted = 0;
	while (sorted == 0)
	{
		sorted = 1;
		i = 0;
		while (i < size - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				swap(&tab[i], &tab[i + 1]);
				sorted = 0;
			}
			i++;
		}
		size--;
	}
}

/*
// if checks if needs sorting otherwise exits
//set it to zero will run once if no swap occurs through all elements
// testing prnt array
void print_array(int *tab, int size) {
    int i = 0;
    while (i < size) {
        printf("%d ", tab[i]);
        i++;
    }
    printf("\n");
}

//bubble sort by repeatly comparing and swapping adjacent elements in an array
//if they are out of order iss repeated until no more swaps are needed

int main() {
    int array[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(array) / sizeof(array[0]);
// N of elements in the array bytes total/bytes of each one

    printf("before:\n");
    print_array(array, size); // Print before sorting

    ft_sort_int_tab(array, size); // to sort

    printf("after:\n");
    print_array(array, size); // print afteer

    return 0;
}
*/
