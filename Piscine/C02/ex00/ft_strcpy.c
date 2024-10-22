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

char	*ft_strcpy(char *dest, char *src)
{
	char	*start;

	start = dest;
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (start);
}

/*
//start copies dest 1 location which is already declared above
//because when it ends dest will be at the last position of the string
//Copies index1 and increments indexes for both
//need to add the null terminator because the while doesnt copy it
//start keeps the 1 adress of the dest

#include <stdio.h>

int main()
{
    char src[] = "the string copied";
    char dest[90];  
    
//Dont need to give src any size because the string defines it
//dest needs fix size to allocate at compile and avoid malloc

    ft_strcpy(dest, src);

    printf("1st string %s\n", src);
    printf("2nd string %s\n", dest);

    return 0;
}
*/
