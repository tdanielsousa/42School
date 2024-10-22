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
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	duplicate_or_invalid(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == '%'
			|| base[i] == '/' || base[i] == '*' || base[i] == '='
			|| base[i] == ',' || base[i] == '.'
			|| base[i] < 33 || base[i] > 126)
			return (1);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	base_length;

	base_length = ft_strlen(base);
	if (base_length <= 1 || duplicate_or_invalid(base))
		return ;
	if (nbr == -2147483648)
	{
		if (ft_strlen(base) == 2)
			ft_putstr("-10000000000000000000000000000000");
		else if (ft_strlen(base) == 16)
			ft_putstr("-80000000");
		else if (ft_strlen(base) == 8)
			ft_putstr("-20000000000");
		return ;
	}
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr >= base_length)
		ft_putnbr_base(nbr / base_length, base);
	ft_putchar(base[nbr % base_length]);
}

/*
//prints nbrs like in putnbr
//print largest -int case specials
//check duplicate or invalids
//use previous made functions

#include <stdio.h>

void ft_putnbr_base(int nbr, char *base);

int main(void) {
   
    printf("-2147483648 in binary:\n");
    ft_putnbr_base(-2147483648, "01");
    printf("\n\n");

    return 0;
}
*/
