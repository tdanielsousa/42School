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
#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

int	get_total_length(int size, char **strs, char *sep)
{
	int	total_len;
	int	i;

	total_len = 0;
	i = 0;
	while (i < size)
	{
		total_len += ft_strlen(strs[i]);
		if (i != size - 1)
			total_len += ft_strlen(sep);
		i++;
	}
	return (total_len);
}

void	concat_strings(char *result, int size, char **strs, char *sep)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	c = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
			result[c++] = strs[i][j++];
		j = 0;
		while (sep[j] != '\0' && i != size - 1)
			result[c++] = sep[j++];
		i++;
	}
	result[c] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int		total_len;

	if (size == 0)
	{
		result = malloc(1);
		if (result)
			result[0] = '\0';
		return (result);
	}
	total_len = get_total_length(size, strs, sep);
	result = malloc(sizeof(char) * (total_len + 1));
	if (!result)
		return (NULL);
	concat_strings(result, size, strs, sep);
	return (result);
}

/*
//ft_strlen: clculates the length of string
//get_total_length:how much space is needed for strings plus the separators
//concat_strings: sums each string and separator
//ft_strjoin: alocates memory for result, join strings, and returns result

If size is 0, it returns an empty string that can be freed.

char	*ft_strjoin(int size, char **strs, char *sep);

int	main(void)
{
	char *strs[] = {"Hellooo", "word", "from", "ft_strjoin"};
	char *sep = ", ";
	int size = 4;

	char *result = ft_strjoin(size, strs, sep);
	if (result)
	{
		printf("Joined string: %s\n", result);
		free(result); 
	}
	else
	{
		printf("memoory allocation failed!\n");
	}

	return 0;
}

*/
