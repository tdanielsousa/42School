/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdaniel- <tdaniel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 11:10:15 by tdaniel-          #+#    #+#             */
/*   Updated: 2025/05/30 05:16:49 by tdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_it_empty(char *map_name, t_game *game)
{
	game->rows = count_lines(map_name);
	if (game->rows <= 0)
	{
		ft_printf("Error, the map appears to be empty.\n");
		ft_quit_game(game);
	}
}

int	count_lines(char *map_name)
{
	int		rows;
	char	*line;
	int		fd;

	rows = 0;
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error opening the map file to count lines.\n");
		return (-1);
	}
	line = get_next_line(fd);
	while (line != NULL)
	{
		rows++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (rows);
}

// map is 2d, fill each row
void	fill_map_rows(int fd, t_game *game)
{
	int	i;

	i = 0;
	while (i < game->rows)
	{
		game->map[i] = get_next_line(fd);
		i++;
	}
}

// r for windows
int	get_map_row_length(char *map_row)
{
	int	i;

	i = 0;
	while (map_row[i] && map_row[i] != '\n' && map_row[i] != '\r')
	{
		i++;
	}
	return (i);
}

// open rets -1 if wrong permission, etc
// malloc a str[][] map
// get rows, colums for opening map, checks..
void	read_map(char *map_name, t_game *game)
{
	int	fd;

	is_it_empty(map_name, game);
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error opening the map file.\n");
		ft_quit_game(game);
	}
	game->map = malloc(sizeof(char *) * (game->rows));
	if (game->map == NULL)
	{
		ft_quit_game(game);
	}
	fill_map_rows(fd, game);
	game->columns = get_map_row_length(game->map[0]);
	close(fd);
}
