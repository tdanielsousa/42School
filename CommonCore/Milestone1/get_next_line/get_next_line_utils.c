/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdaniel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:34:27 by tdaniel-          #+#    #+#             */
/*   Updated: 2025/01/21 10:44:51 by tdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// n_or_not if its 0 its strndup otherwise its strdup
char	*ft_strndup(const char *src, int length, int n_or_not)
{
	int		i;
	char	*new;

	i = -1;
	if (n_or_not == 0)
	{
		new = malloc(length + 1);
		if (new == NULL || length == 0)
			return (ft_free(&new), NULL);
		while (++i < length)
			new[i] = src[i];
	}
	else
	{
		new = malloc(ft_strnlen(src, 0, 1) + 1);
		if (!new)
			return (NULL);
		while (src[++i] != '\0')
			new[i] = src[i];
	}
	new[i] = '\0';
	return (new);
}

// if type is 0 works like strchr else its strlen
int	ft_strnlen(const char *str, char c, int is_strchr)
{
	int	i;

	i = 0;
	if (!str && is_strchr != 0)
		return (0);
	if (is_strchr == 0)
	{
		if (!str)
			return (-1);
		while (str[i] && str[i] != c)
			i++;
		if (str[i] == c)
			return (i);
		return (-1);
	}
	else
	{
		while (str[i])
			i++;
		return (i);
	}
	return (i);
}

// standard strjoin
char	*ft_strjoin(char *s1, char *s2)
{
	char	*joinedstring;
	int		i;
	int		j;
	int		s1_size;
	int		s2_size;

	s1_size = 0;
	s2_size = 0;
	s1_size = ft_strnlen(s1, 0, 1);
	s2_size = ft_strnlen(s2, 0, 1);
	joinedstring = malloc(s1_size + s2_size + 1);
	if (!joinedstring)
		return (ft_free(&s1), NULL);
	i = -1;
	while (++i < s1_size)
		joinedstring[i] = s1[i];
	j = -1;
	while (++j < s2_size)
		joinedstring[i + j] = s2[j];
	joinedstring[i + j] = '\0';
	return (ft_free(&s1), joinedstring);
}

// frees the memory the pointer is pointing to and sets the pointer to null
void	ft_free(char **temp)
{
	if (temp && *temp)
	{
		free(*temp);
		*temp = NULL;
	}
}
