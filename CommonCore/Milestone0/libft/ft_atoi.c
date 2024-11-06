/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdaniel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:46:31 by tdaniel-          #+#    #+#             */
/*   Updated: 2024/11/04 21:37:25 by tdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
skip whitespaces the same as isspace 
check for + and - 1x time unlike piscine
1 neutral for *
*/

int	ft_atoi(const char *nptr)
{
	int	i;
	int	signal;
	int	count;

	i = 0;
	signal = 1;
	count = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			signal *= -1;
		i++;
	}
	while ((nptr[i] >= '0' && nptr[i] <= '9') && nptr[i] != '\0')
	{
		count *= 10;
		count += nptr[i] - '0';
		i++;
	}
	count *= signal;
	return (count);
}
/*
#include <stdio.h>
int main(void) {
    
    //const char *nptr = "+--20";
    const char *nptr = "+200";
    //const char *nptr = "-2147483648";
    printf("%d",ft_atoi(nptr));
    return 0;
}
*/
