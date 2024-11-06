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
destiny > source to check positions in memory because
memmove supports overlapping
so it checks and it copies to the left, (backwards)
or in the next block of code it copies into the right (front)
*/

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*destiny;
	const unsigned char	*source;
	size_t				i;

	if (!dest && !src)
		return (NULL);
	destiny = (unsigned char *)dest;
	source = (const unsigned char *)src;
	if (destiny > source)
	{
		while (n > 0)
		{
			n--;
			destiny[n] = source[n];
		}
		return (dest);
	}
	i = 0;
	while (i < n)
	{
		destiny[i] = source[i];
		i++;
	}
	return (dest);
}
/*
DESCRIPTION
The memmove() function copies n bytes from memory area src to
memory area dest.  
RETURN VALUE
The memmove() function returns a pointer to dest.
*/

/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char str[] = "lets test";
	
	ft_memmove(str, str + 5, 4);
	printf("\nft_memmove with overlap:\n");
	printf("dest = %s\n", str);


	char src[] = "test";
	char dest[5];

	ft_memmove(dest, src, 5);

	printf("\nft_memmove no overlap:\n");
	printf("src  = %s\n", src);
	printf("dest = %s\n", dest);

	return 0;
}
*/