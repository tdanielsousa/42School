/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdaniel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:46:31 by tdaniel-          #+#    #+#             */
/*   Updated: 2024/11/20 10:08:49 by tdaniel-         ###   ########.fr       */
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
// decrease length because of array index 0
// return the nr bytes to hex to return to printf

static int	print_buffer_reverse(char *buffer, int length)
{
	int	result;

	result = 0;
	length--;
	while (length >= 0)
	{
		write(1, &buffer[length], 1);
		result++;
		length--;
	}
	return (result);
}

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
/*
ex. 160 
base becomes string with caps or not 0123456789ABCDEF
160 % 16 || base[0] = "0" || buffer[0]= "0"
160/16=10 and index++ 
10 % 16 || base[10] = "A" || buffer[1]= "A"
Print reverse : A0 and return bytes
*/
