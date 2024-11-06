/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdaniel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:46:31 by tdaniel-          #+#    #+#             */
/*   Updated: 2024/11/05 18:49:05 by tdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	putchar_fd_try(char c, int fd)
{
	write(fd, &c, 1);
}

/*
same as ptnbr, check negative
find the nr of 0 by * untill the last digit is < 10
"reverse" it for module
*/

void	ft_putnbr_fd(int n, int fd)
{
	long	nr;
	int		divisor;

	nr = n;
	divisor = 1;
	if (nr < 0)
	{
		putchar_fd_try('-', fd);
		nr = -nr;
	}
	while (nr / divisor >= 10)
	{
		divisor *= 10;
	}
	while (divisor > 0)
	{
		putchar_fd_try((nr / divisor) % 10 + '0', fd);
		divisor /= 10;
	}
}
/*
#include <unistd.h>
int main() {
	int fd = 1;
	ft_putnbr_fd(42, fd);
	putstr_fd_try("\n", fd);
	ft_putnbr_fd(-42, fd);
	putstr_fd_try("\n", fd);
	ft_putnbr_fd(-2147483648, fd);
	putstr_fd_try("\n", fd);
	ft_putnbr_fd(0, fd);
	return 0;
}
*/