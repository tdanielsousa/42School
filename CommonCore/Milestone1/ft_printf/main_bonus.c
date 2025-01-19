/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdaniel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:46:31 by tdaniel-          #+#    #+#             */
/*   Updated: 2025/01/15 10:01:51 by tdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
cc main_bonus.c libftprintf.a
*/

# include <stdio.h>
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

/*
	place before return in printf to debug flags
            printf("\n****is_left_justified: %d\n", fmt.is_left_justified);
            printf("****is_there_zero: %d\n", fmt.is_there_zero);
            printf("****is_there_plus: %d\n", fmt.is_there_plus);
            printf("****is_there_space: %d\n", fmt.is_there_space);
            printf("****is_there_cardinal: %d\n", fmt.is_there_cardinal);
            printf("****width_value: %d\n", fmt.width_value);
            printf("****precision_value: %d\n", fmt.precision_value);
            printf("****specifier: %c\n", fmt.specifier);
*/

int main()
{
  int printf_bytes, ft_printf_bytes;

printf("\033[1;33m\n ************************************************************************** \n\033[0m");
printf("\033[1;33m **************** \033[0m           decimal              \033[1;33m      ******************* \033[0m\n");
printf("\033[1;33m ************************************************************************** \n\033[0m");

    // Test 0: Test with width and zero padding, positive number
    printf_bytes = printf("Hello World |%+05d|teste\n", 1);
    ft_printf_bytes = ft_printf("Hello World |%+05d|teste\n", 1);
    printf("Bytes printed by or_printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    
    // Test 1: Test with width and zero padding, positive number
    printf_bytes = printf("Test 1: |%05d|\n", 42);
    ft_printf_bytes = ft_printf("Test 1: |%05d|\n", 42);
    printf("Bytes printed by or_printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    
    // Test 2: Test with width and zero padding, negative number
    printf_bytes = printf("Test 2: |%05d|\n", -42);
    ft_printf_bytes = ft_printf("Test 2: |%05d|\n", -42);
    printf("Bytes printed by or_printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    
    // Test 3: Test with precision and no width
    printf_bytes = printf("Test 3: |%.5d|\n", 42);
    ft_printf_bytes = ft_printf("Test 3: |%.5d|\n", 42);
    printf("Bytes printed by or_printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    
    // Test 4: Test with precision and width, no zero padding
    printf_bytes = printf("Test 4: |%10.5d|\n", 42);
    ft_printf_bytes = ft_printf("Test 4: |%10.5d|\n", 42);
    printf("Bytes printed by or_printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
     
   
    // Test 7: Test with width and positive sign
    printf_bytes = printf("Test 7: |%+5d|\n", 42);
    ft_printf_bytes = ft_printf("Test 7: |%+5d|\n", 42);
    printf("Bytes printed by or_printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    
    // Test 8: Test with width, zero padding, and positive sign
    printf_bytes = printf("Test 8: |%+05d|\n", 42);
    ft_printf_bytes = ft_printf("Test 8: |%+05d|\n", 42);
    printf("Bytes printed by or_printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    
    // Test 9: Test with precision, width, and positive sign
    printf_bytes = printf("Test 9: |%+10.5d|\n", 42);
    ft_printf_bytes = ft_printf("Test 9: |%+10.5d|\n", 42);
    printf("Bytes printed by or_printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    
    // Test 10: Test with space flag, positive number
    printf_bytes = printf("Test 10: |% 5d|\n", 42);
    ft_printf_bytes = ft_printf("Test 10: |% 5d|\n", 42);
    printf("Bytes printed by or_printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    
    // Test 11: Test with space flag, negative number
    printf_bytes = printf("Test 11: |% 5d|\n", -42);
    ft_printf_bytes = ft_printf("Test 11: |% 5d|\n", -42);
    printf("Bytes printed by or_printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    
    // Test 12: Test with space flag and zero padding
    printf_bytes = printf("Test 12: |% 05d|\n", 42);
    ft_printf_bytes = ft_printf("Test 12: |% 05d|\n", 42);
    printf("Bytes printed by or_printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    
    // Test 13: Test with left justification and width
    printf_bytes = printf("Test 13: |%-5d|\n", 42);
    ft_printf_bytes = ft_printf("Test 13: |%-5d|\n", 42);
    printf("Bytes printed by or_printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    
    // Test 14: Test with left justification, width, and precision
    printf_bytes = printf("Test 14: |%-10.5d|\n", 42);
    ft_printf_bytes = ft_printf("Test 14: |%-10.5d|\n", 42);
    printf("Bytes printed by or_printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    
    // Test 15: Test with left justification, width, and negative number
    printf_bytes = printf("Test 15: |%-10d|\n", -42);
    ft_printf_bytes = ft_printf("Test 15: |%-10d|\n", -42);
    printf("Bytes printed by or_printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    
    // Test 16: Test with zero padding and width larger than number
    printf_bytes = printf("Test 16: |%010d|\n", 1234);
    ft_printf_bytes = ft_printf("Test 16: |%010d|\n", 1234);
    printf("Bytes printed by or_printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    
   
    // Test 18: Test with zero padding and precision only
    printf_bytes = printf("Test 18: |%.5d|\n", 1234);
    ft_printf_bytes = ft_printf("Test 18: |%.5d|\n", 1234);
    printf("Bytes printed by or_printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    
    // Test 19: Test with width smaller than number, no flags
    printf_bytes = printf("Test 19: |%2d|\n", 12345);
    ft_printf_bytes = ft_printf("Test 19: |%2d|\n", 12345);
    printf("Bytes printed by or_printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    
    // Test 20: Test with precision smaller than number
    printf_bytes = printf("Test 20: |%.3d|\n", 12345);
    ft_printf_bytes = ft_printf("Test 20: |%.3d|\n", 12345);
    printf("Bytes printed by or_printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    
    // Test 21: Test with precision equal to number size
    printf_bytes = printf("Test 21: |%.5d|\n", 12345);
    ft_printf_bytes = ft_printf("Test 21: |%.5d|\n", 12345);
    printf("Bytes printed by or_printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    
    // Test 22: Test with width and precision larger than number
    printf_bytes = printf("Test 22: |%10.8d|\n", 123);
    ft_printf_bytes = ft_printf("Test 22: |%10.8d|\n", 123);
    printf("Bytes printed by or_printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    
    // Test 23: Test with width and precision equal to each other
    printf_bytes = printf("Test 23: |%8.8d|\n", 123);
    ft_printf_bytes = ft_printf("Test 23: |%8.8d|\n", 123);
    printf("Bytes printed by or_printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    
    // Test 24: Test with negative number, width, and precision
    printf_bytes = printf("Test 24: |%10.5d|\n", -123);
    ft_printf_bytes = ft_printf("Test 24: |%10.5d|\n", -123);
    printf("Bytes printed by or_printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    
    // Test 25: Test with zero padding, width, and negative number
    printf_bytes = printf("Test 25: |%010d|\n", -123);
    ft_printf_bytes = ft_printf("Test 25: |%010d|\n", -123);
    printf("Bytes printed by or_printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    
    

    // Test 27: Test with space flag and negative number
    printf_bytes = printf("Test 27: |% 10d|\n", -123);
    ft_printf_bytes = ft_printf("Test 27: |% 10d|\n", -123);
    printf("Bytes printed by or_printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    
   

    // Test 29: Test with width and zero padding, positive number
    printf_bytes = printf("Test 29: |%05d|\n", 42);
    ft_printf_bytes = ft_printf("Test 29: |%05d|\n", 42);
    printf("Bytes printed by or_printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    
    // Test 30: Test with width and zero padding, negative number
    printf_bytes = printf("Test 30: |%05d|\n", -42);
    ft_printf_bytes = ft_printf("Test 30: |%05d|\n", -42);
    printf("Bytes printed by or_printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    
    // Test 31: Test with width, no padding, positive number
    printf_bytes = printf("Test 31: |%5d|\n", 42);
    ft_printf_bytes = ft_printf("Test 31: |%5d|\n", 42);
    printf("Bytes printed by or_printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    
    // Test 32: Test with width, no padding, negative number
    printf_bytes = printf("Test 32: |%5d|\n", -42);
    ft_printf_bytes = ft_printf("Test 32: |%5d|\n", -42);
    printf("Bytes printed by or_printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    
    // Test 33: Test with precision, positive number
    printf_bytes = printf("Test 33: |%.5d|\n", 42);
    ft_printf_bytes = ft_printf("Test 33: |%.5d|\n", 42);
    printf("Bytes printed by or_printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    
    // Test 34: Test with precision, negative number
    printf_bytes = printf("Test 34: |%.5d|\n", -42);
    ft_printf_bytes = ft_printf("Test 34: |%.5d|\n", -42);
    printf("Bytes printed by or_printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    
    // Test 35: Test with precision and width, positive number
    printf_bytes = printf("Test 35: |%8.5d|\n", 42);
    ft_printf_bytes = ft_printf("Test 35: |%8.5d|\n", 42);
    printf("Bytes printed by or_printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    
    // Test 36: Test with precision and width, negative number
    printf_bytes = printf("Test 36: |%8.5d|\n", -42);
    ft_printf_bytes = ft_printf("Test 36: |%8.5d|\n", -42);
    printf("Bytes printed by or_printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    
    // Test 37: Test with width smaller than number of digits, positive number
    printf_bytes = printf("Test 37: |%2d|\n", 12345);
    ft_printf_bytes = ft_printf("Test 37: |%2d|\n", 12345);
    printf("Bytes printed by or_printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    
    // Test 38: Test with width smaller than number of digits, negative number
    printf_bytes = printf("Test 38: |%2d|\n", -12345);
    ft_printf_bytes = ft_printf("Test 38: |%2d|\n", -12345);
    printf("Bytes printed by or_printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    
   

   

    // Test 41: Test with width, precision zero, and zero number
    printf_bytes = printf("Test 41: |%5.0d|\n", 0);
    ft_printf_bytes = ft_printf("Test 41: |%5.0d|\n", 0);
    printf("Bytes printed by or_printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    
    // Test 42: Test with width and precision, number zero
    printf_bytes = printf("Test 42: |%5.3d|\n", 0);
    ft_printf_bytes = ft_printf("Test 42: |%5.3d|\n", 0);
    printf("Bytes printed by or_printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    
    // Test 43: Test negative number with large width and precision
    printf_bytes = printf("Test 43: |%15.10d|\n", -123);
    ft_printf_bytes = ft_printf("Test 43: |%15.10d|\n", -123);
    printf("Bytes printed by or_printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    
    // Test 44: Test positive number with large width and precision
    printf_bytes = printf("Test 44: |%15.10d|\n", 123);
    ft_printf_bytes = ft_printf("Test 44: |%15.10d|\n", 123);
    printf("Bytes printed by or_printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    
    // Test 45: Test number zero with no width and precision zero
    printf_bytes = printf("Test 45: |%.0d|\n", 0);
    ft_printf_bytes = ft_printf("Test 45: |%.0d|\n", 0);
    printf("Bytes printed by or_printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

printf("\033[1;33m\n ************************************************************************** \n\033[0m");
printf("\033[1;33m **************** \033[0m           percent               \033[1;33m      ****************** \033[0m\n");
 printf("\033[1;33m ************************************************************************** \n\033[0m");


    printf_bytes = printf("|%%|\n");
    ft_printf_bytes = ft_printf("|%%|\n");
    printf("Bytes nr: %d\n", printf_bytes);
    printf("Bytes FT: %d\n", ft_printf_bytes);
        if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

printf("\033[1;33m\n ************************************************************************** \n\033[0m");
printf("\033[1;33m ************** \033[0m           single char               \033[1;33m      **************** \033[0m\n");
 printf("\033[1;33m ************************************************************************** \n\033[0m");


    char ch = 'A';
    printf_bytes = printf("|%11c|\n", ch);
    ft_printf_bytes = ft_printf("|%11c|\n", ch);
    printf("Bytes nr: %d\n", printf_bytes);
    printf("Bytes FT: %d\n", ft_printf_bytes);
        if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    
    
    // Basic Case: Single character without width
char ch1 = 'B';
printf_bytes = printf("|%c|\n", ch1);
ft_printf_bytes = ft_printf("|%c|\n", ch1);
printf("Bytes nr: %d\n", printf_bytes);
printf("Bytes FT: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    
// Basic Case: Single character with width
char ch2 = 'C';
printf_bytes = printf("|%5c|\n", ch2);
ft_printf_bytes = ft_printf("|%5c|\n", ch2);
printf("Bytes nr: %d\n", printf_bytes);
printf("Bytes FT: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    
// Basic Case: Single character with left justification
char ch3 = 'D';
printf_bytes = printf("|%-5c|\n", ch3);
ft_printf_bytes = ft_printf("|%-5c|\n", ch3);
printf("Bytes nr: %d\n", printf_bytes);
printf("Bytes FT: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    
// Edge Case: Null character
char ch4 = '\0';
printf_bytes = printf("n1|%c|\n", ch4);
ft_printf_bytes = ft_printf("n1|%c|\n", ch4);
printf("Bytes nr: %d\n", printf_bytes);
printf("Bytes FT: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    
// Edge Case: Null character with width
char ch5 = '\0';
printf_bytes = printf("n2|%5c|\n", ch5);
ft_printf_bytes = ft_printf("n2|%5c|\n", ch5);
printf("Bytes nr: %d\n", printf_bytes);
printf("Bytes FT: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    
// Edge Case: Null character with left justification
char ch6 = '\0';
printf_bytes = printf("n3|%-5c|\n", ch6);
ft_printf_bytes = ft_printf("n3|%-5c|\n", ch6);
printf("Bytes nr: %d\n", printf_bytes);
printf("Bytes FT: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    
// Edge Case: Width smaller than character output
char ch7 = 'E';
printf_bytes = printf("|%1c|\n", ch7);
ft_printf_bytes = ft_printf("|%1c|\n", ch7);
printf("Bytes nr: %d\n", printf_bytes);
printf("Bytes FT: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    
// Edge Case: Negative width (interpreted as left justification)
char ch8 = 'F';
printf_bytes = printf("|%-5c|\n", ch8);
ft_printf_bytes = ft_printf("|%-5c|\n", ch8);
printf("Bytes nr: %d\n", printf_bytes);
printf("Bytes FT: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    
// Edge Case: Large width
char ch9 = 'G';
printf_bytes = printf("|%50c|\n", ch9);
ft_printf_bytes = ft_printf("|%50c|\n", ch9);
printf("Bytes nr: %d\n", printf_bytes);
printf("Bytes FT: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    
// Edge Case: Width and zero padding (ignored for `%c`)
char ch10 = 'H';
printf_bytes = printf("|%5c|\n", ch10);
ft_printf_bytes = ft_printf("|%5c|\n", ch10);
printf("Bytes nr: %d\n", printf_bytes);
printf("Bytes FT: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    
// Edge Case: Non-ASCII character
char ch11 = 0xE9; // é in extended ASCII
printf_bytes = printf("|%c|\n", ch11);
ft_printf_bytes = ft_printf("|%c|\n", ch11);
printf("Bytes nr: %d\n", printf_bytes);
printf("Bytes FT: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    

    
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////

printf("\033[1;33m\n ************************************************************************** \n\033[0m");
printf("\033[1;33m **************** \033[0m           pointers              \033[1;33m      ****************** \033[0m\n");
 printf("\033[1;33m ************************************************************************** \n\033[0m");


// Edge Case 8: NULL pointer with width
void *null_ptr_2 = NULL;
printf_bytes = printf("|%20p|\n", null_ptr_2);
ft_printf_bytes = ft_printf("|%20p|\n", null_ptr_2);
printf("Bytes printed by or_printf: %d\n", printf_bytes);
printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    
// Edge Case 9: NULL pointer with left justification and width
void *null_ptr_3 = NULL;
printf_bytes = printf("|%-25p|\n", null_ptr_3);
ft_printf_bytes = ft_printf("|%-25p|\n", null_ptr_3);
printf("Bytes printed by or_printf: %d\n", printf_bytes);
printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    
// Edge Case 10: Pointer with small width (smaller than pointer size)
void *ptr_7 = (void *)0xDEADBEEF;
printf_bytes = printf("|%5p|\n", ptr_7);
ft_printf_bytes = ft_printf("|%5p|\n", ptr_7);
printf("Bytes printed by or_printf: %d\n", printf_bytes);
printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    
// Edge Case 11: Pointer with very large width
void *ptr_8 = (void *)0xBEEFDEAD;
printf_bytes = printf("|%50p|\n", ptr_8);
ft_printf_bytes = ft_printf("|%50p|\n", ptr_8);
printf("Bytes printed by or_printf: %d\n", printf_bytes);
printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    
// Edge Case 12: Pointer with zero width and zero padding
void *ptr_9 = (void *)123456789;
printf_bytes = printf("|%10p|\n", ptr_9);
ft_printf_bytes = ft_printf("|%10p|\n", ptr_9);
printf("Bytes printed by or_printf: %d\n", printf_bytes);
printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    
// Edge Case 13: Pointer with left justification, zero padding ignored
void *ptr_10 = (void *)789456;
printf_bytes = printf("|%-15p|\n", ptr_10);
ft_printf_bytes = ft_printf("|%-15p|\n", ptr_10);
printf("Bytes printed by or_printf: %d\n", printf_bytes);
printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    
// Edge Case 14: Pointer to maximum unsigned value
void *ptr_11 = (void *)0xFFFFFFFFFFFFFFFF;
printf_bytes = printf("|%p|\n", ptr_11);
ft_printf_bytes = ft_printf("|%p|\n", ptr_11);
printf("Bytes printed by or_printf: %d\n", printf_bytes);
printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    
// Edge Case 15: Pointer to address zero
void *ptr_12 = (void *)0;
printf_bytes = printf("|%p|\n", ptr_12);
ft_printf_bytes = ft_printf("|%p|\n", ptr_12);
printf("Bytes printed by or_printf: %d\n", printf_bytes);
printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    
// Edge Case 16: Pointer with multiple conflicting flags
void *ptr_13 = (void *)0xCAFEBABE;
printf_bytes = printf("|%-20p|\n", ptr_13);
ft_printf_bytes = ft_printf("|%-20p|\n", ptr_13);
printf("Bytes printed by or_printf: %d\n", printf_bytes);
printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    
// Edge Case 17: Large address with left justification
void *ptr_14 = (void *)0x7FFFFFFFFFFFFFFF;
printf_bytes = printf("|%-40p|\n", ptr_14);
ft_printf_bytes = ft_printf("|%-40p|\n", ptr_14);
printf("Bytes printed by or_printf: %d\n", printf_bytes);
printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    
// Edge Case 18: Pointer to small address
void *ptr_15 = (void *)0x1;
printf_bytes = printf("|%p|\n", ptr_15);
ft_printf_bytes = ft_printf("|%p|\n", ptr_15);
printf("Bytes printed by or_printf: %d\n", printf_bytes);
printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    
// Edge Case 19: Pointer with mixed zero padding and width
void *ptr_16 = (void *)0xABCDEF;
printf_bytes = printf("|%15p|\n", ptr_16);
ft_printf_bytes = ft_printf("|%15p|\n", ptr_16);
printf("Bytes printed by or_printf: %d\n", printf_bytes);
printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////

printf("\033[1;33m\n ************************************************************************** \n\033[0m");
printf("\033[1;33m *************** \033[0m           hex values               \033[1;33m      **************** \033[0m\n");
 printf("\033[1;33m ************************************************************************** \n\033[0m");


// Edge Case: Precision greater than the number of digits
printf_bytes = printf("|%.10x|\n", 45);
ft_printf_bytes = ft_printf("|%.10x|\n", 45);
printf("Bytes printed by or_printf: %d\n", printf_bytes);
printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    
// Edge Case: Precision of 0 with value 0
printf_bytes = printf("|%.0x|\n", 0);
ft_printf_bytes = ft_printf("|%.0x|\n", 0);
printf("Bytes printed by or_printf: %d\n", printf_bytes);
printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    
// Edge Case: Width with zero padding
printf_bytes = printf("|%05x|\n", 45);
ft_printf_bytes = ft_printf("|%05x|\n", 45);
printf("Bytes printed by or_printf: %d\n", printf_bytes);
printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    
// Edge Case: Width with left justification
printf_bytes = printf("|%-5x|\n", 45);
ft_printf_bytes = ft_printf("|%-5x|\n", 45);
printf("Bytes printed by or_printf: %d\n", printf_bytes);
printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    


// Edge Case: Combination of width, left justification, and precision
printf_bytes = printf("|%-8.5x|\n", 45);
ft_printf_bytes = ft_printf("|%-8.5x|\n", 45);
printf("Bytes printed by or_printf: %d\n", printf_bytes);
printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    
// Edge Case: Zero value with width, precision, and #
printf_bytes = printf("|%#8.0x|\n", 0);
ft_printf_bytes = ft_printf("|%#8.0x|\n", 0);
printf("Bytes printed by or_printf: %d\n", printf_bytes);
printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    
// Edge Case: Zero value with width, precision, and left justification
printf_bytes = printf("|%-#8.0x|\n", 0);
ft_printf_bytes = ft_printf("|%-#8.0x|\n", 0);
printf("Bytes printed by or_printf: %d\n", printf_bytes);
printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    
// Edge Case: Maximum unsigned int
printf_bytes = printf("|%#x|\n", 4294967295U);
ft_printf_bytes = ft_printf("|%#x|\n", 4294967295U);
printf("Bytes printed by or_printf: %d\n", printf_bytes);
printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    
// Edge Case: Minimum non-zero value (1)
printf_bytes = printf("|%#x|\n", 1);
ft_printf_bytes = ft_printf("|%#x|\n", 1);
printf("Bytes printed by or_printf: %d\n", printf_bytes);
printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    


// Edge Case: Large number with all flags
printf_bytes = printf("|%-#20.15x|\n", 123456789);
ft_printf_bytes = ft_printf("|%-#20.15x|\n", 123456789);
printf("Bytes printed by or_printf: %d\n", printf_bytes);
printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    
// Edge Case: Precision and width with no value
printf_bytes = printf("|%10.5x|\n", 0);
ft_printf_bytes = ft_printf("|%10.5x|\n", 0);
printf("Bytes printed by or_printf: %d\n", printf_bytes);
printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    
// Edge Case: No width or precision, just value
printf_bytes = printf("|%x|\n", 12345);
ft_printf_bytes = ft_printf("|%x|\n", 12345);
printf("Bytes printed by or_printf: %d\n", printf_bytes);
printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    
// Edge Case: Uppercase %X, precision, and #
printf_bytes = printf("|%#.10X|\n", 12345);
ft_printf_bytes = ft_printf("|%#.10X|\n", 12345);
printf("Bytes printed by or_printf: %d\n", printf_bytes);
printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    
// Edge Case: Uppercase %X, width, zero padding
printf_bytes = printf("|%08X|\n", 12345);
ft_printf_bytes = ft_printf("|%08X|\n", 12345);
printf("Bytes printed by or_printf: %d\n", printf_bytes);
printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    
// Edge Case: Uppercase %X, left justification
printf_bytes = printf("|%-8X|\n", 12345);
ft_printf_bytes = ft_printf("|%-8X|\n", 12345);
printf("Bytes printed by or_printf: %d\n", printf_bytes);
printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    
// Edge Case: Precision greater than the number of digits
printf_bytes = printf("|%.10x|\n", 45);
ft_printf_bytes = ft_printf("|%.10x|\n", 45);
printf("Bytes printed by or_printf: %d\n", printf_bytes);
printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    
// Edge Case: Precision equal to the number of digits
printf_bytes = printf("|%.3x|\n", 45);
ft_printf_bytes = ft_printf("|%.3x|\n", 45);
printf("Bytes printed by or_printf: %d\n", printf_bytes);
printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    
// Edge Case: Precision less than the number of digits
printf_bytes = printf("|%.1x|\n", 45);
ft_printf_bytes = ft_printf("|%.1x|\n", 45);
printf("Bytes printed by or_printf: %d\n", printf_bytes);
printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    
// Edge Case: Width greater than the number of digits
printf_bytes = printf("|%8x|\n", 45);
ft_printf_bytes = ft_printf("|%8x|\n", 45);
printf("Bytes printed by or_printf: %d\n", printf_bytes);
printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    
// Edge Case: Width greater than the number of digits and left-justified
printf_bytes = printf("|%-8x|\n", 45);
ft_printf_bytes = ft_printf("|%-8x|\n", 45);
printf("Bytes printed by or_printf: %d\n", printf_bytes);
printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    
// Edge Case: Width and Precision together (left-justified)
printf_bytes = printf("|%-8.5x|\n", 45);
ft_printf_bytes = ft_printf("|%-8.5x|\n", 45);
printf("Bytes printed by or_printf: %d\n", printf_bytes);
printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    
// Edge Case: Width and Precision together (right-justified)
printf_bytes = printf("|%8.5x|\n", 45);
ft_printf_bytes = ft_printf("|%8.5x|\n", 45);
printf("Bytes printed by or_printf: %d\n", printf_bytes);
printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    
// Edge Case: Zero value with precision zero
printf_bytes = printf("|%.0x|\n", 0);
ft_printf_bytes = ft_printf("|%.0x|\n", 0);
printf("Bytes printed by or_printf: %d\n", printf_bytes);
printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    
// Edge Case: Zero value with width greater than zero
printf_bytes = printf("|%8x|\n", 0);
ft_printf_bytes = ft_printf("|%8x|\n", 0);
printf("Bytes printed by or_printf: %d\n", printf_bytes);
printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    
// Edge Case: Maximum width and precision with non-zero value
printf_bytes = printf("|%20.15x|\n", 987654321);
ft_printf_bytes = ft_printf("|%20.15x|\n", 987654321);
printf("Bytes printed by or_printf: %d\n", printf_bytes);
printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    
// Multiple %x specifiers in a single format string
printf_bytes = printf("|%8x|%10x|\n", 45, 255);
ft_printf_bytes = ft_printf("|%8x|%10x|\n", 45, 255);
printf("Bytes printed by or_printf: %d\n", printf_bytes);
printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    
// Multiple %x specifiers with left and right justification
printf_bytes = printf("|%-8x|%8x|\n", 45, 255);
ft_printf_bytes = ft_printf("|%-8x|%8x|\n", 45, 255);
printf("Bytes printed by or_printf: %d\n", printf_bytes);
printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    
// Edge Case: Large number with precision and width
printf_bytes = printf("|%10.8x|\n", 123456789);
ft_printf_bytes = ft_printf("|%10.8x|\n", 123456789);
printf("Bytes printed by or_printf: %d\n", printf_bytes);
printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    

/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////

printf("\033[1;33m\n ************************************************************************** \n\033[0m");
printf("\033[1;33m ***************** \033[0m           unsigned              \033[1;33m      ***************** \033[0m\n");
 printf("\033[1;33m ************************************************************************** \n\033[0m");


unsigned int large_number = 4294967295; // Maximum value for unsigned int

// Test 1: Zero Value
printf_bytes = printf("|%u| |%05u| |%-5u|\n", 0, 0, 0);
ft_printf_bytes = ft_printf("|%u| |%05u| |%-5u|\n", 0, 0, 0);
printf("Bytes printed by or_printf: %u\n", printf_bytes);
printf("Bytes printed by ft_printf: %u\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    
// Test 2: Large Positive Number
printf_bytes = printf("|%u| |%20u| |%-20u|\n", large_number, large_number, large_number);
ft_printf_bytes = ft_printf("|%u| |%20u| |%-20u|\n", large_number, large_number, large_number);
printf("Bytes printed by or_printf: %u\n", printf_bytes);
printf("Bytes printed by ft_printf: %u\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    
// Test 3: Combination of Width and Precision
printf_bytes = printf("|%10.5u| |%5.10u| |%-10.5u|\n", 123, 456, 789);
ft_printf_bytes = ft_printf("|%10.5u| |%5.10u| |%-10.5u|\n", 123, 456, 789);
printf("Bytes printed by or_printf: %u\n", printf_bytes);
printf("Bytes printed by ft_printf: %u\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    

// Test 5: Edge of Precision
printf_bytes = printf("|%.u| |%.0u| |%.3u|\n", 0, 0, 42);
ft_printf_bytes = ft_printf("|%.u| |%.0u| |%.3u|\n", 0, 0, 42);
printf("Bytes printed by or_printf: %u\n", printf_bytes);
printf("Bytes printed by ft_printf: %u\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    
// Test 8: Width Less than Number of Digits
printf_bytes = printf("|%3u| |%3.2u| |%-3u|\n", 1234, 5678, 90);
ft_printf_bytes = ft_printf("|%3u| |%3.2u| |%-3u|\n", 1234, 5678, 90);
printf("Bytes printed by or_printf: %u\n", printf_bytes);
printf("Bytes printed by ft_printf: %u\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    
// Test 9: Negative Values (Undefined Behavior)
printf_bytes = printf("|%u| |%5u| |%05u|\n", -1, -42, -999);
ft_printf_bytes = ft_printf("|%u| |%5u| |%05u|\n", -1, -42, -999);
printf("Bytes printed by or_printf: %u\n", printf_bytes);
printf("Bytes printed by ft_printf: %u\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////

printf("\033[1;33m\n ************************************************************************** \n\033[0m");
printf("\033[1;33m ************** \033[0m           string part               \033[1;33m      **************** \033[0m\n");
printf("\033[1;33m ************************************************************************** \n\033[0m");

	char *str = "Hello";
	char *empty_str = "";
	char *null_str = NULL;

	// Test 1: Basic string with left justification
	printf_bytes = printf("|%-10s|\n", str);
	ft_printf_bytes = ft_printf("|%-10s|\n", str);
	printf("Bytes printed by or_printf: %d\n", printf_bytes);
	printf("Bytes prin by ft_printf: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    
	// Test 2: Basic string with right justification
	printf_bytes = printf("|%10s|\n", str);
	ft_printf_bytes = ft_printf("|%10s|\n", str);
	printf("Bytes printed by or_printf: %d\n", printf_bytes);
	printf("Bytes prin by ft_printf: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    
	// Test 3: String with precision less than length
	printf_bytes = printf("|%.3s|\n", str);
	ft_printf_bytes = ft_printf("|%.3s|\n", str);
	printf("Bytes printed by or_printf: %d\n", printf_bytes);
	printf("Bytes prin by ft_printf: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    
	// Test 4: String with precision greater than length
	printf_bytes = printf("|%.10s|\n", str);
	ft_printf_bytes = ft_printf("|%.10s|\n", str);
	printf("Bytes printed by or_printf: %d\n", printf_bytes);
	printf("Bytes prin by ft_printf: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    
	// Test 5: String with precision and width
	printf_bytes = printf("|%10.3s|\n", str);
	ft_printf_bytes = ft_printf("|%10.3s|\n", str);
	printf("Bytes printed by or_printf: %d\n", printf_bytes);
	printf("Bytes prin by ft_printf: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    
	// Test 6: Empty string with width
	printf_bytes = printf("|%10s|\n", empty_str);
	ft_printf_bytes = ft_printf("|%10s|\n", empty_str);
	printf("Bytes printed by or_printf: %d\n", printf_bytes);
	printf("Bytes prin by ft_printf: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    
	// Test 7: Empty string with precision
	printf_bytes = printf("|%.3s|\n", empty_str);
	ft_printf_bytes = ft_printf("|%.3s|\n", empty_str);
	printf("Bytes printed by or_printf: %d\n", printf_bytes);
	printf("Bytes prin by ft_printf: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    
	// Test 8: NULL string with default behavior
	printf_bytes = printf("|%s|\n", null_str);
	ft_printf_bytes = ft_printf("|%s|\n", null_str);
	printf("Bytes printed by or_printf: %d\n", printf_bytes);
	printf("Bytes prin by ft_printf: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    
	// Test 9: NULL string with width
	printf_bytes = printf("|%10s|\n", null_str);
	ft_printf_bytes = ft_printf("|%10s|\n", null_str);
	printf("Bytes printed by or_printf: %d\n", printf_bytes);
	printf("Bytes prin by ft_printf: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    
	// Test 10: NULL string with precision
	printf_bytes = printf("|%.3s|\n", null_str);
	ft_printf_bytes = ft_printf("|%.3s|\n", null_str);
	printf("Bytes printed by or_printf: %d\n", printf_bytes);
	printf("Bytes prin by ft_printf: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    
	// Test 11: NULL string with precision and width
	printf_bytes = printf("|%10.3s|\n", null_str);
	ft_printf_bytes = ft_printf("|%10.3s|\n", null_str);
	printf("Bytes printed by or_printf: %d\n", printf_bytes);
	printf("Bytes prin by ft_printf: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");
    

    return 0;
}
