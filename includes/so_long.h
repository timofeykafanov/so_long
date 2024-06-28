/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <tkafanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:16:17 by tkafanov          #+#    #+#             */
/*   Updated: 2024/06/28 15:16:18 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "textures.h"
# include "macro.h"
# include "structs.h"
# include "../minilibx-linux/mlx.h"
// # include <mlx.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <fcntl.h>
# include <stdbool.h>
# include <time.h>

// free.c

void	free_map(char **map);

// put_border.c

void	put_border(t_mlx_data data, int y, int x);

// display.c

int		display_game(t_mlx_data *data);

// display_utils.c

bool	is_cross(t_mlx_data data, int y, int x);
bool	is_corner(t_mlx_data data, int y, int x);
void	put_cross(t_mlx_data data, int y, int x);
void	put_corner(t_mlx_data data, int y, int x);
void	put_edge(t_mlx_data data, int y, int x);

// map.c

int		count_width(char **map);
int		count_height(char **map);
int		init_map(t_mlx_data *data, char *file);

// map_utils.c

bool	is_map_rectangular(char **map);
bool	is_perimeter_true(char **map);
bool	has_start_and_and(char **map);
bool	contains_coins(t_mlx_data *data);
bool	is_filename_valid(char *filename);

// movements.c

void	find_player(t_mlx_data *data, int *y, int *x);
void	move_up(t_mlx_data *data);
void	move_down(t_mlx_data *data);
void	move_right(t_mlx_data *data);
void	move_left(t_mlx_data *data);

// movements_utils.c

void	handle_up(t_mlx_data *data, int y, int x);
void	handle_right(t_mlx_data *data, int y, int x);
void	handle_left(t_mlx_data *data, int y, int x);
void	handle_down(t_mlx_data *data, int y, int x);

// flood_fill.c

bool	has_valid_path(t_mlx_data *data);

// symbol_check.c

bool	has_only_valid_symbols(char **map);

// close.c

int		close_game(t_mlx_data *data);

// sprite_player_bonus.c

void	display_player_sprite(t_mlx_data data, int y, int x, int frame);

// sprite_coin_bonus.c

void	display_coin_sprite(t_mlx_data data, int y, int x, int frame);

// sprite_enemy_bonus.c

void	display_enemy_sprite(t_mlx_data *data, int y, int x, int frame);

// move_enemies_bonus.c

void	move_enemies(t_mlx_data *data);

// move_enemies_utils_bonus.c

void	move_enemy_right(t_mlx_data *data, int *i, int *j);
void	move_enemy_left(t_mlx_data *data, int *i, int *j);
void	move_enemy_up(t_mlx_data *data, int *i, int *j);
void	move_enemy_down(t_mlx_data *data, int *i, int *j);

// init_images.c

void	init_images(t_mlx_data *data);

// destroy_images.c

void	destroy_images(t_mlx_data *data);

#endif // SO_LONG_H
