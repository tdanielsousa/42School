/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdaniel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:46:31 by tdaniel-          #+#    #+#             */
/*   Updated: 2025/01/16 09:30:39 by tdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

// write % directly because it isnt affected by flags
int	which_specifier(char specifier, va_list args, t_format *fmt)
{
	if (specifier == 'c')
		return (ft_print_char(va_arg(args, int), fmt));
	else if (specifier == 's')
		return (ft_print_string(va_arg(args, char *), fmt));
	else if (specifier == 'p')
		return (ft_print_pointer((unsigned long)va_arg(args, void *), fmt));
	else if (specifier == 'd' || specifier == 'i')
		return (ft_print_decimal(va_arg(args, int), fmt));
	else if (specifier == 'u')
		return (ft_print_unsigned(va_arg(args, unsigned long long), fmt));
	else if (specifier == 'x' || specifier == 'X')
		return (ft_print_hex(va_arg(args, unsigned int), specifier, fmt));
	else if (specifier == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	return (0);
}

// Parse the format, update the struct send to specifier
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
