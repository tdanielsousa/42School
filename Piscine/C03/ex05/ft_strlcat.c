/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdaniel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:46:31 by tdaniel-          #+#    #+#             */
/*   Updated: 2024/09/12 08:51:58 by tdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	res;

	i = 0;
	j = 0;
	res = 0;
	while (dest[i] != '\0')
		i++;
	while (src[res] != '\0')
	{
		res++;
	}
	if (size <= i)
		res += size;
	else
		res += i;
	while (src[j] != '\0' && (i + 1) < size)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (res);
}

/*
//1st while with i calculate length of dest string i is length of dest str
//res is the lengt of source string kinda same as above
//j to reset index 0 and copy chars to the dest string from i (already at end)
//i+1 to overwrite null terminator
//runs untill src string is reached or the result string would exceed the size
//checks if we have room to do dest + origin otherwise adds to dest the size 
//we recieve to increase size to prevent the overflowsss error

#include<stdio.h>


int	main(void)
{
	char dest[90] = "testar";
	char src[90] = "juntarr";
	unsigned int	n = 50;

int	ret = ft_strlcat(dest, src, n);
	printf("%u %s\n", ret, dest);
	
	return (0);
}
*/
