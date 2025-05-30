/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdaniel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:46:31 by tdaniel-          #+#    #+#             */
/*   Updated: 2024/11/06 13:10:47 by tdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}

/*
Difference to mapi is changes chars in place instead of creating a new str

Parameters
s: The string on which to iterate.
f: The function to apply to each character.

DESCRIPTION 
Applies the function ’f’ on each character of the string passed as 
argument, passing its index as first argument. Each character is passed
by address to ’f’ to be modified if necessary.
f (index,adress_charcter) 
*/

/*
#include <stdio.h>

//index is usefull to aply stuff as this; can also be unused
void to_uppercase(unsigned int index, char *c)
{
    if (index % 2 == 0 && *c >= 'a' && *c <= 'z') {
        *c = *c - 32;
    }
}

int main(void) {
    char str[] = "stringteri test";

    printf("original strng: %s\n", str);

    ft_striteri(str, to_uppercase);

    printf("after strng:    %s\n", str);

    return 0;
}
*/