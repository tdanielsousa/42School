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

// Only add padding if the length is positive
int	handle_padding_pointer(int padding_length, char padding_char)
{
	int	total_length;

	total_length = 0;
	if (padding_length > 0)
	{
		while (padding_length-- > 0)
		{
			write(1, &padding_char, 1);
			total_length++;
		}
	}
	return (total_length);
}

//  if (fmt->is_there_cardinal == 1 && index > 0)
// Include prefix for non-zero values
int	width_size_number_pointer(int index, t_format *fmt)
{
	int	size_already_used;
	int	padding_length;

	size_already_used = index;
	if (fmt->is_there_cardinal == 1 && index > 0)
		size_already_used += 2;
	padding_length = fmt->width_value - size_already_used;
	return (padding_length);
}

// padding_length -= 2; 
//acount for printing # directly and adding length there
int	width_calculator_pointer(int index, t_format *fmt)
{
	int	padding_length;
	int	total_length;

	total_length = 0;
	padding_length = width_size_number_pointer(index, fmt);
	padding_length -= 2;
	if (padding_length > 0)
	{
		total_length += handle_padding_pointer(padding_length, ' ');
	}
	return (total_length);
}

int	width_calculator_nil(int index, t_format *fmt)
{
	int	padding_length;
	int	total_length;

	total_length = 0;
	padding_length = fmt->width_value - index;
	if (padding_length > 0)
	{
		total_length += handle_padding_pointer(padding_length, ' ');
	}
	return (total_length);
}

int	populate_nil(t_format *fmt)
{
	int	length;

	length = 0;
	if (fmt->is_left_justified == 1)
	{
		write(1, "(nil)", 5);
		length += 5;
		length += width_calculator_nil(5, fmt);
	}
	else
	{
		length += width_calculator_nil(5, fmt);
		write(1, "(nil)", 5);
		length += 5;
	}
	return (length);
}
