/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdaniel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 08:58:45 by tdaniel-          #+#    #+#             */
/*   Updated: 2024/11/20 10:41:10 by tdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);

// Conversion function prototypes
int	ft_print_char(int c);
int	ft_print_string(char *str);
int	ft_print_decimal(int n);
int	ft_print_unsigned(unsigned int n);
int	ft_print_hex(unsigned long nb, const char form);
int	ft_print_pointer(unsigned long pointer);
int	ft_print_percent(void);

#endif
