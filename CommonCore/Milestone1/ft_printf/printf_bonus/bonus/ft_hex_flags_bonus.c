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

int	precision_calculator_x(int n, t_format *fmt)
{
	int	precision;
	int	length;

	length = 0;
	precision = fmt->precision_value;
	while (precision > n)
	{
		write(1, "0", 1);
		precision--;
		length++;
	}
	return (length);
}

int	precision_size_report_x(int n, t_format *fmt)
{
	int	precision;
	int	length;

	length = 0;
	precision = fmt->precision_value;
	while (precision > n)
	{
		precision--;
		length++;
	}
	return (length);
}

int	handle_padding_x(int padding_length, char padding_char, t_format *fmt)
{
	int	total_length;

	total_length = 0;
	if (fmt->is_there_zero == 1 && fmt->precision_value != -1)
		padding_char = ' ';
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

// if (fmt->is_there_cardinal == 1 && index > 0)
// Include prefix for non-zero values
int	width_size_number_x(int index, t_format *fmt)
{
	int	size_already_used;
	int	padding_length;

	size_already_used = index;
	if (fmt->is_there_cardinal == 1 && index > 0)
		size_already_used += 2;
	size_already_used += precision_size_report_x(index, fmt);
	padding_length = fmt->width_value - size_already_used;
	return (padding_length);
}

int	width_calculator_x(int index, t_format *fmt)
{
	int	padding_length;
	int	total_length;

	total_length = 0;
	padding_length = width_size_number_x(index, fmt);
	if (padding_length > 0)
	{
		if (fmt->is_left_justified == 1)
		{
			total_length += handle_padding_x(padding_length, ' ', fmt);
		}
		else
		{
			if (fmt->is_there_zero == 1 && fmt->is_left_justified == 0)
			{
				total_length += handle_padding_x(padding_length, '0', fmt);
			}
			else
			{
				total_length += handle_padding_x(padding_length, ' ', fmt);
			}
		}
	}
	return (total_length);
}
