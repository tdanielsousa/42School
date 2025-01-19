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

// Call ft_hex_logic to populate the buffer and get the index.
// debug printf("Bytes: %d\n", length);

int	ft_print_hex_pointer(unsigned long nb, const char specifier, t_format *fmt)
{
	char	buffer[16];
	int		index;
	int		length;

	index = 0;
	length = 0;
	index = ft_hex_logic(nb, specifier, buffer, fmt);
	if (fmt->is_left_justified == 1)
	{
		length += 2;
		write(1, "0x", 2);
		length += print_buffer_reverse(buffer, index);
		length += width_calculator_pointer(index, fmt);
	}
	else
	{
		length += width_calculator_pointer(index, fmt);
		length += 2;
		write(1, "0x", 2);
		length += print_buffer_reverse(buffer, index);
	}
	return (length);
}

int	ft_print_pointer(unsigned long pointer, t_format *fmt)
{
	int	length;

	length = 0;
	if (!pointer)
	{
		length += populate_nil(fmt);
	}
	else
	{
		length += ft_print_hex_pointer(pointer, 'x', fmt);
	}
	return (length);
}
