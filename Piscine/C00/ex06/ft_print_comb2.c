/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdaniel- <tdaniel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 12:46:31 by tdaniel-          #+#    #+#             */
/*   Updated: 2024/09/09 16:34:45 by tdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb2(void)
{
	int		first;
	int		second;
	char	temporary;

	first = 0;
	while (first <= 98)
	{
		second = first + 1;
		while (second <= 99)
		{
			temporary = first / 10 + '0';
			write(1, &temporary, 1);
			temporary = first % 10 + '0';
			write(1, &temporary, 1);
			write(1, " ", 1);
			temporary = second / 10 + '0';
			write(1, &temporary, 1);
			temporary = second % 10 + '0';
			write(1, &temporary, 1);
			if (first < 98)
				write(1, ", ", 2);
			second++;
		}
		first++;
	}
}
