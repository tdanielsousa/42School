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
erases data in n bytes of the memory starting at the location pointed to by s
by writing zeros (bytes containing '\0') to that area
used to initialize a memory block to zero
char buffer[10];
ft_bzero(buffer, sizeof(buffer));
now buffer contains all zero bytes
accessing memory byte by byte requires a pointer of type char* or unsign
*/

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*setzero;

	i = 0;
	setzero = (unsigned char *)s;
	while (i < n)
	{
		setzero[i] = 0;
		i++;
	}
}
/*
#include <stddef.h>
#include <stdio.h>

int main()
{
    char buffer[10] = "Test12345"; 

    printf("Before ft_bzero: %s\n", buffer);

    ft_bzero(buffer, 10);

    printf("After ft_bzero: %s\n", buffer);

    return 0;
}
*/