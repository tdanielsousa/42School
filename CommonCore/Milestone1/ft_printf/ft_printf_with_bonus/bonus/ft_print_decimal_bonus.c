/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdaniel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:46:31 by tdaniel-          #+#    #+#             */
/*   Updated: 2025/01/06 22:17:23 by tdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

/*
in fmt->is_left_justified == 1 :
    length += sign_checker(n, fmt);
    length += precision_calculator(n, fmt);
    length += buffer_number_printer(n, fmt);
    length += width_calculator(n, fmt);
and
if (fmt->is_there_zero == 1)
	length += sign_checker(n, fmt);
	length += width_calculator(n, fmt);
changed to norminette compliance
*/

int	ft_print_decimal(int n, t_format *fmt)
{
	int	length;

	length = 0;
	if (fmt->precision_value != -1 && fmt->is_there_zero == 1)
		fmt->is_there_zero = 0;
	if (fmt->is_left_justified == 1)
	{
		length += sign_checker(n, fmt) + precision_calculator(n, fmt);
		length += buffer_number_printer(n, fmt) + width_calculator(n, fmt);
	}
	else
	{
		if (fmt->is_there_zero == 1)
		{
			length += sign_checker(n, fmt) + width_calculator(n, fmt);
		}
		else
		{
			length += width_calculator(n, fmt);
			length += sign_checker(n, fmt);
		}
		length += precision_calculator(n, fmt);
		length += buffer_number_printer(n, fmt);
	}
	return (length);
}
