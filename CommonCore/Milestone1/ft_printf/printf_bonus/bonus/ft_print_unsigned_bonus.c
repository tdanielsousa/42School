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

int	number_size_calculator_unsigned(unsigned long long n)
{
	unsigned long long	divisor;
	int					i;

	divisor = 1;
	i = 0;
	while ((n / divisor) >= 10)
		divisor *= 10;
	while (divisor > 0)
	{
		i++;
		n = n % divisor;
		divisor = divisor / 10;
	}
	return (i);
}

//long long to avoid errors because unsigned int highest nr 4294967295
int	buffer_number_printer_unsigned(unsigned long long n, t_format *fmt)
{
	int		buff_used;
	char	buffer_number[12];

	buff_used = number_size_calculator_unsigned(n);
	ft_putnbr_write_unsigned(n, buffer_number);
	if (n == 0 && fmt->precision_value == 0)
		return (0);
	write(1, buffer_number, buff_used);
	return (buff_used);
}

/*
zero cant exist with precision
works just like decimal but with long long
also removed the signed portions
*/
int	ft_print_unsigned(unsigned long long n, t_format *fmt)
{
	int	length;

	length = 0;
	if (fmt->precision_value != -1 && fmt->is_there_zero == 1)
		fmt->is_there_zero = 0;
	if (fmt->is_left_justified == 1)
	{
		length += precision_calculator_unsigned(n, fmt);
		length += buffer_number_printer_unsigned(n, fmt) + width_calculator_u(n,
				fmt);
	}
	else
	{
		if (fmt->is_there_zero == 1)
			length += width_calculator_u(n, fmt);
		else
			length += width_calculator_u(n, fmt);
		length += precision_calculator_unsigned(n, fmt);
		length += buffer_number_printer_unsigned(n, fmt);
	}
	return (length);
}
