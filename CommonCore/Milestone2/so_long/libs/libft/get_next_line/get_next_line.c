/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdaniel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 09:14:05 by tdaniel-          #+#    #+#             */
/*   Updated: 2025/01/21 10:51:57 by tdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
*read_buffer - temporary buffer to store all data from the read
temp - what is recieved is the leftovers from previous run
bytes_read - bytes returned by read
-1: error occurred, the function frees memory and returns NULL.
0: end of the file, the function returns temp after freeing read_buffer.
ft_strnlen(temp, '\n', 0) <= 0
ensures function continues to read more data until it finds a newline char \n
join temp which is the leftovers as a prefix
*/

char	*ft_read_and_join(int fd, char *temp)
{
	char	*read_buffer;
	int		bytes_read;

	bytes_read = 1;
	read_buffer = malloc(BUFFER_SIZE + 1);
	while (bytes_read > 0 && ft_strnlen(temp, '\n', 0) <= 0)
	{
		if (!read_buffer)
			return (NULL);
		bytes_read = read(fd, read_buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			ft_free(&read_buffer);
			ft_free(&temp);
			return (NULL);
		}
		if (bytes_read == 0)
			return (ft_free(&read_buffer), temp);
		read_buffer[bytes_read] = '\0';
		temp = ft_strjoin_get(temp, read_buffer);
	}
	ft_free(&read_buffer);
	return (temp);
}

/*
when this recieves leftovers its already leftover + read
copies everything after the first \n
free the original string
check if str is empty
returns the leftovers to the next run
*/
char	*ft_make_leftovers(char *temp)
{
	char	*str;
	int		i;

	i = 0;
	while (temp[i])
	{
		if (temp[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	str = ft_strndup(temp + i, 0, 1);
	ft_free(&temp);
	if (ft_strnlen(str, 0, 1) == 0)
		return (ft_free(&str), NULL);
	else
		return (str);
	return (NULL);
}

/*
send leftover from previous runs and get the leftover + read
line - search to see if there is a newline else till the end of the string
and copies aconrdingly	ft_strndup(const char *src, int length, int n_or_not)
then make leftovers for next run
*/
char	*get_next_line(int fd)
{
	static char	*leftovers;
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		ft_free(&leftovers);
		return (NULL);
	}
	if (!leftovers)
		leftovers = NULL;
	leftovers = ft_read_and_join(fd, leftovers);
	if (!leftovers)
		return (NULL);
	if (ft_strnlen(leftovers, '\n', 0) >= 0)
		line = ft_strndup(leftovers, ft_strnlen(leftovers, '\n', 0) + 1, 0);
	else if (ft_strnlen(leftovers, '\0', 0) >= 0)
		line = ft_strndup(leftovers, ft_strnlen(leftovers, '\0', 0), 0);
	else
		return (NULL);
	leftovers = ft_make_leftovers(leftovers);
	if (!line)
		return (NULL);
	return (line);
}

/*
int	main()
{
    
  	printf("%s\n", "-------------------- TEST -------------------");

    int fd1 = open("test.txt", O_RDONLY);
    if (fd1 < 0) {
        printf("Error: could not open file.\n");
        return (-1);
    }

    char *line;
    while ((line = get_next_line(fd1)) != NULL) {
        printf("%s", line);
        free(line);
    }

    close(fd1);
    printf("\n");

	return (0);
}
*/
