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

int	ft_sqrt(int nb)
{
	int	i;

	i = 0;
	if (nb < 0)
		return (0);
	while ((i * i) < nb)
		i++;
	if (i * i == nb)
		return (i);
	else
		return (0);
}

/*
//checks 1x1 2x2 etc till nb
//if it leaves the while checks if returns or 0 for nonroots
#include<stdio.h>
int	main(void)
{
	printf("%d \n", ft_sqrt(9));
	return (0);
}
*/