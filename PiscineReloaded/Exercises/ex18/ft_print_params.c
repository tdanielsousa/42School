/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdaniel- <tdaniel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 12:46:31 by tdaniel-          #+#    #+#             */
/*   Updated: 2024/09/09 16:31:07 by tdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c);

int	main(int argc, char *argv[])
{
	int	counter;
	int	i;

	counter = 1;
	i = 0;
	if (argc > 1)
	{
		while (counter < argc)
		{
			while (argv[counter][i])
			{
				ft_putchar(argv[counter][i]);
				i++;
			}
			i = 0;
			ft_putchar('\n');
			counter++;
		}
	}
}
