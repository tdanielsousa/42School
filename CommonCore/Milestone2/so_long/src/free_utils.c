/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdaniel- <tdaniel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 16:32:14 by tdaniel-          #+#    #+#             */
/*   Updated: 2025/05/30 05:12:19 by tdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	is_there_only_allowed_chars(t_game *game)
{
	int		x;
	int		y;
	char	c;

	y = 0;
	while (y < game->rows)
	{
		x = 0;
		while (x < game->columns)
		{
			c = game->map[y][x];
			if (c != 'C' && c != 'E' && c != 'P' && c != '1' && c != '0'
				&& c != '\n')
				return (false);
			x++;
		}
		y++;
	}
	return (true);
}

// Free each line
void	free_map_util(char **map, int rows)
{
	int	i;

	i = 0;
	if (map == NULL || map[0] == NULL)
	{
		free(map);
		return ;
	}
	while (i < rows)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_everything(t_game *game)
{
	if (game == NULL)
		return ;
	if (game->map != NULL)
		free_map_util(game->map, game->rows);
	if (game->map_copy != NULL)
		free_map_util(game->map_copy, game->rows);
	if (game->window_ptr != NULL)
		mlx_destroy_window(game->mlx_ptr, game->window_ptr);
	if (game->wall != NULL)
		mlx_destroy_image(game->mlx_ptr, game->wall);
	if (game->floor != NULL)
		mlx_destroy_image(game->mlx_ptr, game->floor);
	if (game->exit != NULL)
		mlx_destroy_image(game->mlx_ptr, game->exit);
	if (game->player != NULL)
		mlx_destroy_image(game->mlx_ptr, game->player);
	if (game->mush != NULL)
		mlx_destroy_image(game->mlx_ptr, game->mush);
	if (game->mlx_ptr != NULL)
	{
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}
	free(game);
}

//gnl trick to clean leftovers
int	ft_quit_game(t_game *game)
{
	get_next_line(-1);
	free_everything(game);
	exit(EXIT_SUCCESS);
}
