/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal_width_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdaniel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:46:31 by tdaniel-          #+#    #+#             */
/*   Updated: 2025/01/07 14:32:04 by tdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

// Calculate the length of the number (including sign)
// Include the sign in length
// special case test41 IF for fix pad++
int	width_size_number_u(unsigned long long n, t_format *fmt)
{
	int	number_length;
	int	size_already_used;
	int	padding_length;

	number_length = number_size_calculator_unsigned(n);
	size_already_used = precision_size_report_unsigned(n, fmt) + number_length;
	padding_length = fmt->width_value - size_already_used;
	if (n == 0 && fmt->precision_value == 0 && fmt->width_value != 0)
		padding_length++;
	return (padding_length);
}
// Calculate the padding length
// Only pad if padding_length is greater than 0
// Left-justified padding
// Pad with spaces	// Zero padding (if zero flag is set)

int	width_calculator_u(unsigned long long n, t_format *fmt)
{
	int	padding_length;
	int	total_length;

	total_length = 0;
	padding_length = width_size_number_u(n, fmt);
	if (padding_length > 0)
	{
		if (fmt->is_left_justified == 1)
		{
			total_length += handle_padding(padding_length, ' ');
		}
		else
		{
			if (fmt->is_there_zero && fmt->is_left_justified == 0)
			{
				total_length += handle_padding(padding_length, '0');
			}
			else
			{
				total_length += handle_padding(padding_length, ' ');
			}
		}
	}
	return (total_length);
}

int	precision_calculator_unsigned(unsigned long long n, t_format *fmt)
{
	int	digits;
	int	precision;
	int	length;

	length = 0;
	digits = number_size_calculator_unsigned(n);
	precision = fmt->precision_value;
	while (precision > digits)
	{
		write(1, "0", 1);
		precision--;
		length++;
	}
	return (length);
}

int	precision_size_report_unsigned(unsigned long long n, t_format *fmt)
{
	int	digits;
	int	precision;
	int	length;

	length = 0;
	digits = number_size_calculator_unsigned(n);
	precision = fmt->precision_value;
	while (precision > digits)
	{
		precision--;
		length++;
	}
	return (length);
}
