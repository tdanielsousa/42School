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

int	ft_atoi(char *str)
{
	int	number;
	int	signal;

	signal = 1;
	number = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\v' || *str == '\f' || *str == '\r')
	{
		str++;
	}
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
		{
			signal = signal * -1;
		}
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		number = (number * 10) + (*str - '0');
		str++;
	}
	return (number * signal);
}
/*
//subtracting '0' from any digit character gives you its numeric equivalent
//skip whitespace characters
//looks at + -, if - changes it even if alrdy - cause - - = +
//prints while finds numbers
//transforms to int


#include<stdio.h>

int	main(void)
{
	char *str = " ---+--+1234ab567";
	printf("%d", ft_atoi(str));
	return (0);
}
*/
