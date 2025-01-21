/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdaniel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:34:27 by tdaniel-          #+#    #+#             */
/*   Updated: 2025/01/21 10:48:29 by tdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

char	*ft_strndup(const char *src, int length, int n_or_not);
int		ft_strnlen(const char *str, char c, int is_strchr);
char	*ft_strjoin(char *s1, char *s2);
void	ft_free(char **temp);
char	*ft_read_and_join(int fd, char *temp);
char	*ft_make_leftovers(char *temp);
char	*get_next_line(int fd);

#endif
