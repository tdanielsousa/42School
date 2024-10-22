/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdaniel- <tdaniel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 12:46:31 by tdaniel-          #+#    #+#             */
/*   Updated: 2024/09/08 12:46:31 by tdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/*
#include <stdio.h>

int main() {
	int x = 5;
	int y = 10;

	printf("original:\n");
	printf("x = %d\n", x);
	printf("y = %d\n", y);

	// swap values
	ft_swap(&x, &y);

	printf("after:\n");
	printf("x = %d\n", x);
	printf("y = %d\n", y);

	return 0;
}

*/
