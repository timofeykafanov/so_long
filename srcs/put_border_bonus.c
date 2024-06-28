/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_border_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <tkafanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 14:06:52 by tkafanov          #+#    #+#             */
/*   Updated: 2024/06/28 14:17:40 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	put_top(t_mlx_data data, int y, int x)
{
	if (data.map[y + 1][x] == WALL)
		mlx_put_image_to_window(data.mlx, data.wdw, data.img.wall_2, \
			x * data.img.w, y * data.img.h + 45);
	else
		mlx_put_image_to_window(data.mlx, data.wdw, data.img.wall_6, \
			x * data.img.w, y * data.img.h + 45);
}

static void	put_bot(t_mlx_data data, int y, int x)
{
	if (data.map[y - 1][x] == WALL)
		mlx_put_image_to_window(data.mlx, data.wdw, data.img.wall_4, \
			x * data.img.w, y * data.img.h + 45);
	else
		mlx_put_image_to_window(data.mlx, data.wdw, data.img.wall_6, \
			x * data.img.w, y * data.img.h + 45);
}

static void	put_left(t_mlx_data data, int y, int x)
{
	if (data.map[y][x + 1] == WALL)
		mlx_put_image_to_window(data.mlx, data.wdw, data.img.wall_5, \
			x * data.img.w, y * data.img.h + 45);
	else
		mlx_put_image_to_window(data.mlx, data.wdw, data.img.wall_7, \
			x * data.img.w, y * data.img.h + 45);
}

static void	put_right(t_mlx_data data, int y, int x)
{
	if (data.map[y][x - 1] == WALL)
		mlx_put_image_to_window(data.mlx, data.wdw, data.img.wall_3, \
			x * data.img.w, y * data.img.h + 45);
	else
		mlx_put_image_to_window(data.mlx, data.wdw, data.img.wall_7, \
			x * data.img.w, y * data.img.h + 45);
}

void	put_border(t_mlx_data data, int y, int x)
{
	if (y == 0 && x > 0 && x < data.width - 1)
		put_top(data, y, x);
	else if (y == data.height - 1 && x > 0 && x < data.width - 1)
		put_bot(data, y, x);
	else if (x == 0 && y > 0 && y < data.height - 1)
		put_left(data, y, x);
	else if (x == data.width - 1 && y > 0
		&& y < data.height - 1)
		put_right(data, y, x);
	else if (y == 0 && x == 0)
		mlx_put_image_to_window(data.mlx, data.wdw, data.img.wall_8, \
			x * data.img.w, y * data.img.h + 45);
	else if (y == 0 && x == data.width - 1)
		mlx_put_image_to_window(data.mlx, data.wdw, data.img.wall_9, \
			x * data.img.w, y * data.img.h + 45);
	else if (y == data.height - 1 && x == 0)
		mlx_put_image_to_window(data.mlx, data.wdw, data.img.wall_10, \
			x * data.img.w, y * data.img.h + 45);
	else if (y == data.height - 1 && x == data.width - 1)
		mlx_put_image_to_window(data.mlx, data.wdw, data.img.wall_11, \
			x * data.img.w, y * data.img.h + 45);
}
