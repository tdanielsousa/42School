/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdaniel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 12:46:31 by tdaniel-          #+#    #+#             */
/*   Updated: 2024/11/05 18:46:43 by tdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	src_length;

	src_length = 0;
	while (src[src_length] != '\0')
	{
		src_length++;
	}
	if (size == 0)
	{
		return (src_length);
	}
	i = 0;
	while (src[i] != '\0' && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_length);
}

/*
//copy only a portion of the src string to the dest buffer
//size == 0 avoids any copying when size is zero.
//null termination the destination buffer
//last while because of strlcpy specification returning
//calculating and returning the full length of src is necessary
 
 #include <stdio.h>
 
int main() {
    char src[] = "testing my print";
    char dest[6];
    //small buffer testng

    unsigned int result; //no neg values
    result = ft_strlcpy(dest, src, sizeof(dest));

    printf("copied %s\n", dest);
    printf("total original length %u\n", result);

    return 0;
}
*/
