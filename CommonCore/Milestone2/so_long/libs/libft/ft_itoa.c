/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdaniel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:46:31 by tdaniel-          #+#    #+#             */
/*   Updated: 2024/11/04 21:42:32 by tdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
if nr is 0 its one digit
if negative keep on more space for the - sign
keeps / until 1 digit since its not float ex 3/10 = 0
*/

static unsigned int	number_of_digits(int nb)
{
	unsigned int	length;

	length = 0;
	if (nb == 0)
	{
		length++;
		return (length);
	}
	if (nb < 0)
		length++;
	while (nb != 0)
	{
		nb /= 10;
		length++;
	}
	return (length);
}

/*
cast long because of int min and get nr of digits
if negative add -
add null at end
lenght -1 because indices start at 0
use module to keep digit
*/

char	*ft_itoa(int n)
{
	unsigned int	length;
	char			*string;
	long			num;

	num = n;
	length = number_of_digits(num);
	string = (char *)malloc(sizeof(char) * (length + 1));
	if (string == NULL)
		return (NULL);
	if (num < 0)
	{
		string[0] = '-';
		num = -num;
	}
	if (num == 0)
		string[0] = '0';
	string[length] = '\0';
	while (num != 0)
	{
		string[length - 1] = (num % 10) + '0';
		num = num / 10;
		length--;
	}
	return (string);
}

/*
#include <stdio.h>
#include <stdlib.h>

int main() 
{
    char *result;

    result = ft_itoa(0);
    printf("nr: %d, string: %s\n", 0, result);
    free(result);

    result = ft_itoa(-2147483647);
    printf("nr: %d, string: %s\n", -2147483647, result);
    free(result);

    result = ft_itoa(467856);
    printf("nr: %d, string: %s\n", 467856, result);
    free(result);

    result = ft_itoa(-1);
    printf("nr: %d, string: %s\n", -1, result);
    free(result);

    return (0);
}
*/