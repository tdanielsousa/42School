/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdaniel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:46:31 by tdaniel-          #+#    #+#             */
/*   Updated: 2025/01/14 09:16:59 by tdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

//if 0 doesnt add prefix
int	ft_hex_prefix(t_format *fmt, const char specifier, unsigned long nb)
{
	if (fmt->is_there_cardinal == 1 && nb != 0)
	{
		if (specifier == 'x')
			write(1, "0x", 2);
		else if (specifier == 'X')
			write(1, "0X", 2);
		return (2);
	}
	return (0);
}

/*
function that assembles left/right justified output
ft_hex_logic to handle conversion logic
index is the nr of bytes already used
*/

int	ft_print_hex(unsigned long nb, const char specifier, t_format *fmt)
{
	char	buffer[16];
	int		index;
	int		length;

	index = 0;
	length = 0;
	index = ft_hex_logic(nb, specifier, buffer, fmt);
	if (fmt->is_left_justified == 1)
	{
		length += ft_hex_prefix(fmt, specifier, nb);
		length += precision_calculator_x(index, fmt);
		length += print_buffer_reverse(buffer, index);
		length += width_calculator_x(index, fmt);
	}
	else
	{
		length += width_calculator_x(index, fmt);
		length += ft_hex_prefix(fmt, specifier, nb);
		length += precision_calculator_x(index, fmt);
		length += print_buffer_reverse(buffer, index);
	}
	return (length);
}
