/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdaniel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:46:31 by tdaniel-          #+#    #+#             */
/*   Updated: 2024/11/05 17:23:24 by tdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
PARAMETERS 
s1: The prefix string.
s2: The suffix string.
RETURN VALUE
The new string.
DESCRIPTION
Allocates (with malloc(3)) and returns a new string,
which is the result of the concatenation of ’s1’ and ’s2’.
*/

static	int	sizecalculator(char const *s1, char const *s2)
{
	unsigned int	prefix;
	unsigned int	sufix;
	unsigned int	size;

	prefix = 0;
	sufix = 0;
	while (s1[prefix])
	{
		prefix++;
	}
	while (s2[sufix])
	{
		sufix++;
	}
	size = prefix + sufix;
	return (size);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*joinedstring;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	joinedstring = malloc((sizecalculator(s1, s2) + 1) * sizeof(char));
	if (joinedstring == NULL)
	{
		return (NULL);
	}
	while (s1[i])
	{
		joinedstring[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		joinedstring[i] = s2[j];
		j++;
		i++;
	}
	joinedstring[i] = '\0';
	return (joinedstring);
}
/*
int	main(void)
{
    char	*str1 = "para ";
    char	*str2 = "testar";
    char	*result = ft_strjoin(str1, str2);
    printf("joined: %s\n", result);    
    free(result);
    return 0;
}
*/