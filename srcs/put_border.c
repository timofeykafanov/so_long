/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_border.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <tkafanov@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:32:26 by tkafanov          #+#    #+#             */
/*   Updated: 2024/06/25 17:02:37 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	*put_top(t_mlx_data data, t_img *img, int y, int x)
{
	if (data.map[y + 1][x] == WALL)
		return (mlx_xpm_file_to_image(data.mlx, RBL, &img->w, &img->h));
	else
		return (mlx_xpm_file_to_image(data.mlx, RL, &img->w, &img->h));
	return (NULL);
}

static void	*put_bot(t_mlx_data data, t_img *img, int y, int x)
{
	if (data.map[y - 1][x] == WALL)
		return (mlx_xpm_file_to_image(data.mlx, RTL, &img->w, &img->h));
	else
		return (mlx_xpm_file_to_image(data.mlx, RL, &img->w, &img->h));
	return (NULL);
}

static void	*put_left(t_mlx_data data, t_img *img, int y, int x)
{
	if (data.map[y][x + 1] == WALL)
		return (mlx_xpm_file_to_image(data.mlx, RTB, &img->w, &img->h));
	else
		return (mlx_xpm_file_to_image(data.mlx, TB, &img->w, &img->h));
	return (NULL);
}

static void	*put_right(t_mlx_data data, t_img *img, int y, int x)
{
	if (data.map[y][x - 1] == WALL)
		return (mlx_xpm_file_to_image(data.mlx, LTB, &img->w, &img->h));
	else
		return (mlx_xpm_file_to_image(data.mlx, TB, &img->w, &img->h));
	return (NULL);
}

void	*put_border(t_mlx_data data, t_img *img, int y, int x)
{
	if (y == 0 && x > 0 && x < count_width(data.map) - 1)
		return (put_top(data, img, y, x));
	else if (y == count_height(data.map) - 1
		&& x > 0 && x < count_width(data.map) - 1)
		return (put_bot(data, img, y, x));
	else if (x == 0 && y > 0 && y < count_height(data.map) - 1)
		return (put_left(data, img, y, x));
	else if (x == count_width(data.map) - 1 && y > 0
		&& y < count_height(data.map) - 1)
		return (put_right(data, img, y, x));
	else if (y == 0 && x == 0)
		return (mlx_xpm_file_to_image(data.mlx, RB, &img->w, &img->h));
	else if (y == 0 && x == count_width(data.map) - 1)
		return (mlx_xpm_file_to_image(data.mlx, LB, &img->w, &img->h));
	else if (y == count_height(data.map) - 1 && x == 0)
		return (mlx_xpm_file_to_image(data.mlx, RT, &img->w, &img->h));
	else if (y == count_height(data.map) - 1 && x == count_width(data.map) - 1)
		return (mlx_xpm_file_to_image(data.mlx, LT, &img->w, &img->h));
	return (NULL);
}
