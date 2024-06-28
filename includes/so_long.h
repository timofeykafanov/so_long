/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <tkafanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:16:17 by tkafanov          #+#    #+#             */
/*   Updated: 2024/06/28 09:38:27 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "textures.h"
# include "../minilibx-linux/mlx.h"
// # include <mlx.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <fcntl.h>
# include <stdbool.h>
# include <time.h>

# define SUCCESS 0
# define ERROR 1

# define IMG_H 32
# define IMG_W 32

# define ESC 65307
# define UP 119
# define LEFT 97
# define DOWN 115
# define RIGHT 100

# define GAME "Packman"

# define WALL	'1'
# define FLOOR	'0'
# define PLAYER	'P'
# define COIN	'C'
# define EXIT	'E'
# define ENEMY	'G'
# define FILL	'F'

# define NEW_LINE '\n'

# define ERR_MESS_PER		"Error\nThe map should be surrounded by walls!\n"
# define ERR_MESS_EXTEN		"Error\nInvalid file extention!\n"
# define ERR_MESS_FILE		"Error\nFile doesn't exist!\n"
# define ERR_MESS_SHAPE		"Error\nMap should be rectangular!\n"
# define ERR_MESS_PLAYER	"Error\nThere should be 1 player!\n"
# define ERR_MESS_EXIT		"Error\nThere should be 1 exit!\n"
# define ERR_MESS_COINS		"Error\nThere should be at least 1 collectible!\n"
# define ERR_MESS_READ		"Error\nError reading file!\n"
# define ERR_MESS_EMPTY		"Error\nEmpty map!\n"
# define ERR_MESS_PATH		"Error\nThere is no valid path!\n"
# define ERR_MESS_SYMB		"Error\nInvalid symbol found!\n"
# define ERR_MESS_NEWLINE	"Error\nInvalid newline found!\n"
# define ERR_MESS_ARGS		"Error\nUsage: %s [map file path]\n"

# define LOSE_MESS	"You died!\n"
# define MOVES_MESS	"Moves: %d\n"
# define WIN_MESS	"You won! Result: %d\n"

typedef struct s_mlx_data
{
	void	*mlx;
	void	*wdw;
	int		width;
	int		height;
	char	**map;
	int		moves;
	int		coins;
	bool	flag;
	int		direction;
	int		enemy;
	int		frame;
}	t_mlx_data;

typedef struct s_img
{
	void	*img;
	int		w;
	int		h;
}	t_img;

typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;

typedef struct s_validation
{
	int	player;
	int	exit;
}	t_validation;

typedef struct s_read_map
{
	char	**map;
	char	*file_content;
	char	*line;
	int		fd;
}	t_read_map;

// free.c

void	free_map(char **map);

// put_border.c

void	*put_border(t_mlx_data data, t_img *img, int y, int x);

// display.c

int		display_game(t_mlx_data *data);

// display_utils.c

bool	is_cross(t_mlx_data data, int y, int x);
bool	is_corner(t_mlx_data data, int y, int x);
void	*put_cross(t_mlx_data data, t_img *img, int y, int x);
void	*put_corner(t_mlx_data data, t_img *img, int y, int x);

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

void	*put_player_sprite(t_mlx_data data, t_img *img, int frame);

// sprite_coin_bonus.c

void	*put_coin_sprite(t_mlx_data data, t_img *img, int frame);

// sprite_enemy_bonus.c

void	*put_enemy_sprite(t_mlx_data *data, t_img *img, int frame);

// move_enemies_bonus.c

void	move_enemies(t_mlx_data *data);

// move_enemies_utils_bonus.c

void	move_enemy_right(t_mlx_data *data, int *i, int *j);
void	move_enemy_left(t_mlx_data *data, int *i, int *j);
void	move_enemy_up(t_mlx_data *data, int *i, int *j);
void	move_enemy_down(t_mlx_data *data, int *i, int *j);

// timeout_bonus.c

void	timeout(t_mlx_data *data);

#endif // SO_LONG_H
