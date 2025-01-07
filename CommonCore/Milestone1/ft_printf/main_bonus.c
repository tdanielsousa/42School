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

#include "ft_printf_bonus.h"

# include <stdio.h>

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

    // Test 0: Test with width and zero padding, positive number
    printf_bytes = printf("Hello World |%+05d|teste\n", 1);
    ft_printf_bytes = ft_printf("Hello World |%+05d|teste\n", 1);
    printf("Bytes printed by printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);

    // Test 1: Test with width and zero padding, positive number
    printf_bytes = printf("Test 1: |%05d|\n", 42);
    ft_printf_bytes = ft_printf("Test 1: |%05d|\n", 42);
    printf("Bytes printed by printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);

    // Test 2: Test with width and zero padding, negative number
    printf_bytes = printf("Test 2: |%05d|\n", -42);
    ft_printf_bytes = ft_printf("Test 2: |%05d|\n", -42);
    printf("Bytes printed by printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);

    // Test 3: Test with precision and no width
    printf_bytes = printf("Test 3: |%.5d|\n", 42);
    ft_printf_bytes = ft_printf("Test 3: |%.5d|\n", 42);
    printf("Bytes printed by printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);

    // Test 4: Test with precision and width, no zero padding
    printf_bytes = printf("Test 4: |%10.5d|\n", 42);
    ft_printf_bytes = ft_printf("Test 4: |%10.5d|\n", 42);
    printf("Bytes printed by printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);

    // Test 5: Test with precision, width, and zero padding
    printf_bytes = printf("Test 5: |%010.5d|\n", 42);
    ft_printf_bytes = ft_printf("Test 5: |%010.5d|\n", 42);
    printf("Bytes printed by printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);

    // Test 6: Test with precision, width, zero padding, and negative number
    printf_bytes = printf("Test 6: |%010.5d|\n", -42);
    ft_printf_bytes = ft_printf("Test 6: |%010.5d|\n", -42);
    printf("Bytes printed by printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);

    // Test 7: Test with width and positive sign
    printf_bytes = printf("Test 7: |%+5d|\n", 42);
    ft_printf_bytes = ft_printf("Test 7: |%+5d|\n", 42);
    printf("Bytes printed by printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);

    // Test 8: Test with width, zero padding, and positive sign
    printf_bytes = printf("Test 8: |%+05d|\n", 42);
    ft_printf_bytes = ft_printf("Test 8: |%+05d|\n", 42);
    printf("Bytes printed by printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);

    // Test 9: Test with precision, width, and positive sign
    printf_bytes = printf("Test 9: |%+10.5d|\n", 42);
    ft_printf_bytes = ft_printf("Test 9: |%+10.5d|\n", 42);
    printf("Bytes printed by printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);

    // Test 10: Test with space flag, positive number
    printf_bytes = printf("Test 10: |% 5d|\n", 42);
    ft_printf_bytes = ft_printf("Test 10: |% 5d|\n", 42);
    printf("Bytes printed by printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);

    // Test 11: Test with space flag, negative number
    printf_bytes = printf("Test 11: |% 5d|\n", -42);
    ft_printf_bytes = ft_printf("Test 11: |% 5d|\n", -42);
    printf("Bytes printed by printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);

    // Test 12: Test with space flag and zero padding
    printf_bytes = printf("Test 12: |% 05d|\n", 42);
    ft_printf_bytes = ft_printf("Test 12: |% 05d|\n", 42);
    printf("Bytes printed by printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);

    // Test 13: Test with left justification and width
    printf_bytes = printf("Test 13: |%-5d|\n", 42);
    ft_printf_bytes = ft_printf("Test 13: |%-5d|\n", 42);
    printf("Bytes printed by printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);

    // Test 14: Test with left justification, width, and precision
    printf_bytes = printf("Test 14: |%-10.5d|\n", 42);
    ft_printf_bytes = ft_printf("Test 14: |%-10.5d|\n", 42);
    printf("Bytes printed by printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);

    // Test 15: Test with left justification, width, and negative number
    printf_bytes = printf("Test 15: |%-10d|\n", -42);
    ft_printf_bytes = ft_printf("Test 15: |%-10d|\n", -42);
    printf("Bytes printed by printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);

    // Test 16: Test with zero padding and width larger than number
    printf_bytes = printf("Test 16: |%010d|\n", 1234);
    ft_printf_bytes = ft_printf("Test 16: |%010d|\n", 1234);
    printf("Bytes printed by printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);

    // Test 17: Test with zero padding, width, and precision
    printf_bytes = printf("Test 17: |%010.5d|\n", 1234);
    ft_printf_bytes = ft_printf("Test 17: |%010.5d|\n", 1234);
    printf("Bytes printed by printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);

    // Test 18: Test with zero padding and precision only
    printf_bytes = printf("Test 18: |%.5d|\n", 1234);
    ft_printf_bytes = ft_printf("Test 18: |%.5d|\n", 1234);
    printf("Bytes printed by printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);

    // Test 19: Test with width smaller than number, no flags
    printf_bytes = printf("Test 19: |%2d|\n", 12345);
    ft_printf_bytes = ft_printf("Test 19: |%2d|\n", 12345);
    printf("Bytes printed by printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);

    // Test 20: Test with precision smaller than number
    printf_bytes = printf("Test 20: |%.3d|\n", 12345);
    ft_printf_bytes = ft_printf("Test 20: |%.3d|\n", 12345);
    printf("Bytes printed by printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);

    // Test 21: Test with precision equal to number size
    printf_bytes = printf("Test 21: |%.5d|\n", 12345);
    ft_printf_bytes = ft_printf("Test 21: |%.5d|\n", 12345);
    printf("Bytes printed by printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);

    // Test 22: Test with width and precision larger than number
    printf_bytes = printf("Test 22: |%10.8d|\n", 123);
    ft_printf_bytes = ft_printf("Test 22: |%10.8d|\n", 123);
    printf("Bytes printed by printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);

    // Test 23: Test with width and precision equal to each other
    printf_bytes = printf("Test 23: |%8.8d|\n", 123);
    ft_printf_bytes = ft_printf("Test 23: |%8.8d|\n", 123);
    printf("Bytes printed by printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);

    // Test 24: Test with negative number, width, and precision
    printf_bytes = printf("Test 24: |%10.5d|\n", -123);
    ft_printf_bytes = ft_printf("Test 24: |%10.5d|\n", -123);
    printf("Bytes printed by printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);

    // Test 25: Test with zero padding, width, and negative number
    printf_bytes = printf("Test 25: |%010d|\n", -123);
    ft_printf_bytes = ft_printf("Test 25: |%010d|\n", -123);
    printf("Bytes printed by printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);

    // Test 26: Test with zero padding and precision larger than number
    printf_bytes = printf("Test 26: |%010.8d|\n", 123);
    ft_printf_bytes = ft_printf("Test 26: |%010.8d|\n", 123);
    printf("Bytes printed by printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);

    // Test 27: Test with space flag and negative number
    printf_bytes = printf("Test 27: |% 10d|\n", -123);
    ft_printf_bytes = ft_printf("Test 27: |% 10d|\n", -123);
    printf("Bytes printed by printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);

    // Test 28: Test with left justification, precision, and zero padding
    printf_bytes = printf("Test 28: |%-010.5d|\n", 123);
    ft_printf_bytes = ft_printf("Test 28: |%-010.5d|\n", 123);
    printf("Bytes printed by printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);

 printf("*******************************************************\n");

    // Test 29: Test with width and zero padding, positive number
    printf_bytes = printf("Test 29: |%05d|\n", 42);
    ft_printf_bytes = ft_printf("Test 29: |%05d|\n", 42);
    printf("Bytes printed by printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);

    // Test 30: Test with width and zero padding, negative number
    printf_bytes = printf("Test 30: |%05d|\n", -42);
    ft_printf_bytes = ft_printf("Test 30: |%05d|\n", -42);
    printf("Bytes printed by printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);

    // Test 31: Test with width, no padding, positive number
    printf_bytes = printf("Test 31: |%5d|\n", 42);
    ft_printf_bytes = ft_printf("Test 31: |%5d|\n", 42);
    printf("Bytes printed by printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);

    // Test 32: Test with width, no padding, negative number
    printf_bytes = printf("Test 32: |%5d|\n", -42);
    ft_printf_bytes = ft_printf("Test 32: |%5d|\n", -42);
    printf("Bytes printed by printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);

    // Test 33: Test with precision, positive number
    printf_bytes = printf("Test 33: |%.5d|\n", 42);
    ft_printf_bytes = ft_printf("Test 33: |%.5d|\n", 42);
    printf("Bytes printed by printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);

    // Test 34: Test with precision, negative number
    printf_bytes = printf("Test 34: |%.5d|\n", -42);
    ft_printf_bytes = ft_printf("Test 34: |%.5d|\n", -42);
    printf("Bytes printed by printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);

    // Test 35: Test with precision and width, positive number
    printf_bytes = printf("Test 35: |%8.5d|\n", 42);
    ft_printf_bytes = ft_printf("Test 35: |%8.5d|\n", 42);
    printf("Bytes printed by printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);

    // Test 36: Test with precision and width, negative number
    printf_bytes = printf("Test 36: |%8.5d|\n", -42);
    ft_printf_bytes = ft_printf("Test 36: |%8.5d|\n", -42);
    printf("Bytes printed by printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);

    // Test 37: Test with width smaller than number of digits, positive number
    printf_bytes = printf("Test 37: |%2d|\n", 12345);
    ft_printf_bytes = ft_printf("Test 37: |%2d|\n", 12345);
    printf("Bytes printed by printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);

    // Test 38: Test with width smaller than number of digits, negative number
    printf_bytes = printf("Test 38: |%2d|\n", -12345);
    ft_printf_bytes = ft_printf("Test 38: |%2d|\n", -12345);
    printf("Bytes printed by printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);

    // Test 39: Test with zero padding and precision, positive number
    printf_bytes = printf("Test 39: |%08.5d|\n", 42);
    ft_printf_bytes = ft_printf("Test 39: |%08.5d|\n", 42);
    printf("Bytes printed by printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);

    // Test 40: Test with zero padding and precision, negative number
    printf_bytes = printf("Test 40: |%08.5d|\n", -42);
    ft_printf_bytes = ft_printf("Test 40: |%08.5d|\n", -42);
    printf("Bytes printed by printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);

    // Test 41: Test with width, precision zero, and zero number
    printf_bytes = printf("Test 41: |%5.0d|\n", 0);
    ft_printf_bytes = ft_printf("Test 41: |%5.0d|\n", 0);
    printf("Bytes printed by printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);

    // Test 42: Test with width and precision, number zero
    printf_bytes = printf("Test 42: |%5.3d|\n", 0);
    ft_printf_bytes = ft_printf("Test 42: |%5.3d|\n", 0);
    printf("Bytes printed by printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);

    // Test 43: Test negative number with large width and precision
    printf_bytes = printf("Test 43: |%15.10d|\n", -123);
    ft_printf_bytes = ft_printf("Test 43: |%15.10d|\n", -123);
    printf("Bytes printed by printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);

    // Test 44: Test positive number with large width and precision
    printf_bytes = printf("Test 44: |%15.10d|\n", 123);
    ft_printf_bytes = ft_printf("Test 44: |%15.10d|\n", 123);
    printf("Bytes printed by printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);

    // Test 45: Test number zero with no width and precision zero
    printf_bytes = printf("Test 45: |%.0d|\n", 0);
    ft_printf_bytes = ft_printf("Test 45: |%.0d|\n", 0);
    printf("Bytes printed by printf: %d\n", printf_bytes);
    printf("Bytes printed by ft_printf: %d\n", ft_printf_bytes);

    return 0;
}
