/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starting_setup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdaniel- <tdaniel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 16:30:17 by tdaniel-          #+#    #+#             */
/*   Updated: 2025/06/02 11:31:39 by tdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// ft_strncmp(const char *s1, const char *s2, size_t n)
// instead of index[0] give the 4th from end
bool	is_map_extension_ok(char *map_name)
{
	int	len;

	if (map_name == NULL)
	{
		return (false);
	}
	len = ft_strlen(map_name);
	if (map_name[5] == '.')
	{
		ft_printf("Error\nName can't start with .\n");
		return (false);
	}
	if (len < 5 || ft_strncmp(map_name + len - 4, ".ber", 4) != 0)
	{
		ft_printf("Error\nMap needs to be a <name>.ber\n");
		return (false);
	}
	return (true);
}

void	initialize_game_state(t_game *game)
{
	game->map = NULL;
	game->map_copy = NULL;
	game->map_name = NULL;
	game->move_counter = 0;
	game->columns = 0;
	game->rows = 0;
	game->total_collectibles = 0;
	game->count_collec_flood = 0;
	game->current_collectibles = 0;
	game->count_exit_flood = 0;
	game->img_size_y = 0;
	game->img_size_x = 0;
}

void	initialize_graphics(t_game *game)
{
	game->mlx_ptr = mlx_init();
	game->window_ptr = NULL;
	game->img_size_y = SIZE;
	game->img_size_x = SIZE;
	game->wall = NULL;
	game->floor = NULL;
	game->exit = NULL;
	game->player = NULL;
	game->mush = NULL;
}

t_game	*setup_game(char *map_name)
{
	t_game	*game;

	game = malloc((1) * sizeof(t_game));
	if (!game)
		return (NULL);
	initialize_game_state(game);
	initialize_graphics(game);
	game->map_name = map_name;
	return (game);
}
