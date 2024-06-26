/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <tkafanov@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:16:17 by tkafanov          #+#    #+#             */
/*   Updated: 2024/06/26 14:04:44 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
// # include "../minilibx-linux/mlx.h"
# include <mlx.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdbool.h>

#include <stdio.h>

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

# define WALL '1'
# define FLOOR '0'
# define PLAYER 'P'
# define COIN 'C'
# define EXIT 'E'
# define ENEMY 'G'
# define FILL 'F'

# define NEW_LINE '\n'

# define P_IMG_0 "./images/hero/sprite_0.xpm"

# define P_IMG_1_L "./images/hero/sprite_1_l.xpm"
# define P_IMG_2_L "./images/hero/sprite_2_l.xpm"
# define P_IMG_3_L "./images/hero/sprite_3_l.xpm"

# define P_IMG_1_U "./images/hero/sprite_1_u.xpm"
# define P_IMG_2_U "./images/hero/sprite_2_u.xpm"
# define P_IMG_3_U "./images/hero/sprite_3_u.xpm"

# define P_IMG_1_R "./images/hero/sprite_1_r.xpm"
# define P_IMG_2_R "./images/hero/sprite_2_r.xpm"
# define P_IMG_3_R "./images/hero/sprite_3_r.xpm"

# define P_IMG_1_D "./images/hero/sprite_1_d.xpm"
# define P_IMG_2_D "./images/hero/sprite_2_d.xpm"
# define P_IMG_3_D "./images/hero/sprite_3_d.xpm"

# define ENEMY_IMG "./images/enemy/enemy.xpm"

# define FLOOR_IMG "./images/floor/floor.xpm"

# define C_IMG_0 "./images/coins/coin1.xpm"
# define C_IMG_1 "./images/coins/coin2.xpm"
# define C_IMG_2 "./images/coins/coin3.xpm"
# define C_IMG_3 "./images/coins/coin4.xpm"
# define C_IMG_4 "./images/coins/coin55.xpm"
# define C_IMG_5 "./images/coins/coin6.xpm"

# define EXIT_IMG "./images/exit/color.xpm"

# define WALL_IMG "./images/walls/wall.xpm"
# define RTLB "./images/walls/wall_rtlb.xpm"
# define RBL "./images/walls/wall_rbl.xpm"
# define LTB "./images/walls/wall_ltb.xpm"
# define RTL "./images/walls/wall_rtl.xpm"
# define RTB "./images/walls/wall_rtb.xpm"
# define RL "./images/walls/wall_rl.xpm"
# define TB "./images/walls/wall_tb.xpm"
# define RB "./images/walls/wall_rb.xpm"
# define LB "./images/walls/wall_lb.xpm"
# define RT "./images/walls/wall_rt.xpm"
# define LT "./images/walls/wall_lt.xpm"
# define B "./images/walls/wall_b.xpm"
# define T "./images/walls/wall_t.xpm"
# define R "./images/walls/wall_r.xpm"
# define L "./images/walls/wall_l.xpm"

# define ERR_MESS_PER "Error\nThe map should be surrounded by walls!\n"
# define ERR_MESS_EXTEN "Error\nInvalid file extention!\n"
# define ERR_MESS_FILE "Error\nFile doesn't exist!\n"
# define ERR_MESS_SHAPE "Error\nMap should be rectangular!\n"
# define ERR_MESS_PLAYER "Error\nThere should be 1 player!\n"
# define ERR_MESS_EXIT "Error\nThere should be 1 exit!\n"
# define ERR_MESS_COINS "Error\nThere should be at least 1 collectible!\n"
# define ERR_MESS_READ "Error\nRrror reading file!\n"
# define ERR_MESS_EMPTY "Error\nEmpty map!\n"
# define ERR_MESS_PATH "Error\nThere is no valid path!\n"
# define ERR_MESS_SYMB "Error\nInvalid symbol found!\n"

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

// flood_fill.c

bool	has_valid_path(t_mlx_data *data);

// symbol_check.c

bool	has_only_valid_symbols(char **map);

// close.c

void	close_game(t_mlx_data *data);

// sprite_player_bonus.c

void	*put_player_sprite(t_mlx_data data, t_img *img, int frame);

// sprite_coin_bonus.c

void	*put_coin_sprite(t_mlx_data data, t_img *img, int frame);

#endif // SO_LONG_H
