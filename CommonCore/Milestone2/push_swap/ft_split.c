/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdaniel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 03:07:29 by tdaniel-          #+#    #+#             */
/*   Updated: 2025/05/04 18:22:49 by tdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned int	i;

	if (size == 0)
	{
		i = 0;
		while (src[i] != '\0')
		{
			i++;
		}
		return (i);
	}
	size -= 1;
	i = 0;
	while (src[i] != '\0' && i < size)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	while (src[i] != '\0')
	{
		i++;
	}
	return (i);
}
// strlcpy returns total length of the string it tried to create
// size-1 in strlcpy for null term
// iterate after copy because strlcpy returns src length

int	do_malloc(char **word_matrix, int position, int nr_bytes)
{
	int	i;

	i = 0;
	word_matrix[position] = malloc(nr_bytes);
	if (word_matrix[position] == NULL)
	{
		while (i < position)
		{
			free(word_matrix[i++]);
		}
		free(word_matrix);
		return (1);
	}
	return (0);
}
// alocate and check if fails and frees
// in fail releaseall memory allocated to each index of the array
// and then frees the array of arrays itself
// return 0 if malloc was good otherwise 1 as error

int	fill_rows(char **word_matrix, char const *s, char delimiter)
{
	int	len;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[j])
	{
		len = 0;
		while (s[j] == delimiter && s[j])
			j++;
		while (s[j] != delimiter && s[j])
		{
			len++;
			j++;
		}
		if (len > 0)
		{
			if (do_malloc(word_matrix, i, len + 1) == 1)
				return (1);
			ft_strlcpy(word_matrix[i], &s[j - len], len + 1);
			i++;
		}
	}
	return (0);
}

// fills each row of the array of arrays
// if do_malloc returns 1 as error return 1 as welll

int	count_words(char const *s, char delimeter)
{
	int	words;
	int	inside_word;

	words = 0;
	while (*s)
	{
		inside_word = 0;
		while (*s == delimeter && *s)
			s++;
		while (*s != delimeter && *s)
		{
			if (!inside_word)
			{
				words++;
				inside_word = 42;
			}
			s++;
		}
	}
	return (words);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**word_matrix;

	if (NULL == s)
		return (NULL);
	words = 0;
	words = count_words(s, c);
	word_matrix = malloc((words + 1) * sizeof(char *));
	if (NULL == word_matrix)
		return (NULL);
	word_matrix[words] = NULL;
	if (fill_rows(word_matrix, s, c))
	{
		return (NULL);
	}
	return (word_matrix);
}
/*
int	main(void) {
	const char *str = "Hello, this is a test string.";
	char delimiter = ' ';
	char **result;
	int i;

	result = ft_split(str, delimiter);
	if (result == NULL) {
		printf("Memory allocation failed.\n");
		return (1);
	}

	for (i = 0; result[i] != NULL; i++) {
		printf("word %d: %s\n", i, result[i]);
		free(result[i]);  // Free each word after use
	}
	free(result);  // Free the array of word

	return (0);
}
*/