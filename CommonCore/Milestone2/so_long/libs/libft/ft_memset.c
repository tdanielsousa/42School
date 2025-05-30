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
The memset() function fills the first n bytes of the memory area
pointed to by s with the constant byte c.
RETURN VALUE
The memset() function returns a pointer to the memory area s.
Use to_copy to cast
*/

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*to_copy;

	i = 0;
	to_copy = (unsigned char *)s;
	while (i < n)
	{
		to_copy[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
/*
#include <stdio.h>
int main()
{
	char str[20];

	ft_memset(str, 'A', 19);
	str[19] = '\0';

	printf("result of ft_memset: %s\n", str);

	ft_memset(str, 'c', 5);
	printf("result aafter ft_memset: %s\n", str);

	return 0;
}
*/