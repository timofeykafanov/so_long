/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <tkafanov@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:16:17 by tkafanov          #+#    #+#             */
/*   Updated: 2024/06/18 15:21:24 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "mlx.h"
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdbool.h>

# define SUCCESS 0
# define ERROR 1

# define IMG_H 32
# define IMG_W 32

# define ESC 65307
# define UP 119
# define LEFT 97
# define DOWN 115
# define RIGHT 100

# define WALL '1'
# define FLOOR '0'
# define PLAYER 'P'

# define WALL_IMG "./images/wall.xpm"
# define FLOOR_IMG "./images/floor.xpm"
# define PLAYER_IMG "./images/hero_opened.xpm"

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

// free.c

void	free_map(char **map);

// display.c

void	display_game(t_mlx_data data);

// map.c

int		count_width(char **map);
int		count_height(char **map);
char	**read_map(char *file_name);
bool	is_map_valid(char **map);

#endif // SO_LONG_H
