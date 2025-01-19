/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdaniel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:46:31 by tdaniel-          #+#    #+#             */
/*   Updated: 2025/01/16 09:31:54 by tdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

// -1 indicates precision not specified
// reset for consecutive use

void	reset_format(t_format *fmt)
{
	fmt->is_left_justified = 0;
	fmt->is_there_zero = 0;
	fmt->is_there_plus = 0;
	fmt->is_there_space = 0;
	fmt->is_there_cardinal = 0;
	fmt->width_value = 0;
	fmt->precision_value = -1;
	fmt->specifier = '\0';
}

// Parse width using atoi
// skip index with isdigit

int	parse_flags_and_width(const char *format, int i, t_format *fmt)
{
	while (format[i] == '#' || format[i] == '-' || format[i] == '0'
		|| format[i] == ' ' || format[i] == '+')
	{
		if (format[i] == '-')
			fmt->is_left_justified = 1;
		else if (format[i] == '0')
			fmt->is_there_zero = 1;
		else if (format[i] == '+')
			fmt->is_there_plus = 1;
		else if (format[i] == ' ')
			fmt->is_there_space = 1;
		else if (format[i] == '#')
			fmt->is_there_cardinal = 1;
		i++;
	}
	if (ft_isdigit(format[i]))
		fmt->width_value = ft_atoi(&format[i]);
	while (ft_isdigit(format[i]))
		i++;
	return (i);
}

// value = 0 because only '.' means precision is 0
// to precision exist . needs to exist

int	parse_precision_and_specifier(const char *format, int i, t_format *fmt)
{
	if (format[i] == '.')
	{
		fmt->precision_value = 0;
		i++;
		if (ft_isdigit(format[i]))
			fmt->precision_value = ft_atoi(&format[i]);
		while (ft_isdigit(format[i]))
			i++;
	}
	fmt->specifier = format[i++];
	return (i);
}

// Reset the struct before parsing
// i is incremented in both parses

int	parse_format(const char *format, int i, t_format *fmt)
{
	reset_format(fmt);
	i = parse_flags_and_width(format, i, fmt);
	i = parse_precision_and_specifier(format, i, fmt);
	return (i);
}
