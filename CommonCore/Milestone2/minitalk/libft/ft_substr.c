/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdaniel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 12:46:31 by tdaniel-          #+#    #+#             */
/*   Updated: 2024/11/06 14:37:57 by tdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlcpy_try(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	src_length;

	src_length = 0;
	while (src[src_length] != '\0')
	{
		src_length++;
	}
	if (size == 0)
	{
		return (src_length);
	}
	i = 0;
	while (src[i] != '\0' && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_length);
}

static size_t	ft_strlen_try(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
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
len > substring_len to be sure it doesnt copy more chars than the str has
and it prevents acess to memory it cant
strlcpy needs +1 because it uses 1 for null term
*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	s_len;
	size_t	substring_len;

	if (NULL == s)
		return (NULL);
	s_len = ft_strlen_try(s);
	if (start >= s_len)
	{
		return (ft_strdup_empty());
	}
	substring_len = s_len - start;
	if (len > substring_len)
	{
		len = substring_len;
	}
	substr = malloc(len + 1);
	if (NULL == substr)
	{
		return (NULL);
	}
	ft_strlcpy_try(substr, s + start, len + 1);
	return (substr);
}
/*
Parameters
s: The string from which to create the substring.
start: The start index of the substring in the string ’s’.
len: The maximum length of the substring.

Return value
The substring.
NULL if the allocation fails.

Description
Allocates (with malloc(3)) and returns a substring from the string ’s’.
The substring begins at index ’start’ and is of maximum size ’len’.
*/

/*
#include <stdio.h>
#include <stdlib.h>
int	main(void)
{
    char	*str = "testar substr";
    char	*result = ft_substr(str, 2, 2);
    printf("substring: %s\n", result);    
    free(result);
    return 0;
}
*/