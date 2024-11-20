/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdaniel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:46:31 by tdaniel-          #+#    #+#             */
/*   Updated: 2024/11/20 10:26:46 by tdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
unsign because hex values arent signed

(nil) specifically represents a null pointer in hexadecimal output style
which is unique to the %p specifier in original printf
(nil) avoids confusion with (null) and indicates that it refers to a null pointer

send to print_hex with lowercase format
*/

int	ft_print_pointer(unsigned long pointer)
{
	int	length;

	length = 0;
	if (!pointer)
	{
		write(1, "(nil)", 5);
		length += 5;
	}
	else
	{
		write(1, "0x", 2);
		length += 2;
		length += ft_print_hex(pointer, 'x');
	}
	return (length);
}
