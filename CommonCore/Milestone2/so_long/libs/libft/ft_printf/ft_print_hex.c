/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdaniel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:46:31 by tdaniel-          #+#    #+#             */
/*   Updated: 2025/01/16 08:24:02 by tdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*which_base(const char specifier)
{
	char	*base;

	if (specifier == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	return (base);
}
// decrease index because of array index 0
// return the nr bytes to hex to return to printf

static int	print_buffer_reverse(char *buffer, int index)
{
	int	result;

	result = 0;
	index--;
	while (index >= 0)
	{
		write(1, &buffer[index], 1);
		result++;
		index--;
	}
	return (result);
}
/*
ex. 160 
base  0123456789ABCDEF
160 % 16 = 0 || base[0] = "0" || buffer[0]= "0"
160/16=10 and index++ 
10 % 16 || base[10] = "A" || buffer[1]= "A"
Print reverse : A0 and return bytes
*/

int	ft_print_hex(unsigned long nb, const char specifier)
{
	char	buffer[16];
	int		index;
	int		result;
	char	*base;

	result = 0;
	index = 0;
	base = which_base(specifier);
	if (nb == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	while (nb > 0)
	{
		buffer[index] = base[nb % 16];
		index++;
		nb /= 16;
	}
	result = print_buffer_reverse(buffer, index);
	return (result);
}
