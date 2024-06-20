/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <tkafanov@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:14:08 by tkafanov          #+#    #+#             */
/*   Updated: 2024/06/20 16:16:58 by tkafanov         ###   ########.fr       */
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

void	*put_cross(t_mlx_data data, t_img *img, int y, int x)
{
	if (data.map[y][x - 1] == WALL && data.map[y][x + 1] == WALL
		&& data.map[y - 1][x] == WALL && data.map[y + 1][x] == WALL)
		return (mlx_xpm_file_to_image(data.mlx, RTLB, &img->w, &img->h));
	else if (data.map[y][x - 1] == WALL
		&& data.map[y][x + 1] == WALL && data.map[y - 1][x] == WALL)
		return (mlx_xpm_file_to_image(data.mlx, RTL, &img->w, &img->h));
	else if (data.map[y][x - 1] == WALL
		&& data.map[y][x + 1] == WALL && data.map[y + 1][x] == WALL)
		return (mlx_xpm_file_to_image(data.mlx, RBL, &img->w, &img->h));
	else if (data.map[y][x - 1] == WALL
		&& data.map[y - 1][x] == WALL && data.map[y + 1][x] == WALL)
		return (mlx_xpm_file_to_image(data.mlx, LTB, &img->w, &img->h));
	else if (data.map[y][x + 1] == WALL
		&& data.map[y - 1][x] == WALL && data.map[y + 1][x] == WALL)
		return (mlx_xpm_file_to_image(data.mlx, RTB, &img->w, &img->h));
	return (NULL);
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

void	*put_corner(t_mlx_data data, t_img *img, int y, int x)
{
	if (data.map[y][x - 1] == WALL && data.map[y + 1][x] == WALL)
		return (mlx_xpm_file_to_image(data.mlx, LB, &img->w, &img->h));
	else if (data.map[y][x - 1] == WALL && data.map[y - 1][x] == WALL)
		return (mlx_xpm_file_to_image(data.mlx, LT, &img->w, &img->h));
	else if (data.map[y - 1][x] == WALL && data.map[y][x + 1] == WALL)
		return (mlx_xpm_file_to_image(data.mlx, RT, &img->w, &img->h));
	else if (data.map[y + 1][x] == WALL && data.map[y][x + 1] == WALL)
		return (mlx_xpm_file_to_image(data.mlx, RB, &img->w, &img->h));
	return (NULL);
}
