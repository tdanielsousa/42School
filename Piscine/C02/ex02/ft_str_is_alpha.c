/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdaniel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 12:46:31 by tdaniel-          #+#    #+#             */
/*   Updated: 2024/09/12 09:38:03 by tdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	while (*str != '\0')
	{
		if ((*str < 'A' || *str > 'Z') && (*str < 'a' || *str > 'z'))
		{
			return (0);
		}
		str++;
	}
	return (1);
}
/*
//checking is its beetween a and z for caps and lowercase
//only letters returns 1, spaces also return 0
//&& to avoid smll or upper from detecting

#include <stdio.h>

int main()
{
 
    char str1[] = "Testingftalpha";

    printf("Test 1: %s\n", str1);
    printf("Its %d\n", ft_str_is_alpha(str1)); 

    return 0;
}
*/
