/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <tkafanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:48:26 by tkafanov          #+#    #+#             */
/*   Updated: 2024/06/28 14:29:56 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	display_wall(t_mlx_data data, int y, int x)
{
	if (y == 0 || x == 0 || y == data.height - 1
		|| x == data.width - 1)
		put_border(data, y, x);
	else if (is_cross(data, y, x))
		put_cross(data, y, x);
	else if (data.map[y - 1][x] == WALL && data.map[y + 1][x] == WALL)
		mlx_put_image_to_window(data.mlx, data.wdw, data.img.wall_7, \
			x * data.img.w, y * data.img.h);
	else if (data.map[y][x - 1] == WALL && data.map[y][x + 1] == WALL)
		mlx_put_image_to_window(data.mlx, data.wdw, data.img.wall_6, \
			x * data.img.w, y * data.img.h);
	else if (is_corner(data, y, x))
		put_corner(data, y, x);
	else if (data.map[y + 1][x] == WALL || data.map[y - 1][x] == WALL
		|| data.map[y][x + 1] == WALL || data.map[y][x - 1] == WALL)
		put_edge(data, y, x);
	else
		mlx_put_image_to_window(data.mlx, data.wdw, data.img.wall_0, \
			x * data.img.w, y * data.img.h);
}

static void	display_player(t_mlx_data data, int y, int x)
{
	if (data.direction == 0)
		mlx_put_image_to_window(data.mlx, data.wdw, data.img.player_3, \
			x * data.img.w, y * data.img.h);
	else if (data.direction == 1)
		mlx_put_image_to_window(data.mlx, data.wdw, data.img.player_6, \
			x * data.img.w, y * data.img.h);
	else if (data.direction == 2)
		mlx_put_image_to_window(data.mlx, data.wdw, data.img.player_9, \
			x * data.img.w, y * data.img.h);
	else
		mlx_put_image_to_window(data.mlx, data.wdw, data.img.player_12, \
			x * data.img.w, y * data.img.h);
}

static void	display_img(t_mlx_data data, int y, int x)
{
	if (data.map[y][x] == FLOOR)
		mlx_put_image_to_window(data.mlx, data.wdw, data.img.floor, \
			x * data.img.w, y * data.img.h);
	else if (data.map[y][x] == WALL)
		display_wall(data, y, x);
	else if (data.map[y][x] == PLAYER)
		display_player(data, y, x);
	else if (data.map[y][x] == COIN)
		mlx_put_image_to_window(data.mlx, data.wdw, data.img.coin_0, \
			x * data.img.w, y * data.img.h);
	else if (data.map[y][x] == EXIT)
		mlx_put_image_to_window(data.mlx, data.wdw, data.img.exit, \
			x * data.img.w, y * data.img.h);
}

int	display_game(t_mlx_data *data)
{
	int		y;
	int		x;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			display_img(*data, y, x);
			x++;
		}
		y++;
	}
	return (SUCCESS);
}
