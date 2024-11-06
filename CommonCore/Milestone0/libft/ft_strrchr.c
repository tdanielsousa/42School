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

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = 0;
	while (s[len])
	{
		len++;
	}
	while (len >= 0)
	{
		if ((char)c == s[len])
			return ((char *)(s + len));
		len--;
	}
	return (NULL);
}
/*
DESCRIPTION
The strrchr() function returns a pointer to the last occurrence
of the character c in the string s.

RETURN VALUE :
The strrchr() functions return a pointer to the
matched character or NULL if the character is not found.

*/

/*
#include <stddef.h>
#include <stdio.h>

int main(void)
{
    const char *str = "testing my strrchr";
    char ch = 'c';
    char *result;

    result = ft_strrchr(str, ch);
    if (result)
        printf("last occurrence of '%c' found at pos: %ld\n", ch, result - str);
    else
        printf("char '%c' not found\n", ch);

    return 0;
}
*/