/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdaniel- <tdaniel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 12:49:27 by tdaniel-          #+#    #+#             */
/*   Updated: 2025/06/02 09:34:11 by tdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	process_player_input(int key, t_game *game)
{
	if (key == XK_Escape)
	{
		ft_printf("The ESC key was pressed, exited.\n");
		ft_quit_game(game);
	}
	else if (key == 'w' || key == XK_Up)
		move_player(game, -1, 0);
	else if (key == 's' || key == XK_Down)
		move_player(game, +1, 0);
	else if (key == 'a' || key == XK_Left)
		move_player(game, 0, -1);
	else if (key == 'd' || key == XK_Right)
		move_player(game, 0, +1);
	return (0);
}

// bounds and wall check
// draw the player in the new spot
// redraw the old spot (floor or exit)
// update current position and use update to update game state
// using deltay and deltax delta meaning any value will change it
// e.g dy -1 removes 1 to the y axis
void	move_player(t_game *game, int dy, int dx)
{
	int	old_y;
	int	old_x;
	int	new_y;
	int	new_x;

	old_y = game->player_position_y;
	old_x = game->player_position_x;
	new_y = old_y + dy;
	new_x = old_x + dx;
	if (new_y < 0 || new_y >= game->rows || new_x < 0 || new_x >= game->columns
		|| game->map[new_y][new_x] == '1')
		return ;
	mlx_put_image_to_window(game->mlx_ptr, game->window_ptr, game->player, new_x
		* SIZE, new_y * SIZE);
	if (game->map[old_y][old_x] == 'E')
		mlx_put_image_to_window(game->mlx_ptr, game->window_ptr, game->exit,
			old_x * SIZE, old_y * SIZE);
	else
		mlx_put_image_to_window(game->mlx_ptr, game->window_ptr, game->floor,
			old_x * SIZE, old_y * SIZE);
	game->player_position_y = new_y;
	game->player_position_x = new_x;
	update_collectible_and_win_condition(game);
}

// Called on every move, win condition and move counter printer
void	update_collectible_and_win_condition(t_game *game)
{
	if (game->map[game->player_position_y][game->player_position_x] == 'C')
	{
		game->map[game->player_position_y][game->player_position_x] = '0';
		game->current_collectibles++;
	}
	if (game->map[game->player_position_y][game->player_position_x] == 'E')
	{
		if (game->current_collectibles == game->total_collectibles)
		{
			ft_printf("You collected everything, thanks for playing.\n");
			ft_quit_game(game);
		}
	}
	game->move_counter++;
	ft_printf("Move counter: %d\n", game->move_counter);
}
