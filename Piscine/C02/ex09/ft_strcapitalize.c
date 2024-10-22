/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdaniel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 12:46:31 by tdaniel-          #+#    #+#             */
/*   Updated: 2024/09/12 11:13:52 by tdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_alphanumeric(char c)
{
	if ((c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'))
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	in_word;

	i = 0;
	in_word = 0;
	while (str[i] != '\0')
	{
		if (is_alphanumeric(str[i]))
		{
			if (in_word == 0 && (str[i] >= 'a' && str[i] <= 'z'))
				str[i] -= 'a' - 'A';
			else if (in_word == 1 && (str[i] >= 'A' && str[i] <= 'Z'))
				str[i] += 'a' - 'A';
			in_word = 1;
		}
		else
			in_word = 0;
		i++;
	}
	return (str);
}

/*
// breaking condition into 3 because of size and into helper func
//code goes through each character till null
//checking if its chars or digit like in previous exercises
//'a' - 'A' 32 difference between ascii values of 'a' and 'A'
//while inside a word, it converts any uppercase to lowercase. line28
//digits dont need treatment
//limits; if not a letter or digit, it marks the end of the current word.
//i++ moves to next char

#include <stdio.h>
int main() {
    char str[] = "a1b2c3";
    printf("string %s\n", str);
    printf("with caps: %s\n", ft_strcapitalize(str));
    return 0;
}
*/
