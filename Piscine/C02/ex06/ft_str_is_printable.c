/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdaniel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 12:46:31 by tdaniel-          #+#    #+#             */
/*   Updated: 2024/09/12 10:07:32 by tdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	while (*str != '\0')
	{
		if (*str < 32)
		{
			return (0);
		}
		str++;
	}
	return (1);
}
/*
//// Verifica se o caractere é menor que 32, que são caracteres não imprimíveis
//man ascii
//#include <stdio.h>

int main()
{
    char str1[] = "Testar 01";  

    printf("string %s\n", str1);
    printf("resultado %d\n", ft_str_is_printable(str1));

    return 0;
}
*/
