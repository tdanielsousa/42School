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

#include <stdlib.h>

int	ft_strncmp(char c, char *s2)
{
	int	i;

	i = 0;
	while (s2[i] != '\0')
	{
		if (c == s2[i])
			return (0);
		i++;
	}
	return (1);
}

int	ft_strcount(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && !(ft_strncmp(str[i], charset)))
			i++;
		if (str[i])
			count++;
		while (str[i] && (ft_strncmp(str[i], charset)))
			i++;
	}
	return (count);
}

int	ft_strlen(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i] && (ft_strncmp(str[i], charset)))
	{
		i++;
	}
	return (i);
}

char	*ft_print_word(char *str, char *charset)
{
	int		i;
	int		lenstr;
	char	*array;

	i = 0;
	lenstr = ft_strlen(str, charset);
	array = (char *)malloc((lenstr + 1) * sizeof(char));
	while (str[i] && (ft_strncmp(str[i], charset)))
	{
		array[i] = str[i];
		i++;
	}
	array[i] = '\0';
	return (array);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	char	**array;
	int		count;

	i = 0;
	j = 0;
	count = ft_strcount(str, charset);
	array = (char **)malloc((count + 1) * sizeof(char *));
	while (str[i] && j < count)
	{
		while (str[i] && !(ft_strncmp(str[i], charset)))
			i++;
		if (str[i])
		{
			array[j] = ft_print_word((str + i), charset);
			j++;
		}
		while (str[i] && (ft_strncmp(str[i], charset)))
			i++;
	}
	array[j] = 0;
	return (array);
}
