/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdaniel- <tdaniel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 12:46:31 by tdaniel-          #+#    #+#             */
/*   Updated: 2024/09/09 16:31:07 by tdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int min, int max)
{
	int	size;
	int	*range;
	int	i;

	if (min >= max)
	{
		return (NULL);
	}
	size = max - min;
	range = (int *)malloc(size * sizeof(int));
	if (range == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (i < size)
	{
		range[i] = min + i;
		i++;
	}
	return (range);
}
/*
int main() {
    int min = 5;
    int max = 10;
    int *range = ft_range(min, max);

    if (range != NULL) {
        int i = 0;
        while (i < max - min) {
            printf("%d ", range[i]);
            i++;
        }
        printf("\n");
        free(range);
    } else {
        printf("NULL pointer returned\n");
    }

    return 0;
}
*/
