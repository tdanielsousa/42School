/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdaniel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:46:31 by tdaniel-          #+#    #+#             */
/*   Updated: 2024/11/20 10:28:50 by tdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
Same as putnbr just remove the signed part

ex. nr 321

321/1  >= 10 - Y- divi =10
321/10  >= 10 - Y - divi = 100
321/100  >= 10 - X -
divi = 100

(nr / divisor) % 10 + '0';
321/100 = 3 % 10 = 3 + '0';
divisor /= 10;
321/10 = 32 % 10 = 2 + '0';
divisor /= 10;
321/1 = 321 % 10 = 1 + '0';
*/

static int	ft_putnbr_unsigned(unsigned int n)
{
	unsigned int	nr;
	int				divisor;
	char			c;
	int				length;

	nr = n;
	divisor = 1;
	length = 0;
	while (nr / divisor >= 10)
		divisor *= 10;
	while (divisor > 0)
	{
		c = (nr / divisor) % 10 + '0';
		write(1, &c, 1);
		divisor /= 10;
		length++;
	}
	return (length);
}

int	ft_print_unsigned(unsigned int n)
{
	return (ft_putnbr_unsigned(n));
}
