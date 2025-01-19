/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal_precision_flags_bonus.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdaniel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 08:58:45 by tdaniel-          #+#    #+#             */
/*   Updated: 2025/01/16 10:33:15 by tdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

//same as ptnbr but no write just calculates size
int	number_size_calculator_decimal(int n)
{
	long	nr;
	int		divisor;
	int		i;

	nr = n;
	divisor = 1;
	i = 0;
	if (nr < 0)
		nr = -nr;
	while ((nr / divisor) >= 10)
		divisor *= 10;
	while (divisor > 0)
	{
		i++;
		nr = nr % divisor;
		divisor = divisor / 10;
	}
	return (i);
}

//treated the spc flag as a sign
int	sign_checker(int n, t_format *fmt)
{
	if (n >= 0 && fmt->is_there_space == 1 && fmt->is_there_plus == 0)
	{
		write(1, " ", 1);
		return (1);
	}
	if (n >= 0 && fmt->is_there_plus == 1)
	{
		write(1, "+", 1);
		return (1);
	}
	if (n < 0)
	{
		write(1, "-", 1);
		return (1);
	}
	return (0);
}

//doesnt print when precis and n are 0, edge case
//buff 10 holds any nr in the int range (–2147483648)
//buff_used is the bytes for write and to return
int	buffer_number_printer(int n, t_format *fmt)
{
	int		buff_used;
	char	buffer_number[10];

	buff_used = number_size_calculator_decimal(n);
	ft_putnbr_write(n, buffer_number);
	if (n == 0 && fmt->precision_value == 0)
		return (0);
	write(1, buffer_number, buff_used);
	return (buff_used);
}

//precision is the min nr or digits
//if it needs more it writes 0's
int	precision_calculator(int n, t_format *fmt)
{
	int	digits;
	int	precision;
	int	length;

	length = 0;
	digits = number_size_calculator_decimal(n);
	precision = fmt->precision_value;
	while (precision > digits)
	{
		write(1, "0", 1);
		precision--;
		length++;
	}
	return (length);
}

//same as precision_calculator but no write, intended to be used in width
// because width requires the size of the full number + precision
int	precision_size_report(int n, t_format *fmt)
{
	int	digits;
	int	precision;
	int	length;

	length = 0;
	digits = number_size_calculator_decimal(n);
	precision = fmt->precision_value;
	while (precision > digits)
	{
		precision--;
		length++;
	}
	return (length);
}
