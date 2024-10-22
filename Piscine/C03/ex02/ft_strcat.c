/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdaniel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:46:31 by tdaniel-          #+#    #+#             */
/*   Updated: 2024/09/14 23:17:08 by tdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	p;

	i = 0;
	p = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[p] != '\0')
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

int	main(void)
{
	char dest[90] = "testar ";
	char *src = "juntar";

	printf("%s", ft_strcat(dest, src));
	return (0);
}

*/
