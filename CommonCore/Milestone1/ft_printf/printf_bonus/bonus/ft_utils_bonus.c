/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdaniel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:46:31 by tdaniel-          #+#    #+#             */
/*   Updated: 2025/01/19 08:59:38 by tdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

/*
skip trailing whitespaces
check for sign
for 321:
count 0*10 +3
count 3*10 30+2 
count 32*10 320+1
321
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

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

/* 
ex. nr 321

321/1  >= 10 : divi =10;
321/10  >= 10 : divi = 100;
321/100  >= 10 : NO;
divi = 100

(nr / divisor) % 10 + '0';
321/100 = 3 % 10 = 3 + '0';
divisor /= 10;
321/10 = 32 % 10 = 2 + '0';
divisor /= 10;
321/1 = 321 % 10 = 1 + '0';
putnbr with write to a buffer no return
*/

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

void	ft_putnbr_write_unsigned(unsigned long long n, char *buffer)
{
	unsigned long long	divisor;
	int					i;

	divisor = 1;
	i = 0;
	while ((n / divisor) >= 10)
		divisor *= 10;
	while (divisor > 0)
	{
		buffer[i] = (n / divisor) % 10 + '0';
		i++;
		n = n % divisor;
		divisor = divisor / 10;
	}
	buffer[i] = '\0';
}
