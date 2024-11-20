/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdaniel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:46:31 by tdaniel-          #+#    #+#             */
/*   Updated: 2024/11/20 10:35:33 by tdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>

// helper function to handle the conversion specifiers after %
static int	which_specifier(char specifier, va_list args)
{
	if (specifier == 'c')
		return (ft_print_char(va_arg(args, int)));
	else if (specifier == 's')
		return (ft_print_string(va_arg(args, char *)));
	else if (specifier == 'p')
		return (ft_print_pointer((unsigned long)va_arg(args, void *)));
	else if (specifier == 'd' || specifier == 'i')
		return (ft_print_decimal(va_arg(args, int)));
	else if (specifier == 'u')
		return (ft_print_unsigned(va_arg(args, unsigned int)));
	else if (specifier == 'x' || specifier == 'X')
		return (ft_print_hex(va_arg(args, unsigned int), specifier));
	else if (specifier == '%')
		return (ft_print_percent());
	return (0);
}

/*
Prints chars if they are not a %, if they are check the following specifier
Send that specifier to the helper which will return 0 in case of error
Because nothing was printed
Return bytes printed
*/

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		total_bytes_printed;
	int		i;

	va_start(args, format);
	total_bytes_printed = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] != '%')
		{
			write(1, &format[i], 1);
			total_bytes_printed++;
		}
		else
		{
			i++;
			total_bytes_printed += which_specifier(format[i], args);
		}
		i++;
	}
	va_end(args);
	return (total_bytes_printed);
}
