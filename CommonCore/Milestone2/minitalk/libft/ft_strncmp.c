/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdaniel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:46:31 by tdaniel-          #+#    #+#             */
/*   Updated: 2024/11/06 13:14:18 by tdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] != '\0' && s2[i] != '\0' && i < n -1 && s1[i] == s2[i])
	{
		i++;
	}
	if (s1[i] == s2[i])
	{
		return (0);
	}
	else
	{
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
}

/*
cast to fix non ascii values

Description
The strcmp() function compares the two strings s1 and s2. It returns an integer
less than, equal to, or greater than zero if s1 is found, respectively, to be 
less than, to match, or be greater than s2.
The strncmp() function is similar, except it only
compares the first (at most) n bytes of s1 and s2.

Return Value
The strcmp() and strncmp() functions return an integer less than,
equal to, or greater than zeroif s1  (or the first n bytes thereof) is found,
respectively, to be less than, to match, or be greater than s2.
*/

/*
#include<stdio.h>
 
 
int     main(void)
{
        int n;
        n = 3;
        char s1[] = "testee";
        char s2[] = "testeee";
 
        printf("%d", ft_strncmp(s1, s2,n));
        return(0);
}
*/