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

void	ft_rev_int_tab(int *tab, int size)
{
	int	temp_swap;
	int	start;
	int	end;

	start = 0;
	end = size - 1;
	while (start < end)
	{
		temp_swap = tab[start];
		tab[start] = tab[end];
		tab[end] = temp_swap;
		start++;
		end--;
	}
}

/*
#include <stdio.h>

//array values start at 0, ex: size is 3 = 0, 1, 2.  so to be valid size-1

void print_array(int *tab, int size) {
    int i = 0;
    while (i < size) {
        printf("%d ", tab[i]);
        i++;
    }
    printf("\n");
}

int main() {
	int array[] = {1, 2, 3, 4, 5};
	int size = sizeof(array) / sizeof(array[0]);
//directly make the division into size to avoid creating 2 extra vars to do it. 
//gives the total size of the array dividing for individual
//Also sizeof can only be used in arrays defined at compile time. “hard coded”
    
	printf("orignal:\n");
	print_array(array, size);
    
	ft_rev_int_tab(array, size);  //reversing to print it after
    
	printf("inverted:\n");
	print_array(array, size);
    
	return 0;
}
*/
