/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdaniel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:46:31 by tdaniel-          #+#    #+#             */
/*   Updated: 2025/01/19 08:57:42 by tdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
cc main.c libftprintf.a
*/

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int	ft_printf(const char *format, ...);

// Conversion function prototypes
int	ft_print_char(int c);
int	ft_print_string(char *str);
int	ft_print_decimal(int n);
int	ft_print_unsigned(unsigned int n);
int	ft_print_hex(unsigned long nb, const char form);
int	ft_print_pointer(unsigned long pointer);
int	ft_print_percent(void);

int main()
{
    int printf_bytes, ft_printf_bytes;

    // *************************************************************
    // **               Character (c) Tests                     **
    // *************************************************************

    printf("\033[1;33m\n ************************************************************************** \n\033[0m");
    printf("\033[1;33m **************** \033[0m           character               \033[1;33m      **************** \033[0m\n");
    printf("\033[1;33m ************************************************************************** \n\033[0m");

    // Test 1: Basic character
    char ch = 'A';
    printf_bytes = printf("|%c|\n", ch);
    ft_printf_bytes = ft_printf("|%c|\n", ch);
    printf("Bytes printed by or_printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");

    // *************************************************************
    // **               String (s) Tests                        **
    // *************************************************************

    printf("\033[1;33m\n ************************************************************************** \n\033[0m");
    printf("\033[1;33m *************** \033[0m           string                 \033[1;33m      ****************** \033[0m\n");
    printf("\033[1;33m ************************************************************************** \n\033[0m");

    // Test 1: String w
    char *str = "Hello testing";
    printf_bytes = printf("|%s|\n", str);
    ft_printf_bytes = ft_printf("|%s|\n", str);
    printf("Bytes printed by or_printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");


    // *************************************************************
    // **               Pointer (p) Tests                       **
    // *************************************************************

    printf("\033[1;33m\n ************************************************************************** \n\033[0m");
    printf("\033[1;33m *************** \033[0m           pointer                \033[1;33m      ****************** \033[0m\n");
    printf("\033[1;33m ************************************************************************** \n\033[0m");

    // Test 1: NULL pointer
    void *ptr = NULL;
    printf_bytes = printf("|%p|\n", ptr);
    ft_printf_bytes = ft_printf("|%p|\n", ptr);
    printf("Bytes printed by or_printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");

    // *************************************************************
    // **               Decimal (d) / Integer (i) Tests          **
    // *************************************************************

    printf("\033[1;33m\n ************************************************************************** \n\033[0m");
    printf("\033[1;33m **************** \033[0m           decimal/integer        \033[1;33m      ***************** \033[0m\n");
    printf("\033[1;33m ************************************************************************** \n\033[0m");

    // Test 1: Decimal positive number
    printf_bytes = printf("|%d|\n", 42);
    ft_printf_bytes = ft_printf("|%d|\n", 42);
    printf("Bytes printed by or_printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");

    // Test 2: Decimal negative number
    printf_bytes = printf("|%d|\n", -42);
    ft_printf_bytes = ft_printf("|%d|\n", -42);
    printf("Bytes printed by or_printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");

    // *************************************************************
    // **               Unsigned (u) Tests                      **
    // *************************************************************

    printf("\033[1;33m\n ************************************************************************** \n\033[0m");
    printf("\033[1;33m **************** \033[0m           unsigned               \033[1;33m      ***************** \033[0m\n");
    printf("\033[1;33m ************************************************************************** \n\033[0m");

    // Test 1: Unsigned value
    unsigned int u_val = 4294967295;
    printf_bytes = printf("|%u|\n", u_val);
    ft_printf_bytes = ft_printf("|%u|\n", u_val);
    printf("Bytes printed by or_printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");

    // Test 2: Unsigned zero
    printf_bytes = printf("|%u|\n", 0);
    ft_printf_bytes = ft_printf("|%u|\n", 0);
    printf("Bytes printed by or_printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");

    // *************************************************************
    // **               Hexadecimal (x) Tests                   **
    // *************************************************************

    printf("\033[1;33m\n ************************************************************************** \n\033[0m");
    printf("\033[1;33m **************** \033[0m           hex (lowercase)        \033[1;33m      ***************** \033[0m\n");
    printf("\033[1;33m ************************************************************************** \n\033[0m");

    // Test 1: Hexadecimal (lowercase)
    printf_bytes = printf("|%x|\n", 255);
    ft_printf_bytes = ft_printf("|%x|\n", 255);
    printf("Bytes printed by or_printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");

    // *************************************************************
    // **               Hexadecimal (X) Tests                   **
    // *************************************************************

    printf("\033[1;33m\n ************************************************************************** \n\033[0m");
    printf("\033[1;33m *************** \033[0m           hex (uppercase)        \033[1;33m      ****************** \033[0m\n");
    printf("\033[1;33m ************************************************************************** \n\033[0m");

    // Test 1: Hexadecimal (uppercase)
    printf_bytes = printf("|%X|\n", 255);
    ft_printf_bytes = ft_printf("|%X|\n", 255);
    printf("Bytes printed by or_printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");

    // *************************************************************
    // **               Percent (%) Tests                       **
    // *************************************************************

    printf("\033[1;33m\n ************************************************************************** \n\033[0m");
    printf("\033[1;33m ****************** \033[0m           percent             \033[1;33m      ****************** \033[0m\n");
    printf("\033[1;33m ************************************************************************** \n\033[0m");

    // Test 1: Percent sign
    printf_bytes = printf("|%%|\n");
    ft_printf_bytes = ft_printf("|%%|\n");
    printf("Bytes printed by or_printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);
    if (printf_bytes == ft_printf_bytes)
        printf("\033[32m ************* OK *************  \033[0m\n");
    else
        printf("\033[31m ************* NO *************  \033[0m\n");
    printf("\n");

    return 0;
}
