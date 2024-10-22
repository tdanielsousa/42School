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

#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *str, int size)
{
	char	*res;
	int		i;

	res = NULL;
	res = malloc(sizeof (char) * (size + 1));
	i = 0;
	while (str[i])
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*stocks;
	int			i;

	stocks = malloc(sizeof (t_stock_str) * (ac + 1));
	if (stocks == NULL)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		stocks[i].size = ft_strlen(av[i]);
		stocks[i].str = av[i];
		stocks[i].copy = ft_strcpy(av[i], stocks[i].size);
		i++;
	}
	stocks[i].size = 0;
	stocks[i].str = 0;
	stocks[i].copy = 0;
	return (stocks);
}
//converts an array of strings  into an array of structures
//*stocks creates a pointer to a struct named stocks based on t_stock_str
//structure t_stock_str, original str, copied str, size
//size+1 because of null terminator
//ac +1 to add "null ter" to struct to idnetify end of array
