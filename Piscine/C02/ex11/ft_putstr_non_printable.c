/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdaniel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 12:46:31 by tdaniel-          #+#    #+#             */
/*   Updated: 2024/09/11 22:58:58 by tdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_char_is_printable(char c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_char_is_printable(str[i]) == 1)
			ft_putchar(str[i]);
		else
		{
			ft_putchar('\\');
			ft_putchar("0123456789abcdef"[str[i] / 16]);
			ft_putchar("0123456789abcdef"[str[i] % 16]);
		}
		i++;
	}
}
/*
//using isprintable to test if its within 32 126 ascii if 1 print
//else prints a backslash, escaped
// \n example 10 / 16= 0 character '0' in the string
// 10 % 16 = 10, corresponding to the character 'a' 
//therefore \n = \0a

int main()
{
    char str1[] = "more\tstrings\n";          
    // contem (\t e \n)

    // Testa a função e imprime os resultados
    write(1, "teste\n", 6);
    ft_putstr_non_printable(str1);
    write(1, "\n", 1);

    return 0;
}
*/
