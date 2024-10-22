/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdaniel- <tdaniel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 12:46:31 by tdaniel-          #+#    #+#             */
/*   Updated: 2024/09/09 16:37:06 by tdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	if (size == 0)
	{
		i = 0;
		while (src[i] != '\0')
		{
			i++;
		}
		return (i);
	}
	size -= 1;
	i = 0;
	while (src[i] != '\0' && i < size)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	while (src[i] != '\0')
	{
		i++;
	}
	return (i);
}

/*
//copy only a portion of the src string to the dest buffer
//size == 0 avoids any copying when size is zero.
//counts till null 
//copy characters from src to dest while i lower than size
//null termination the destination buffer
//last while because of strlcpy specification, 
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
