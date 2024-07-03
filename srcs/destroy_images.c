/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_images.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <tkafanov@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 14:44:35 by tkafanov          #+#    #+#             */
/*   Updated: 2024/07/03 08:58:04 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	destroy_images_enemy(t_mlx_data *data)
{
	if (data->img.enemy_0)
		mlx_destroy_image(data->mlx, data->img.enemy_0);
	if (data->img.enemy_1)
		mlx_destroy_image(data->mlx, data->img.enemy_1);
	if (data->img.enemy_2)
		mlx_destroy_image(data->mlx, data->img.enemy_2);
	if (data->img.enemy_3)
		mlx_destroy_image(data->mlx, data->img.enemy_3);
	if (data->img.enemy_4)
		mlx_destroy_image(data->mlx, data->img.enemy_4);
	if (data->img.enemy_5)
		mlx_destroy_image(data->mlx, data->img.enemy_5);
	if (data->img.enemy_6)
		mlx_destroy_image(data->mlx, data->img.enemy_6);
	if (data->img.enemy_7)
		mlx_destroy_image(data->mlx, data->img.enemy_7);
	if (data->img.enemy_8)
		mlx_destroy_image(data->mlx, data->img.enemy_8);
	if (data->img.enemy_9)
		mlx_destroy_image(data->mlx, data->img.enemy_9);
	if (data->img.enemy_10)
		mlx_destroy_image(data->mlx, data->img.enemy_10);
	if (data->img.enemy_11)
		mlx_destroy_image(data->mlx, data->img.enemy_11);
}

static void	destroy_images_player(t_mlx_data *data)
{
	if (data->img.player_0)
		mlx_destroy_image(data->mlx, data->img.player_0);
	if (data->img.player_1)
		mlx_destroy_image(data->mlx, data->img.player_1);
	if (data->img.player_2)
		mlx_destroy_image(data->mlx, data->img.player_2);
	if (data->img.player_3)
		mlx_destroy_image(data->mlx, data->img.player_3);
	if (data->img.player_4)
		mlx_destroy_image(data->mlx, data->img.player_4);
	if (data->img.player_5)
		mlx_destroy_image(data->mlx, data->img.player_5);
	if (data->img.player_6)
		mlx_destroy_image(data->mlx, data->img.player_6);
	if (data->img.player_7)
		mlx_destroy_image(data->mlx, data->img.player_7);
	if (data->img.player_8)
		mlx_destroy_image(data->mlx, data->img.player_8);
	if (data->img.player_9)
		mlx_destroy_image(data->mlx, data->img.player_9);
	if (data->img.player_10)
		mlx_destroy_image(data->mlx, data->img.player_10);
	if (data->img.player_11)
		mlx_destroy_image(data->mlx, data->img.player_11);
}

static void	destroy_images_wall(t_mlx_data *data)
{
	if (data->img.wall_0)
		mlx_destroy_image(data->mlx, data->img.wall_0);
	if (data->img.wall_1)
		mlx_destroy_image(data->mlx, data->img.wall_1);
	if (data->img.wall_2)
		mlx_destroy_image(data->mlx, data->img.wall_2);
	if (data->img.wall_3)
		mlx_destroy_image(data->mlx, data->img.wall_3);
	if (data->img.wall_4)
		mlx_destroy_image(data->mlx, data->img.wall_4);
	if (data->img.wall_5)
		mlx_destroy_image(data->mlx, data->img.wall_5);
	if (data->img.wall_6)
		mlx_destroy_image(data->mlx, data->img.wall_6);
	if (data->img.wall_7)
		mlx_destroy_image(data->mlx, data->img.wall_7);
	if (data->img.wall_8)
		mlx_destroy_image(data->mlx, data->img.wall_8);
	if (data->img.wall_9)
		mlx_destroy_image(data->mlx, data->img.wall_9);
	if (data->img.wall_10)
		mlx_destroy_image(data->mlx, data->img.wall_10);
	if (data->img.wall_11)
		mlx_destroy_image(data->mlx, data->img.wall_11);
}

static void	destroy_images_helper(t_mlx_data *data)
{
	if (data->img.player_12)
		mlx_destroy_image(data->mlx, data->img.player_12);
	if (data->img.wall_12)
		mlx_destroy_image(data->mlx, data->img.wall_12);
	if (data->img.wall_13)
		mlx_destroy_image(data->mlx, data->img.wall_13);
	if (data->img.wall_14)
		mlx_destroy_image(data->mlx, data->img.wall_14);
	if (data->img.wall_15)
		mlx_destroy_image(data->mlx, data->img.wall_15);
}

void	destroy_images(t_mlx_data *data)
{
	destroy_images_enemy(data);
	destroy_images_player(data);
	destroy_images_wall(data);
	destroy_images_helper(data);
	if (data->img.floor)
		mlx_destroy_image(data->mlx, data->img.floor);
	if (data->img.exit)
		mlx_destroy_image(data->mlx, data->img.exit);
	if (data->img.coin_0)
		mlx_destroy_image(data->mlx, data->img.coin_0);
	if (data->img.coin_1)
		mlx_destroy_image(data->mlx, data->img.coin_1);
	if (data->img.coin_2)
		mlx_destroy_image(data->mlx, data->img.coin_2);
	if (data->img.coin_3)
		mlx_destroy_image(data->mlx, data->img.coin_3);
	if (data->img.coin_4)
		mlx_destroy_image(data->mlx, data->img.coin_4);
	if (data->img.coin_5)
		mlx_destroy_image(data->mlx, data->img.coin_5);
}
