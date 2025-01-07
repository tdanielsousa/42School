/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdaniel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:46:31 by tdaniel-          #+#    #+#             */
/*   Updated: 2024/12/26 08:30:44 by tdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
unsign because hex values arent signed

(nil) specifically represents a null pointer in original printf
(nil) avoids confusion with (null) and indicates that its a null pointer

send to print_hex with lowercase format and return bytes to printf
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
