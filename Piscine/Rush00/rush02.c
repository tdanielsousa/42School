/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdo-vale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 12:30:04 by mdo-vale          #+#    #+#             */
/*   Updated: 2024/09/07 13:33:54 by mdo-vale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c);

void	ft_print_line(int x, int e, int m, int d)
{
	int	i;

	i = 0;
	if (x >= 1)
		ft_putchar(e);
	while (i <= (x - 3))
	{
		ft_putchar(m);
		i++;
	}
	if (x >= 2)
		ft_putchar(d);
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	i;

	if (!(x > 0 && y > 0))
		write(1, "The parameters should be integers greater than 0\n", 49);
	i = 0;
	if (x >= 1 && y >= 1)
		ft_print_line(x, 'A', 'B', 'A');
	while (i <= y - 3 && x >= 1)
	{
		ft_print_line(x, 'B', ' ', 'B');
		i++;
	}
	if (y >= 2 && x >= 1)
		ft_print_line(x, 'C', 'B', 'C');
}
