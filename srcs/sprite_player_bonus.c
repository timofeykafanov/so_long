/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_player_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <tkafanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:29:02 by tkafanov          #+#    #+#             */
/*   Updated: 2024/06/28 14:30:56 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	sprite_left(t_mlx_data data, int y, int x, int frame)
{
	if (frame < 2)
		mlx_put_image_to_window(data.mlx, data.wdw, data.img.player_0, \
			x * data.img.w, y * data.img.h + 45);
	else if (frame < 4)
		mlx_put_image_to_window(data.mlx, data.wdw, data.img.player_1, \
			x * data.img.w, y * data.img.h + 45);
	else if (frame < 6)
		mlx_put_image_to_window(data.mlx, data.wdw, data.img.player_2, \
			x * data.img.w, y * data.img.h + 45);
	else if (frame < 8)
		mlx_put_image_to_window(data.mlx, data.wdw, data.img.player_3, \
			x * data.img.w, y * data.img.h + 45);
	else if (frame < 10)
		mlx_put_image_to_window(data.mlx, data.wdw, data.img.player_2, \
			x * data.img.w, y * data.img.h + 45);
	else
		mlx_put_image_to_window(data.mlx, data.wdw, data.img.player_1, \
			x * data.img.w, y * data.img.h + 45);
}

static void	sprite_up(t_mlx_data data, int y, int x, int frame)
{
	if (frame < 2)
		mlx_put_image_to_window(data.mlx, data.wdw, data.img.player_0, \
			x * data.img.w, y * data.img.h + 45);
	else if (frame < 4)
		mlx_put_image_to_window(data.mlx, data.wdw, data.img.player_4, \
			x * data.img.w, y * data.img.h + 45);
	else if (frame < 6)
		mlx_put_image_to_window(data.mlx, data.wdw, data.img.player_5, \
			x * data.img.w, y * data.img.h + 45);
	else if (frame < 8)
		mlx_put_image_to_window(data.mlx, data.wdw, data.img.player_6, \
			x * data.img.w, y * data.img.h + 45);
	else if (frame < 10)
		mlx_put_image_to_window(data.mlx, data.wdw, data.img.player_5, \
			x * data.img.w, y * data.img.h + 45);
	else
		mlx_put_image_to_window(data.mlx, data.wdw, data.img.player_4, \
			x * data.img.w, y * data.img.h + 45);
}

static void	sprite_right(t_mlx_data data, int y, int x, int frame)
{
	if (frame < 2)
		mlx_put_image_to_window(data.mlx, data.wdw, data.img.player_0, \
			x * data.img.w, y * data.img.h + 45);
	else if (frame < 4)
		mlx_put_image_to_window(data.mlx, data.wdw, data.img.player_7, \
			x * data.img.w, y * data.img.h + 45);
	else if (frame < 6)
		mlx_put_image_to_window(data.mlx, data.wdw, data.img.player_8, \
			x * data.img.w, y * data.img.h + 45);
	else if (frame < 8)
		mlx_put_image_to_window(data.mlx, data.wdw, data.img.player_9, \
			x * data.img.w, y * data.img.h + 45);
	else if (frame < 10)
		mlx_put_image_to_window(data.mlx, data.wdw, data.img.player_8, \
			x * data.img.w, y * data.img.h + 45);
	else
		mlx_put_image_to_window(data.mlx, data.wdw, data.img.player_7, \
			x * data.img.w, y * data.img.h + 45);
}

static void	sprite_down(t_mlx_data data, int y, int x, int frame)
{
	if (frame < 2)
		mlx_put_image_to_window(data.mlx, data.wdw, data.img.player_0, \
			x * data.img.w, y * data.img.h + 45);
	else if (frame < 4)
		mlx_put_image_to_window(data.mlx, data.wdw, data.img.player_10, \
			x * data.img.w, y * data.img.h + 45);
	else if (frame < 6)
		mlx_put_image_to_window(data.mlx, data.wdw, data.img.player_11, \
			x * data.img.w, y * data.img.h + 45);
	else if (frame < 8)
		mlx_put_image_to_window(data.mlx, data.wdw, data.img.player_12, \
			x * data.img.w, y * data.img.h + 45);
	else if (frame < 10)
		mlx_put_image_to_window(data.mlx, data.wdw, data.img.player_11, \
			x * data.img.w, y * data.img.h + 45);
	else
		mlx_put_image_to_window(data.mlx, data.wdw, data.img.player_10, \
			x * data.img.w, y * data.img.h + 45);
}

void	display_player_sprite(t_mlx_data data, int y, int x, int frame)
{
	if (data.direction == 0)
		sprite_left(data, y, x, frame);
	else if (data.direction == 1)
		sprite_up(data, y, x, frame);
	else if (data.direction == 2)
		sprite_right(data, y, x, frame);
	else
		sprite_down(data, y, x, frame);
}
