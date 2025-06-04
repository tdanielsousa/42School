/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdaniel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:46:31 by tdaniel-          #+#    #+#             */
/*   Updated: 2024/11/06 13:46:27 by tdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Description
ft_strnstr searches for the first occurrence of the substring little in the
string big, but only within the first len characters of big.
If little is an empty string, it returns big. 
If little is not found within len characters, it returns NULL.
RETURN VALUES
If little is an empty string, big is returned; if little occurs nowhere
in big, NULL is returned; otherwise a pointer to the first character of
the first occurrence of little is returned.
While with 2 vars to cycle trough little and big and check if full 
substring is present
*/

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (little[0] == '\0')
	{
		return ((char *)big);
	}
	i = 0;
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && (i + j) < len)
		{
			if (little[j + 1] == '\0')
			{
				return ((char *)big + i);
			}
			j++;
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
    const char *big = "i want to test if my strnstr finds this here";
    const char *little = "io";
    size_t len = 30; 

    char *result = ft_strnstr(big, little, len);

    if (result)
        printf("found '%s' in the string\n", little);
    else
        printf("'%s' not found within the first %zu chars\n", little, len);

    return 0;
}
*/
