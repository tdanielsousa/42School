/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding_validator.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdaniel- <tdaniel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 11:11:26 by tdaniel-          #+#    #+#             */
/*   Updated: 2025/05/30 05:18:47 by tdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Make a copy of the map because flood substitutes to V what it visited
void	copy_map_for_flood(t_game *game)
{
	int	i;

	i = 0;
	game->map_copy = malloc(sizeof(char *) * game->rows);
	if (game->map_copy == NULL)
	{
		ft_printf("Failed to allocate memory to copy map for flood.\n");
		ft_quit_game(game);
	}
	while (i < game->rows)
	{
		game->map_copy[i] = ft_strdup(game->map[i]);
		if (game->map_copy[i] == NULL)
		{
			ft_printf("Failed to duplicate row %d in flood map copy.\n", i);
			ft_quit_game(game);
		}
		i++;
	}
}

// flood fill needs to start from the player's position to simulate movement
// safeguarded that there is only 1 P with is_there_exit_and_player
void	where_player_starts_flood(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->rows)
	{
		x = 0;
		while (x < game->columns)
		{
			if (game->map[y][x] == 'P')
			{
				game->player_position_x = x;
				game->player_position_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

// get P position from where_player_starts_flood
// v visited
// works like bucket tool, checking neighboors and filling them
bool	flood_fill(char **map_copy, int y, int x, t_game *game)
{
	if (y < 0 || y >= game->rows || x < 0 || x >= game->columns)
		return (true);
	if (map_copy[y][x] == '1' || map_copy[y][x] == 'V')
		return (true);
	if (map_copy[y][x] == 'C')
		game->count_collec_flood++;
	if (map_copy[y][x] == 'E')
		game->count_exit_flood++;
	map_copy[y][x] = 'V';
	flood_fill(map_copy, y, x - 1, game);
	flood_fill(map_copy, y, x + 1, game);
	flood_fill(map_copy, y - 1, x, game);
	flood_fill(map_copy, y + 1, x, game);
	if (game->count_exit_flood != 1
		|| game->count_collec_flood != game->total_collectibles)
		return (false);
	return (true);
}

void	validate_pathfinding(t_game *game)
{
	copy_map_for_flood(game);
	where_player_starts_flood(game);
	if (flood_fill(game->map_copy, game->player_position_y,
			game->player_position_x, game) == false)
	{
		ft_printf("Cant get all collectibles or to exit.\n");
		ft_quit_game(game);
	}
}
