/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdaniel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 12:46:31 by tdaniel-          #+#    #+#             */
/*   Updated: 2024/11/05 17:21:13 by tdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
DESCRIPTION
The strdup() function returns a pointer to a new string which is
a duplicate of the string s.
RETURN VALUE
The strdup() function returns a pointer to the duplicated string.
*/

char	*ft_strdup(const char *s)
{
	int		len_to_alocate;
	int		i;
	char	*dest;

	len_to_alocate = 0;
	while (s[len_to_alocate] != '\0')
	{
		len_to_alocate++;
	}
	dest = malloc(sizeof(char) * (len_to_alocate + 1));
	if (dest == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (s[i] != '\0')
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
#include <stdio.h>
int main(void)
{
    char    *str;
    char    *new_str;

    str = "copying a strng";
    new_str = ft_strdup(str);

    if (new_str == NULL) {
        printf("mem allocation fail\n");
        return 1;
    }

    printf("new one:  %s\n", new_str);

    free(new_str);

    return 0;
}
*/