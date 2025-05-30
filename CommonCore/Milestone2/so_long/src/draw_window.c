/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdaniel- <tdaniel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 16:32:05 by tdaniel-          #+#    #+#             */
/*   Updated: 2025/05/30 05:08:54 by tdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	display_window(t_game *game)
{
	if (game->mlx_ptr == NULL)
	{
		return (false);
	}
	game->window_ptr = mlx_new_window(game->mlx_ptr, game->columns * SIZE,
			game->rows * SIZE, "so_long");
	if (game->window_ptr == NULL)
	{
		return (false);
	}
	return (true);
}

// KeyPress- mlx event type code detect keys
// KeyPressMask - Tell the event loop to listen for keyboard press
// Destroynotify - detect window close X
// StructureNotifyMask - Listen for window structure changes
void	open_window(t_game *game)
{
	if (display_window(game) == false)
		ft_quit_game(game);
	draw_map(game);
	mlx_hook(game->window_ptr, KeyPress, KeyPressMask, &process_player_input,
		game);
	mlx_hook(game->window_ptr, DestroyNotify, StructureNotifyMask,
		&ft_quit_game, game);
	mlx_loop(game->mlx_ptr);
}
