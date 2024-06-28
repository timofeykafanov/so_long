/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <tkafanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 14:08:39 by tkafanov          #+#    #+#             */
/*   Updated: 2024/06/28 14:28:16 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

bool	is_cross(t_mlx_data data, int y, int x)
{
	bool	rtlb;
	bool	rtl;
	bool	rbl;
	bool	ltb;
	bool	rtb;

	rtlb = data.map[y][x - 1] == WALL && data.map[y][x + 1] == WALL
		&& data.map[y - 1][x] == WALL && data.map[y + 1][x] == WALL;
	rtl = data.map[y][x - 1] == WALL
		&& data.map[y][x + 1] == WALL && data.map[y - 1][x] == WALL;
	rbl = data.map[y][x - 1] == WALL
		&& data.map[y][x + 1] == WALL && data.map[y + 1][x] == WALL;
	ltb = data.map[y][x - 1] == WALL
		&& data.map[y - 1][x] == WALL && data.map[y + 1][x] == WALL;
	rtb = data.map[y][x + 1] == WALL
		&& data.map[y - 1][x] == WALL && data.map[y + 1][x] == WALL;
	return (rtlb || rtl || rbl || ltb || rtb);
}

void	put_cross(t_mlx_data data, int y, int x)
{
	if (data.map[y][x - 1] == WALL && data.map[y][x + 1] == WALL
		&& data.map[y - 1][x] == WALL && data.map[y + 1][x] == WALL)
		mlx_put_image_to_window(data.mlx, data.wdw, data.img.wall_1, \
			x * data.img.w, y * data.img.h + 45);
	else if (data.map[y][x - 1] == WALL
		&& data.map[y][x + 1] == WALL && data.map[y - 1][x] == WALL)
		mlx_put_image_to_window(data.mlx, data.wdw, data.img.wall_4, \
			x * data.img.w, y * data.img.h + 45);
	else if (data.map[y][x - 1] == WALL
		&& data.map[y][x + 1] == WALL && data.map[y + 1][x] == WALL)
		mlx_put_image_to_window(data.mlx, data.wdw, data.img.wall_2, \
			x * data.img.w, y * data.img.h + 45);
	else if (data.map[y][x - 1] == WALL
		&& data.map[y - 1][x] == WALL && data.map[y + 1][x] == WALL)
		mlx_put_image_to_window(data.mlx, data.wdw, data.img.wall_3, \
			x * data.img.w, y * data.img.h + 45);
	else if (data.map[y][x + 1] == WALL
		&& data.map[y - 1][x] == WALL && data.map[y + 1][x] == WALL)
		mlx_put_image_to_window(data.mlx, data.wdw, data.img.wall_5, \
			x * data.img.w, y * data.img.h + 45);
}

bool	is_corner(t_mlx_data data, int y, int x)
{
	bool	lb;
	bool	lt;
	bool	rt;
	bool	rb;

	lb = data.map[y][x - 1] == WALL && data.map[y + 1][x] == WALL;
	lt = data.map[y][x - 1] == WALL && data.map[y - 1][x] == WALL;
	rt = data.map[y - 1][x] == WALL && data.map[y][x + 1] == WALL;
	rb = data.map[y + 1][x] == WALL && data.map[y][x + 1] == WALL;
	return (lb || lt || rt || rb);
}

void	put_corner(t_mlx_data data, int y, int x)
{
	if (data.map[y][x - 1] == WALL && data.map[y + 1][x] == WALL)
		mlx_put_image_to_window(data.mlx, data.wdw, data.img.wall_9, x \
			* data.img.w, y * data.img.h + 45);
	else if (data.map[y][x - 1] == WALL && data.map[y - 1][x] == WALL)
		mlx_put_image_to_window(data.mlx, data.wdw, data.img.wall_11, x \
			* data.img.w, y * data.img.h + 45);
	else if (data.map[y - 1][x] == WALL && data.map[y][x + 1] == WALL)
		mlx_put_image_to_window(data.mlx, data.wdw, data.img.wall_10, x \
			* data.img.w, y * data.img.h + 45);
	else if (data.map[y + 1][x] == WALL && data.map[y][x + 1] == WALL)
		mlx_put_image_to_window(data.mlx, data.wdw, data.img.wall_8, x \
			* data.img.w, y * data.img.h + 45);
}

void	put_edge(t_mlx_data data, int y, int x)
{
	if (data.map[y + 1][x] == WALL)
		mlx_put_image_to_window(data.mlx, data.wdw, data.img.wall_12, x \
			* data.img.w, y * data.img.h + 45);
	else if (data.map[y - 1][x] == WALL)
		mlx_put_image_to_window(data.mlx, data.wdw, data.img.wall_13, x \
			* data.img.w, y * data.img.h + 45);
	else if (data.map[y][x + 1] == WALL)
		mlx_put_image_to_window(data.mlx, data.wdw, data.img.wall_14, x \
			* data.img.w, y * data.img.h + 45);
	else if (data.map[y][x - 1] == WALL)
		mlx_put_image_to_window(data.mlx, data.wdw, data.img.wall_15, x \
			* data.img.w, y * data.img.h + 45);
}
