/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdaniel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:46:31 by tdaniel-          #+#    #+#             */
/*   Updated: 2024/11/20 10:09:15 by tdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
Print the percent sign
Return the number of bytes printed
*/

int	ft_print_percent(void)
{
	write(1, "%", 1);
	return (1);
}
