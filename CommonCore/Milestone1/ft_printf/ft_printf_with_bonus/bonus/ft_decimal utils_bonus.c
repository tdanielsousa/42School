/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdaniel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:46:31 by tdaniel-          #+#    #+#             */
/*   Updated: 2025/01/06 22:03:56 by tdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

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

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

// putnbr with write to a buffer no return

void	ft_putnbr_write(int n, char *buffer)
{
	long	nr;
	int		divisor;
	int		i;

	nr = n;
	divisor = 1;
	i = 0;
	if (nr < 0)
		nr = -nr;
	while ((nr / divisor) >= 10)
		divisor *= 10;
	while (divisor > 0)
	{
		buffer[i] = (nr / divisor) % 10 + '0';
		i++;
		nr = nr % divisor;
		divisor = divisor / 10;
	}
	buffer[i] = '\0';
}
