/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdaniel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 08:58:45 by tdaniel-          #+#    #+#             */
/*   Updated: 2025/01/06 22:34:45 by tdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <unistd.h>

typedef struct s_format
{
	int		is_left_justified;
	int		is_there_zero;
	int		is_there_plus;
	int		is_there_space;
	int		is_there_cardinal;
	int		width_value;
	int		precision_value;
	char	specifier;
}			t_format;

int			ft_printf(const char *format, ...);

//function prototypes

int			ft_atoi(const char *nptr);
int			ft_isdigit(int c);
void		ft_putnbr_write(int n, char *buffer);
int			number_size_calculator_decimal(int n);
int			sign_checker(int n, t_format *fmt);
int			buffer_number_printer(int n, t_format *fmt);
int			precision_calculator(int n, t_format *fmt);
int			precision_size_report(int n, t_format *fmt);
int			width_size_number(int n, t_format *fmt);
int			handle_padding(int padding_length, char padding_char);
int			width_calculator(int n, t_format *fmt);
void		reset_format(t_format *fmt);
int			parse_flags_and_width(const char *format, int i, t_format *fmt);
int			parse_precision_and_specifier(const char *format, int i,
				t_format *fmt);
int			parse_format(const char *format, int i, t_format *fmt);
int			ft_print_decimal(int n, t_format *fmt);
int			which_specifier(char specifier, va_list args, t_format *fmt);

#endif
