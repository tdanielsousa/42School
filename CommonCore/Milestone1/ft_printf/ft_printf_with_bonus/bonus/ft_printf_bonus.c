/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdaniel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:46:31 by tdaniel-          #+#    #+#             */
/*   Updated: 2025/01/06 22:18:29 by tdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	which_specifier(char specifier, va_list args, t_format *fmt)
{
	if (specifier == 'd' || specifier == 'i')
		return (ft_print_decimal(va_arg(args, int), fmt));
	return (0);
}

// Skip the '%' character
// Parse the format and update the struct
// Once we have the parsed format, handle the specifier
int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			total_bytes_printed;
	int			i;
	t_format	fmt;

	va_start(args, format);
	total_bytes_printed = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] != '%')
		{
			write(1, &format[i], 1);
			total_bytes_printed++;
			i++;
		}
		else
		{
			i++;
			i = parse_format(format, i, &fmt);
			total_bytes_printed += which_specifier(fmt.specifier, args, &fmt);
		}
	}
	va_end(args);
	return (total_bytes_printed);
}
