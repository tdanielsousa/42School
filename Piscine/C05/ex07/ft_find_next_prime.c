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

int	ft_find_next_prime(int nb)
{
	if (nb < 2)
	{
		return (2);
	}
	while (nb >= 2)
	{
		if (ft_is_prime(nb))
		{
			return (nb);
		}
		nb++;
	}
	return (0);
}

/*
//use previous to next prime
#include<stdio.h>
int	main(void)
{
	printf("%d \n", ft_find_next_prime(0));
	return (0);
}
*/
