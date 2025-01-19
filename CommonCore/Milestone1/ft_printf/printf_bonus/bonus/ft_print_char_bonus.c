/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdaniel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:46:31 by tdaniel-          #+#    #+#             */
/*   Updated: 2025/01/14 09:11:41 by tdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	width_single_char(t_format *fmt)
{
	int	width;
	int	length;

	length = 0;
	width = fmt->width_value;
	while (width > 1)
	{
		write(1, " ", 1);
		width--;
		length++;
	}
	return (length);
}

int	ft_print_char(int c, t_format *fmt)
{
	int	bytes;

	if (fmt->is_left_justified == 1)
	{
		write(1, &c, 1);
		bytes = width_single_char(fmt) + 1;
	}
	else
	{
		bytes = width_single_char(fmt) + 1;
		write(1, &c, 1);
	}
	return (bytes);
}
