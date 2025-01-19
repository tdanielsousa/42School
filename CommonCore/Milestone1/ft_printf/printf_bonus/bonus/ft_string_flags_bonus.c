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

int	string_size(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	width_string(char *str, t_format *fmt)
{
	int	wrote_size;
	int	width;
	int	length;
	int	check;

	check = 0;
	length = 0;
	if (fmt->precision_value >= 6 || fmt->precision_value == -1)
		check = 1;
	if (str == NULL && check == 1)
		wrote_size = 6;
	if (str == NULL && check == 0)
		wrote_size = 0;
	if (str != NULL)
		wrote_size = string_printer_sizer(str, fmt);
	width = fmt->width_value;
	while (width > wrote_size)
	{
		write(1, " ", 1);
		width--;
		length++;
	}
	return (length);
}

int	handle_null(t_format *fmt)
{
	if (fmt->precision_value >= 6 || fmt->precision_value == -1)
	{
		write(1, "(null)", 6);
		return (6);
	}
	else
		return (0);
}

int	handle_null_size(t_format *fmt)
{
	if (fmt->precision_value >= 6 || fmt->precision_value == -1)
	{
		return (6);
	}
	else
		return (0);
}
