/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_shared_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdaniel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:46:31 by tdaniel-          #+#    #+#             */
/*   Updated: 2025/01/16 11:03:47 by tdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

//functs shared between pointer and hex
char	*which_base(const char specifier)
{
	char	*base;

	if (specifier == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	return (base);
}

//decrease index because of array index 0
int	print_buffer_reverse(char *buffer, int index)
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
--------------------------------------------
converts the number into hexadecimal and stores it in buffer
returns the number of digits
long because of hexa
 */
int	ft_hex_logic(unsigned long nb, const char specifier, char *buffer,
	t_format *fmt)
{
	int		index;
	char	*base;

	index = 0;
	base = which_base(specifier);
	if (nb == 0 && fmt->precision_value != 0)
	{
		buffer[index] = '0';
		return (1);
	}
	while (nb > 0)
	{
		buffer[index] = base[nb % 16];
		index++;
		nb /= 16;
	}
	return (index);
}
