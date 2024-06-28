/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_enemy_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <tkafanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:17:33 by tkafanov          #+#    #+#             */
/*   Updated: 2024/06/28 14:16:56 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	sprite_red(t_mlx_data data, int y, int x, int frame)
{
	if (frame < 3)
		mlx_put_image_to_window(data.mlx, data.wdw, data.img.enemy_0, \
			x * data.img.w, y * data.img.h + 45);
	else if (frame < 6)
		mlx_put_image_to_window(data.mlx, data.wdw, data.img.enemy_2, \
			x * data.img.w, y * data.img.h + 45);
	else if (frame < 9)
		mlx_put_image_to_window(data.mlx, data.wdw, data.img.enemy_0, \
			x * data.img.w, y * data.img.h + 45);
	else
		mlx_put_image_to_window(data.mlx, data.wdw, data.img.enemy_1, \
			x * data.img.w, y * data.img.h + 45);
}

static void	sprite_purple(t_mlx_data data, int y, int x, int frame)
{
	if (frame < 3)
		mlx_put_image_to_window(data.mlx, data.wdw, data.img.enemy_9, \
			x * data.img.w, y * data.img.h + 45);
	else if (frame < 6)
		mlx_put_image_to_window(data.mlx, data.wdw, data.img.enemy_11, \
			x * data.img.w, y * data.img.h + 45);
	else if (frame < 9)
		mlx_put_image_to_window(data.mlx, data.wdw, data.img.enemy_9, \
			x * data.img.w, y * data.img.h + 45);
	else
		mlx_put_image_to_window(data.mlx, data.wdw, data.img.enemy_10, \
			x * data.img.w, y * data.img.h + 45);
}

static void	sprite_sky(t_mlx_data data, int y, int x, int frame)
{
	if (frame < 3)
		mlx_put_image_to_window(data.mlx, data.wdw, data.img.enemy_6, \
			x * data.img.w, y * data.img.h + 45);
	else if (frame < 6)
		mlx_put_image_to_window(data.mlx, data.wdw, data.img.enemy_8, \
			x * data.img.w, y * data.img.h + 45);
	else if (frame < 9)
		mlx_put_image_to_window(data.mlx, data.wdw, data.img.enemy_6, \
			x * data.img.w, y * data.img.h + 45);
	else
		mlx_put_image_to_window(data.mlx, data.wdw, data.img.enemy_7, \
			x * data.img.w, y * data.img.h + 45);
}

static void	sprite_green(t_mlx_data data, int y, int x, int frame)
{
	if (frame < 3)
		mlx_put_image_to_window(data.mlx, data.wdw, data.img.enemy_3, \
			x * data.img.w, y * data.img.h + 45);
	else if (frame < 6)
		mlx_put_image_to_window(data.mlx, data.wdw, data.img.enemy_5, \
			x * data.img.w, y * data.img.h + 45);
	else if (frame < 9)
		mlx_put_image_to_window(data.mlx, data.wdw, data.img.enemy_3, \
			x * data.img.w, y * data.img.h + 45);
	else
		mlx_put_image_to_window(data.mlx, data.wdw, data.img.enemy_4, \
			x * data.img.w, y * data.img.h + 45);
}

void	display_enemy_sprite(t_mlx_data *data, int y, int x, int frame)
{
	data->enemy++;
	if (data->enemy % 4 == 0)
		sprite_red(*data, y, x, frame);
	else if (data->enemy % 4 == 1)
		sprite_purple(*data, y, x, frame);
	else if (data->enemy % 4 == 2)
		sprite_sky(*data, y, x, frame);
	else
		sprite_green(*data, y, x, frame);
}
