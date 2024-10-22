/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdaniel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:46:31 by tdaniel-          #+#    #+#             */
/*   Updated: 2024/09/14 23:15:49 by tdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	p;

	i = 0;
	while (dest[i])
	{
		i++;
	}
	p = 0;
	while (src[p] != '\0' && p < nb)
	{
		dest[i] = src[p];
		i++;
		p++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
#include<stdio.h>
#include<string.h>
int	main(void)
{
	char dest[50] = "I love: ";
	char src[] = "chopin and mahler s2";
	unsigned int	n = 19;
	
	printf("%s", ft_strncat(dest, src, n));
	return (0);
}
*/
