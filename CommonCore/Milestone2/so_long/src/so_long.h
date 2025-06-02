/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdaniel- <tdaniel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 11:15:46 by tdaniel-          #+#    #+#             */
/*   Updated: 2025/05/30 05:29:23 by tdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libs/libft/libft.h"
# include "../libs/minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdbool.h>
# include <unistd.h>
// Open and O_RDONLY
# include <fcntl.h>

# define SIZE 64

typedef struct s_game
{
	char	**map;
	char	**map_copy;
	char	*map_name;
	int		move_counter;
	int		rows;
	int		columns;
	int		total_collectibles;
	int		current_collectibles;
	int		count_collec_flood;
	int		count_exit_flood;

	void	*mlx_ptr;
	void	*window_ptr;

	void	*wall;
	void	*floor;
	void	*exit;
	void	*player;
	void	*mush;

	int		player_position_x;
	int		player_position_y;
	int		img_size_x;
	int		img_size_y;

}			t_game;

// draw_game.c
bool		load_textures_to_pointers(t_game *game);
void		draw_tile_texture(t_game *game, int y, int x);
void		draw_map(t_game *game);

// draw_window.c
bool		display_window(t_game *game);
void		open_window(t_game *game);

// free_util.c
bool		is_there_only_allowed_chars(t_game *game);
void		free_map_util(char **map, int rows);
void		free_everything(t_game *game);
int			ft_quit_game(t_game *game);

// main.c
void		validate_game_map(t_game *game);

// map_checker.c
bool		is_map_rectangle(t_game *game);
bool		is_firstlast_wall_ok(t_game *game);
bool		is_side_walls_ok(t_game *game);
bool		are_there_collectibles(t_game *game);
bool		is_there_exit_and_player(t_game *game);

// map_reader.c
void		is_it_empty(char *map_name, t_game *game);
int			count_lines(char *map_name);
void		fill_map_rows(int fd, t_game *game);
int			get_map_row_length(char *map_row);
void		read_map(char *map_name, t_game *game);

// pathfinding_validator.c
void		copy_map_for_flood(t_game *game);
void		where_player_starts_flood(t_game *game);
bool		flood_fill(char **map_copy, int y, int x, t_game *game);
void		validate_pathfinding(t_game *game);

// player_input.c
int			process_player_input(int key, t_game *game);
void		move_player(t_game *game, int dy, int dx);
void		update_collectible_and_win_condition(t_game *game);

// starting_setup.c
bool		is_map_extension_ok(char *map_name);
void		initialize_game_state(t_game *game);
void		initialize_graphics(t_game *game);
t_game		*setup_game(char *map_name);

#endif