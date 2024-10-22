/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdaniel- <tdaniel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:46:31 by tdaniel-          #+#    #+#             */
/*   Updated: 2024/09/09 16:23:36 by tdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ft(int *nbr)
{
	*nbr = 42;
}

/*
#include <unistd.h>

void	ft_ft(int *nbr);

void	ft_putchar(char c) //funct to call write
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb > 9)
    	ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + '0');
}

int	main(void)
{
	int	nbr;

	ft_ft(&nbr);  // Referencing to get address
	ft_putnbr(nbr);  // 10base system modulo and div printer
	ft_putchar('\n');  // skip a line
	return (0);
}
*/
