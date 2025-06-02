/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdaniel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:46:31 by tdaniel-          #+#    #+#             */
/*   Updated: 2024/11/06 14:23:18 by tdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
find end and start of str by sending positions which to copy ignoring 
the first ones that are going to be trimmed
*/

static	int	find_start(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	found;

	i = 0;
	while (s1[i])
	{
		found = 0;
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
			{
				found = 1;
				break ;
			}
			j++;
		}
		if (found == 0)
		{
			return (i);
		}
		i++;
	}
	return (i);
}

static	int	find_end(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	found;

	i = 0;
	j = 0;
	found = 0;
	while (s1[i])
		i++;
	i--;
	while (i >= 0)
	{
		found = 0;
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
				found = 1;
			j++;
		}
		if (found == 0)
			return (i);
		i--;
	}
	return (i);
}

static char	*ft_strdup_empty(void)
{
	char	*empty_str;

	empty_str = malloc(1 * sizeof(char));
	if (empty_str == NULL)
	{
		return (NULL);
	}
	empty_str[0] = '\0';
	return (empty_str);
}
/*
ex: start = 3 and end = 5 needs pos 3 4 5 + null so 4
5-3=2 so malloc with +2
*/

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	int		start;
	int		end;
	int		i;

	i = 0;
	start = find_start(s1, set);
	end = find_end(s1, set);
	if (start > end)
	{
		return (ft_strdup_empty());
	}
	trimmed = malloc((end - start + 2) * sizeof(char));
	if (!trimmed)
		return (NULL);
	while (start <= end)
	{
		trimmed[i] = s1[start];
		i++;
		start++;
	}
	trimmed[i] = '\0';
	return (trimmed);
}
/*
PARAMETERS
s1: The string to be trimmed.
set: The reference set of characters to trim.
RETURN VALUE
The trimmed string.
NULL if the allocation fails.
DESCRIPTION
Allocates (with malloc(3)) and returns a copy of
’s1’ with the characters specified in ’set’ removed
from the beginning and the end of the string.
*/

/*
int main()
{
	char *str = "jjh5jjijj";
	char *set = "j5";
	char *result = ft_strtrim(str, set);
	if (result)
	{
		printf("%s\n", result);
		free(result);
	}
	return 0;
}
*/