/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdaniel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 08:58:45 by tdaniel-          #+#    #+#             */
/*   Updated: 2025/01/15 08:06:45 by tdaniel-         ###   ########.fr       */
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

//function prototypes
int		ft_printf(const char *format, ...);
int		which_specifier(char specifier, va_list args, t_format *fmt);
int		ft_isdigit(int c);
int		ft_atoi(const char *nptr);
void	ft_putnbr_write(int n, char *buffer);
int		handle_null_size(t_format *fmt);
int		handle_null(t_format *fmt);
int		width_string(char *str, t_format *fmt);
int		string_size(char *str);
int		width_size_number_u(unsigned long long n, t_format *fmt);
int		width_calculator_u(unsigned long long n, t_format *fmt);
int		ft_print_unsigned(unsigned long long n, t_format *fmt);
int		string_printer(char *str, t_format *fmt);
int		string_printer_sizer(char *str, t_format *fmt);
int		ft_print_string(char *str, t_format *fmt);
int		ft_print_hex_pointer(unsigned long nb, const char specifier,
			t_format *fmt);
int		ft_print_pointer(unsigned long pointer, t_format *fmt);
int		ft_hex_prefix(t_format *fmt, const char specifier, unsigned long nb);
int		ft_print_hex(unsigned long nb, const char specifier, t_format *fmt);
int		ft_print_decimal(int n, t_format *fmt);
int		ft_print_char(int c, t_format *fmt);
int		width_single_char(t_format *fmt);
int		populate_nil(t_format *fmt);
int		width_calculator_nil(int index, t_format *fmt);
int		width_calculator_pointer(int index, t_format *fmt);
int		width_size_number_pointer(int index, t_format *fmt);
int		handle_padding_pointer(int padding_length, char padding_char);
void	reset_format(t_format *fmt);
int		parse_flags_and_width(const char *format, int i, t_format *fmt);
int		parse_precision_and_specifier(const char *format, int i, t_format *fmt);
int		parse_format(const char *format, int i, t_format *fmt);
int		ft_hex_logic(unsigned long nb, const char specifier, char *buffer,
			t_format *fmt);
int		print_buffer_reverse(char *buffer, int index);
char	*which_base(const char specifier);
int		width_calculator_x(int index, t_format *fmt);
int		width_size_number_x(int index, t_format *fmt);
int		handle_padding_x(int padding_length, char padding_char, t_format *fmt);
int		precision_size_report_x(int n, t_format *fmt);
int		precision_calculator_x(int n, t_format *fmt);
int		width_size_number(int n, t_format *fmt);
int		handle_padding(int padding_length, char padding_char);
int		width_calculator(int n, t_format *fmt);
int		number_size_calculator_decimal(int n);
int		sign_checker(int n, t_format *fmt);
int		buffer_number_printer(int n, t_format *fmt);
int		precision_calculator(int n, t_format *fmt);
int		precision_size_report(int n, t_format *fmt);
int		buffer_number_printer_unsigned(unsigned long long n, t_format *fmt);
void	ft_putnbr_write_unsigned(unsigned long long n, char *buffer);
int		number_size_calculator_unsigned(unsigned long long n);
int		precision_calculator_unsigned(unsigned long long n, t_format *fmt);
int		precision_size_report_unsigned(unsigned long long n, t_format *fmt);

#endif
