/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdaniel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:46:31 by tdaniel-          #+#    #+#             */
/*   Updated: 2025/01/14 10:06:00 by tdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	string_printer(char *str, t_format *fmt)
{
	int	i;
	int	stopper;
	int	max_size;

	i = 0;
	if (fmt->precision_value == -1)
	{
		while (str[i])
		{
			write(1, &str[i], 1);
			i++;
		}
	}
	else
	{
		stopper = fmt->precision_value;
		max_size = string_size(str);
		if (stopper > max_size)
			stopper = max_size;
		while (i < stopper)
		{
			write(1, &str[i++], 1);
		}
	}
	return (i);
}

// same as printer without writes
int	string_printer_sizer(char *str, t_format *fmt)
{
	int	i;
	int	stopper;
	int	max_size;

	i = 0;
	if (fmt->precision_value == -1)
	{
		while (str[i])
		{
			i++;
		}
	}
	else
	{
		stopper = fmt->precision_value;
		max_size = string_size(str);
		if (stopper > max_size)
			stopper = max_size;
		while (i < stopper)
		{
			i++;
		}
	}
	return (i);
}

/*
%p (nil) null pointer
%s (null) null string
printf convention
*/

int	ft_print_string(char *str, t_format *fmt)
{
	int	bytes;

	if (fmt->is_left_justified == 1)
	{
		if (str == NULL)
			bytes = handle_null(fmt) + width_string(str, fmt);
		else
			bytes = string_printer(str, fmt) + width_string(str, fmt);
	}
	else
	{
		if (str == NULL)
			bytes = width_string(str, fmt) + handle_null(fmt);
		else
			bytes = width_string(str, fmt) + string_printer(str, fmt);
	}
	return (bytes);
}
