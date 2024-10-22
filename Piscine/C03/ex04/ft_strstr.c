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

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	p;

	i = 0;
	p = 0;
	if (to_find[p] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		while (str[i + p] == to_find[p] && str[i + p] != '\0')
			p++;
		if (to_find[p] == '\0')
			return (str + i);
		i++;
		p = 0;
	}
	return (0);
}

/*
//compares each char from both
//compares it with the characters in the small string (to_find).
//if it finds a match checks the entire string is present in the haystack
//if needle is found the funct retr the start point of the match to the large str
//if not found returns 0
//edge case of zero returns str
//p is incremented to move to the next character in to_find 
//haystack and prints till end


#include<stdio.h>
int	main(void)
{
	char *str = "aiuhtestarjjak";
	char *find = "testar";

	printf("%s", ft_strstr(str, find));
	return (0);
}
*/
