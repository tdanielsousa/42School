/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdaniel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:46:31 by tdaniel-          #+#    #+#             */
/*   Updated: 2024/09/14 23:17:58 by tdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	posit1;
	unsigned int	posit2;

	posit1 = 0;
	posit2 = 0;
	while (s1[posit1] == s2[posit2] && s1[posit1] != '\0' && s2[posit2] != '\0')
	{
		posit1++;
		posit2++;
	}
	if (s1[posit1] == s2[posit2])
	{
		return (0);
	}
	else
	{
		return (s1[posit1] - s2[posit2]);
	}
}

/*
//ifs because large asci values difs caused over/underflow issues
//0, if the s1 and s2 are equal
//a negative value if s1 is less than s2
//a positive value if s1 is greater than s2

#include<stdio.h>
 
 
int     main(void)
{
        char s1[] = "teste";
        char s2[] = "teste";
 
        printf("%d", ft_strcmp(s1, s2));
        return(0);
}


*/
