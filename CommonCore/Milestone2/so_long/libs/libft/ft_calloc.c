/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdaniel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 12:46:31 by tdaniel-          #+#    #+#             */
/*   Updated: 2024/11/04 21:44:44 by tdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
nmemb - the number of elements to allocate
size - the size of each element in bytes
nmemb * size calculates the total number of bytes to allocate
same as malloc but sets all to zero
c doesnt require malloc cast
*/

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*str;
	size_t	i;
	size_t	total_bytes;

	total_bytes = nmemb * size;
	i = 0;
	str = malloc(total_bytes);
	if (str == 0)
		return (NULL);
	while (i < total_bytes)
	{
		str[i] = 0;
		i++;
	}
	return (str);
}
/*

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) 
{

    char *str = (char *)ft_calloc(6, sizeof(char));
    if (str == NULL) 
	{
        return (1); 
    }

    strcpy(str, "Hello");

    printf("%s\n", str);

    free(str);

    return 0;
}
*/
