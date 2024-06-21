/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <tkafanov@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:16:17 by tkafanov          #+#    #+#             */
/*   Updated: 2024/06/21 11:09:29 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "mlx.h"
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

# define PLAYER_IMG "./images/hero/hero_opened.xpm"
# define ENEMY_IMG "./images/hero/hero_closed.xpm"

# define FLOOR_IMG "./images/floor/floor.xpm"

# define COIN_IMG "./images/coins/coin.xpm"

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

typedef struct s_mlx_data
{
	void	*mlx;
	void	*wdw;
	int		width;
	int		height;
	char	**map;
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

// free.c

void	free_map(char **map);

// put_border.c

void	*put_border(t_mlx_data data, t_img *img, int y, int x);

// display.c

void	display_game(t_mlx_data data);

// display_utils.c
bool	is_cross(t_mlx_data data, int y, int x);
bool	is_corner(t_mlx_data data, int y, int x);
void	*put_cross(t_mlx_data data, t_img *img, int y, int x);
void	*put_corner(t_mlx_data data, t_img *img, int y, int x);

// map.c

int		count_width(char **map);
int		count_height(char **map);
char	**read_map(char *file_name);
bool	is_map_valid(char **map);

// movements.c

void	move_up(t_mlx_data *data);
void	move_down(t_mlx_data *data);
void	move_right(t_mlx_data *data);
void	move_left(t_mlx_data *data);

#endif // SO_LONG_H
