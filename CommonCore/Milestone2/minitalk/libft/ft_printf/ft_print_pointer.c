/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdaniel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:46:31 by tdaniel-          #+#    #+#             */
/*   Updated: 2025/01/16 08:23:23 by tdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
printf c convention:
%p (nil) null pointer 
%s (null) null string
(nil) avoids confusion with (null)
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
