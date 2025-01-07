/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdaniel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:46:31 by tdaniel-          #+#    #+#             */
/*   Updated: 2025/01/07 14:29:54 by tdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

# include <stdio.h>

int main()
{
  int printf_bytes, ft_printf_bytes;

  // Test 1: Char (positive case)
    printf_bytes = printf("Test 1: |%c|\n", 'A');
    ft_printf_bytes = ft_printf("Test 1: |%c|\n", 'A');
    printf("Bytes printed by printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);

    // Test 2: Char (null char)
    printf_bytes = printf("Test 2: |%c|\n", '\0');
    ft_printf_bytes = ft_printf("Test 2: |%c|\n", '\0');
    printf("Bytes printed by printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);

    // Test 3: String (normal string)
    printf_bytes = printf("Test 3: |%s|\n", "Hello, World!");
    ft_printf_bytes = ft_printf("Test 3: |%s|\n", "Hello, World!");
    printf("Bytes printed by printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);

    // Test 4: String (empty string)
    printf_bytes = printf("Test 4: |%s|\n", "");
    ft_printf_bytes = ft_printf("Test 4: |%s|\n", "");
    printf("Bytes printed by printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);

    // Test 5: String (NULL string)
    printf_bytes = printf("Test 5: |%s|\n", NULL);
    ft_printf_bytes = ft_printf("Test 5: |%s|\n", NULL);
    printf("Bytes printed by printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);

    // Test 6: Pointer (valid pointer)
    int a = 42;
    printf_bytes = printf("Test 6: |%p|\n", &a);
    ft_printf_bytes = ft_printf("Test 6: |%p|\n", &a);
    printf("Bytes printed by printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);

    // Test 7: Pointer (NULL pointer)
    printf_bytes = printf("Test 7: |%p|\n", NULL);
    ft_printf_bytes = ft_printf("Test 7: |%p|\n", NULL);
    printf("Bytes printed by printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);

    // Test 8: Signed decimal integer (positive number)
    printf_bytes = printf("Test 8: |%d|\n", 123);
    ft_printf_bytes = ft_printf("Test 8: |%d|\n", 123);
    printf("Bytes printed by printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);

    // Test 9: Signed decimal integer (negative number)
    printf_bytes = printf("Test 9: |%d|\n", -123);
    ft_printf_bytes = ft_printf("Test 9: |%d|\n", -123);
    printf("Bytes printed by printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);

    // Test 10: Signed decimal integer (zero)
    printf_bytes = printf("Test 10: |%d|\n", 0);
    ft_printf_bytes = ft_printf("Test 10: |%d|\n", 0);
    printf("Bytes printed by printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);

    // Test 11: Unsigned decimal integer
    printf_bytes = printf("Test 11: |%u|\n", 123456789);
    ft_printf_bytes = ft_printf("Test 11: |%u|\n", 123456789);
    printf("Bytes printed by printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);

    // Test 12: Unsigned decimal integer (zero)
    printf_bytes = printf("Test 12: |%u|\n", 0);
    ft_printf_bytes = ft_printf("Test 12: |%u|\n", 0);
    printf("Bytes printed by printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);

    // Test 13: Hexadecimal integer (lowercase)
    printf_bytes = printf("Test 13: |%x|\n", 0xabcdef);
    ft_printf_bytes = ft_printf("Test 13: |%x|\n", 0xabcdef);
    printf("Bytes printed by printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);

    // Test 14: Hexadecimal integer (uppercase)
    printf_bytes = printf("Test 14: |%X|\n", 0xABCDEF);
    ft_printf_bytes = ft_printf("Test 14: |%X|\n", 0xABCDEF);
    printf("Bytes printed by printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);

    // Test 15: Hexadecimal integer (zero)
    printf_bytes = printf("Test 15: |%x|\n", 0);
    ft_printf_bytes = ft_printf("Test 15: |%x|\n", 0);
    printf("Bytes printed by printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);

    // Test 16: Percent sign
    printf_bytes = printf("Test 16: |%%|\n");
    ft_printf_bytes = ft_printf("Test 16: |%%|\n");
    printf("Bytes printed by printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);

    // Test 17: Smallest integer for signed decimal (%d)
    printf_bytes = printf("Test 17: |%d|\n", -2147483648);
    ft_printf_bytes = ft_printf("Test 17: |%d|\n", -2147483648);
    printf("Bytes printed by printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);

    // Test 18: Largest integer for signed decimal (%d)
    printf_bytes = printf("Test 18: |%d|\n", 2147483647);
    ft_printf_bytes = ft_printf("Test 18: |%d|\n", 2147483647);
    printf("Bytes printed by printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);

    // Test 19: Smallest integer for unsigned decimal (%u)
    printf_bytes = printf("Test 19: |%u|\n", 0);
    ft_printf_bytes = ft_printf("Test 19: |%u|\n", 0);
    printf("Bytes printed by printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);

    // Test 20: Largest integer for unsigned decimal (%u)
    printf_bytes = printf("Test 20: |%u|\n", 4294967295);
    ft_printf_bytes = ft_printf("Test 20: |%u|\n", 4294967295);
    printf("Bytes printed by printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);

    // Test 21: Smallest integer for hexadecimal (%x)
    printf_bytes = printf("Test 21: |%x|\n", 0);
    ft_printf_bytes = ft_printf("Test 21: |%x|\n", 0);
    printf("Bytes printed by printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);

    // Test 22: Largest integer for hexadecimal (lowercase %x)
    printf_bytes = printf("Test 22: |%x|\n", 4294967295);
    ft_printf_bytes = ft_printf("Test 22: |%x|\n", 4294967295);
    printf("Bytes printed by printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);

    // Test 23: Largest integer for hexadecimal (uppercase %X)
    printf_bytes = printf("Test 23: |%X|\n", 4294967295);
    ft_printf_bytes = ft_printf("Test 23: |%X|\n", 4294967295);
    printf("Bytes printed by printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);

    // Test 24: NULL pointer for %p
    printf_bytes = printf("Test 24: |%p|\n", NULL);
    ft_printf_bytes = ft_printf("Test 24: |%p|\n", NULL);
    printf("Bytes printed by printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);

    // Test 25: Empty string for %s
    printf_bytes = printf("Test 25: |%s|\n", "");
    ft_printf_bytes = ft_printf("Test 25: |%s|\n", "");
    printf("Bytes printed by printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);

    // Test 26: NULL string for %s
    printf_bytes = printf("Test 26: |%s|\n", NULL);
    ft_printf_bytes = ft_printf("Test 26: |%s|\n", NULL);
    printf("Bytes printed by printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);

    // Test 27: Smallest char for %c
    printf_bytes = printf("Test 27: |%c|\n", '\0');
    ft_printf_bytes = ft_printf("Test 27: |%c|\n", '\0');
    printf("Bytes printed by printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);


    return 0;
}
