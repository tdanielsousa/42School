/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdaniel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:46:31 by tdaniel-          #+#    #+#             */
/*   Updated: 2024/09/14 23:21:13 by tdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	n;

	n = 2;
	if (nb <= 1)
	{
		return (0);
	}
	while (n < nb)
	{
		if (nb % n == 0)
		{
			return (0);
		}
		n++;
	}
	return (1);
}

/*
//prime only divisible by itself and 1
//runs all till -1 nb(itself)
//2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53

#include<stdio.h>
int	main(void)
{
	printf("%d \n", ft_is_prime(0));
	return (0);
}
*/
