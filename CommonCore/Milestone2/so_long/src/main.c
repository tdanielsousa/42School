/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdaniel- <tdaniel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 16:32:43 by tdaniel-          #+#    #+#             */
/*   Updated: 2025/06/02 09:32:33 by tdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	validate_game_map(t_game *game)
{
	if (is_map_rectangle(game) == false)
	{
		ft_printf("Error\nThe map must be a rectangle.\n");
		ft_quit_game(game);
	}
	if (is_firstlast_wall_ok(game) == false || is_side_walls_ok(game) == false)
	{
		ft_printf("Error\nMap borders must be surrounded by walls.\n");
		ft_quit_game(game);
	}
	if (are_there_collectibles(game) == false)
	{
		ft_printf("Error\nThe map doesnt have collectibles.\n");
		ft_quit_game(game);
	}
	if (is_there_exit_and_player(game) == false)
	{
		ft_printf("Error\nThere isnt a player or an exit.\n");
		ft_quit_game(game);
	}
	if (is_there_only_allowed_chars(game) == false)
	{
		ft_printf("Error\nCharacters allowed [C,P,E,1,0] only \n");
		ft_quit_game(game);
	}
}

int	main(int ac, char *av[])
{
	t_game	*game;

	if (ac == 2)
	{
		game = setup_game(av[1]);
		if (is_map_extension_ok(av[1]) == false)
		{
			ft_quit_game(game);
		}
		read_map(av[1], game);
		validate_game_map(game);
		validate_pathfinding(game);
		open_window(game);
	}
	else
	{
		ft_printf("Error\nUsage: ./so_long maps/map_file.ber\n");
	}
	return (0);
}
