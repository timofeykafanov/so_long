/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <tkafanov@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:48:26 by tkafanov          #+#    #+#             */
/*   Updated: 2024/06/18 15:18:32 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static t_img	*return_img(t_mlx_data data, char c)
{
	static t_img	img = {NULL, IMG_W, IMG_H};
	if (c == WALL)
		img.img = mlx_xpm_file_to_image(data.mlx, WALL_IMG, &img.w, &img.h);
	else if (c == FLOOR)
		img.img = mlx_xpm_file_to_image(data.mlx, FLOOR_IMG, &img.w, &img.h);
	else if (c == PLAYER)
		img.img = mlx_xpm_file_to_image(data.mlx, PLAYER_IMG, &img.w, &img.h);
	return (&img);
}

static void display_img(t_mlx_data data, int y, int x)
{
	t_img	*img;

	img = return_img(data, data.map[y][x]);
	if (!img->img)
		return ;
	mlx_put_image_to_window(data.mlx, data.wdw, img->img, x * img->w, y * img->h);
	mlx_destroy_image(data.mlx, img->img);
}

void display_game(t_mlx_data data)
{
	int 	y;
	int		x;

	y = 0;
	while (y < count_height(data.map))
	{
		x = 0;
		while (x < count_width(data.map))
			display_img(data, y, x++);
		y++;
	}
}
