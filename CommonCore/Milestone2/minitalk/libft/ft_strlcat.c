/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdaniel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:46:31 by tdaniel-          #+#    #+#             */
/*   Updated: 2024/11/05 18:46:31 by tdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	total_len;

	i = 0;
	j = 0;
	total_len = 0;
	while (dst[i] != '\0')
		i++;
	while (src[total_len] != '\0')
	{
		total_len++;
	}
	if (size <= i)
		total_len += size;
	else
		total_len += i;
	while (src[j] != '\0' && (i + 1) < size)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (total_len);
}

/*
Almost same as strjoin but only copies if size > dst
DESCRIPTION
Strlcat guarantees to NUL-terminate the result (as long as size is larger than 0 
or, in the case of strlcat(), as long as there is at least one byte free in dst)
Note that a byte for the NUL should be included in size.
strlcat() both src and dst must be NUL-terminated.
The strlcat() function appends the NUL-terminated string src to the end of dst. 
RETURN
Strlcat() functions return the total length of the string they tried to create.
For strlcat() that means the initial length of dst plus the length of src.
Note, however, that if strlcat() traverses size characters without finding a NUL,
the length of the string is considered to be size and the destination string 
will not be NUL-terminated (since there was no space for the NUL).
*/

/*
#include<stdio.h>
int	main(void)
{
	char dst[20] = "testar";
	char src[20] = "juntarr";
	unsigned int	n = 14;

  int	ret = ft_strlcat(dst, src, n);
	printf("returned len: %u \nstring: %s\n", ret, dst);

	return (0);
}
*/