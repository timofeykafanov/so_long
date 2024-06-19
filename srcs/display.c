/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <tkafanov@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:48:26 by tkafanov          #+#    #+#             */
/*   Updated: 2024/06/19 18:28:19 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void put_wall(t_mlx_data data, t_img img, char c, t_coord coord)
{
	int	y;
	int	x;

	x = coord.x;
	y = coord.y;
	if (data.[x])


}

static t_img	*return_img(t_mlx_data data, char c, t_coord coord)
{
	static t_img	img = {NULL, IMG_W, IMG_H};

	if (c == WALL)
		put_wall(data, img, c, coord);
	else if (c == FLOOR)
		img.img = mlx_xpm_file_to_image(data.mlx, FLOOR_IMG, &img.w, &img.h);
	else if (c == PLAYER)
		img.img = mlx_xpm_file_to_image(data.mlx, PLAYER_IMG, &img.w, &img.h);
	else if (c == COIN)
		img.img = mlx_xpm_file_to_image(data.mlx, PLAYER_IMG, &img.w, &img.h);
	else if (c == EXIT)
		img.img = mlx_xpm_file_to_image(data.mlx, PLAYER_IMG, &img.w, &img.h);
	else if (c == ENEMY)
		img.img = mlx_xpm_file_to_image(data.mlx, ENEMY_IMG, &img.w, &img.h);
	return (&img);
}

static void	display_img(t_mlx_data data, int y, int x)
{
	t_img	*img;
	t_coord	coord;

	coord.x = x;
	coord.y = y;
	img = return_img(data, data.map[y][x], coord);
	if (!img->img)
		return ;
	mlx_put_image_to_window(data.mlx, data.wdw, img->img, \
		x * img->w, y * img->h);
	mlx_destroy_image(data.mlx, img->img);
}

void	display_game(t_mlx_data data)
{
	int	y;
	int	x;

	y = 0;
	while (y < count_height(data.map))
	{
		x = 0;
		while (x < count_width(data.map))
			display_img(data, y, x++);
		y++;
	}
}
