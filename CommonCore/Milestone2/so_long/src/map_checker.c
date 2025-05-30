/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdaniel- <tdaniel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 15:48:43 by tdaniel-          #+#    #+#             */
/*   Updated: 2025/05/30 05:13:53 by tdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Check all rows have the same length as the first row
// Map is rectangular if rows != columns
bool	is_map_rectangle(t_game *game)
{
	int	i;

	i = 1;
	while (i < game->rows)
	{
		if (get_map_row_length(game->map[i]) != game->columns)
		{
			return (false);
		}
		i++;
	}
	if (game->rows == game->columns)
	{
		return (false);
	}
	return (true);
}

bool	is_firstlast_wall_ok(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = game->rows - 1;
	while (game->map[0][x])
	{
		if (game->map[0][x] != '1' && game->map[0][x] != '\n'
			&& game->map[0][x] != '\0')
			return (false);
		x++;
	}
	x = 0;
	while (game->map[y][x])
	{
		if (game->map[y][x] != '1' && game->map[y][x] != '\n'
			&& game->map[y][x] != '\0')
			return (false);
		x++;
	}
	return (true);
}

bool	is_side_walls_ok(t_game *game)
{
	int	y;
	int	x;

	x = game->columns - 1;
	y = 1;
	while (y < game->rows - 1)
	{
		if (game->map[y][0] != '1' || game->map[y][x] != '1')
			return (false);
		y++;
	}
	return (true);
}

bool	are_there_collectibles(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->rows)
	{
		x = 0;
		while (x < game->columns)
		{
			if (game->map[y][x] == 'C')
				game->total_collectibles++;
			x++;
		}
		y++;
	}
	if (game->total_collectibles < 1)
		return (false);
	return (true);
}

// checks if there is exit and play but only 1
bool	is_there_exit_and_player(t_game *game)
{
	int	x;
	int	y;
	int	exit;
	int	player;

	exit = 0;
	player = 0;
	y = 0;
	while (y < game->rows)
	{
		x = 0;
		while (x < game->columns)
		{
			if (game->map[y][x] == 'E')
				exit++;
			else if (game->map[y][x] == 'P')
				player++;
			x++;
		}
		y++;
	}
	if (exit != 1 || player != 1)
		return (false);
	return (true);
}
