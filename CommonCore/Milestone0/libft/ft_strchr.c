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
TLDR
Return the position if found
Return null pos if not found
Return null pos if c is a null
To be able to compare them cast c to char
*/

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c && *s != '\0')
	{
		s++;
	}
	if (*s != '\0')
	{
		return ((char *)s);
	}
	else if (*s == '\0' && 0 == (char)c)
	{
		return ((char *)s);
	}
	else
	{
		return (NULL);
	}
}

/*
DESCRIPTION
The strchr() function returns a pointer to the first occurrence
of the character c in the string s.
Here "character" means "byte"; these functions do not work with
wide or multibyte characters.

RETURN VALUE
The strchr() and strrchr() functions return a pointer to the
matched character or NULL if the character is not found.
The terminating null byte is considered part of the string, so
that if c is specified as '\0', these functions return a pointer
to the terminator.
*/
/*
#include <stdio.h>
int main() {
    const char *str = "a test for str search";
    char target = 'w';

    char *result = ft_strchr(str, target);

    if (result != NULL) {
        printf("character '%c' found at position: %ld\n", target, result - str);
    } else {
        printf("character '%c' not found in the string.\n", target);
    }

    return 0;
}
*/