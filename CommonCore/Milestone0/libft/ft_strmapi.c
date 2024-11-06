/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdaniel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:46:31 by tdaniel-          #+#    #+#             */
/*   Updated: 2024/11/06 13:56:38 by tdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		len;
	char	*str;
	int		i;

	len = 0;
	i = 0;
	while (s[len] != '\0')
	{
		len++;
	}
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
	{
		return (NULL);
	}
	while (s[i] != '\0')
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[len] = '\0';
	return (str);
}
/*
f (index,charcter)
Difference to teri is creates a new str instead of changing chars in place
Parameters
s: The string on which to iterate.
f: The function to apply to each character.

Return value 
The string created from the successive applications
of ’f’.

Description
Applies the function f to each character of the
string s, passing its index as the first argument
and the character itself as the second. A new
string is created (using malloc(3)) to collect the
results from the successive applications of f.
*/

/*
static  char	ft_toupper(unsigned int index, char	c)
{
 	if (c >= 97 && c <= 122)
	{
 		c = c - 32;
 	}
	return (c);
 }

int	main (void)
{
	char const	*str = "olaola";

	printf("%s", ft_strmapi(str, ft_toupper));
	
return (0);
}
*/