/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdaniel- <tdaniel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:46:31 by tdaniel-          #+#    #+#             */
/*   Updated: 2024/10/22 16:23:36 by tdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
The function ft_memchr finds the first occurence of character c in pointer s. 
Both c and the bytes of the memory area pointed
to by s are interpreted as unsigned char
RETURN VALUE :
A pointer to the first occurence of c in s.
NULL if c is not found.
s the pointer
c the char
n the nr of bytes to search
return the adress with &
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*string;
	size_t			i;

	string = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (string[i] == (unsigned char) c)
		{
			return (&string[i]);
		}
		i++;
	}
	return (NULL);
}

/*
#include <stddef.h>
#include <stdio.h>

int main(void)
{
    const char str[] = "lets test this";
    char ch = 'i';
    size_t len = 14;

    char *result = (char *)ft_memchr(str, ch, len);

    if (result != NULL)
        printf("char '%c' found at position: %ld\n", ch, result - str);
    else
        printf("char '%c' not found\n", ch);

    return 0;
}
*/