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
DESCRIPTION
The memcpy() function copies n bytes from memory area src to
memory area dest
RETURN VALUE
The memcpy() function returns a pointer to dest.
void doesnt need cast
*/

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*destiny;
	const char	*source;

	destiny = dest;
	source = src;
	if (dest == src)
		return (dest);
	while (n != 0)
	{
		*destiny++ = *source++;
		n--;
	}
	return (dest);
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{ 
    const char src[] = "its my memcpy";

    char *dst = malloc(strlen(src) + 1);
    if (dst == NULL)
    {
        printf("error");
        return 1;
    }

    ft_memcpy(dst, src, strlen(src) + 1);

    printf("source:  %s\n", src);
    printf("dest:    %s\n", dst);


    free(dst);

    return 0;
}
*/