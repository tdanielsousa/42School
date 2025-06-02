/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdaniel- <tdaniel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 11:09:16 by tdaniel-          #+#    #+#             */
/*   Updated: 2025/05/29 11:07:42 by tdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	load_textures_to_pointers(t_game *game)
{
	game->wall = mlx_xpm_file_to_image(game->mlx_ptr, "./textures/WALL.xpm",
			&game->img_size_x, &game->img_size_y);
	game->floor = mlx_xpm_file_to_image(game->mlx_ptr, "./textures/FLOOR.xpm",
			&game->img_size_x, &game->img_size_y);
	game->exit = mlx_xpm_file_to_image(game->mlx_ptr, "./textures/EXIT.xpm",
			&game->img_size_x, &game->img_size_y);
	game->player = mlx_xpm_file_to_image(game->mlx_ptr, "./textures/PLAYR.xpm",
			&game->img_size_x, &game->img_size_y);
	game->mush = mlx_xpm_file_to_image(game->mlx_ptr, "./textures/MUSH.xpm",
			&game->img_size_x, &game->img_size_y);
	if (!game->wall || !game->floor || !game->exit || !game->player
		|| !game->mush)
		return (false);
	return (true);
}

void	draw_tile_texture(t_game *game, int y, int x)
{
	char	character;
	void	*texture;

	character = game->map[y][x];
	texture = NULL;
	if (character == '1')
		texture = game->wall;
	else if (character == 'E')
		texture = game->exit;
	else if (character == 'P')
		texture = game->player;
	else if (character == '0')
		texture = game->floor;
	else if (character == 'C')
		texture = game->mush;
	if (texture)
		mlx_put_image_to_window(game->mlx_ptr, game->window_ptr, texture, x
			* SIZE, y * SIZE);
}

void	draw_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	if (load_textures_to_pointers(game) == false)
	{
		ft_quit_game(game);
	}
	while (y < game->rows)
	{
		x = 0;
		while (x < game->columns)
		{
			draw_tile_texture(game, y, x);
			x++;
		}
		y++;
	}
}
