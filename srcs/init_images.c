/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <tkafanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 14:31:31 by tkafanov          #+#    #+#             */
/*   Updated: 2024/06/28 14:43:27 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	init_player(t_mlx_data *data)
{
	data->img.player_0 = mlx_xpm_file_to_image(data->mlx, P_IMG_0, \
		&data->img.h, &data->img.w);
	data->img.player_1 = mlx_xpm_file_to_image(data->mlx, P_IMG_1_L, \
		&data->img.h, &data->img.w);
	data->img.player_2 = mlx_xpm_file_to_image(data->mlx, P_IMG_2_L, \
		&data->img.h, &data->img.w);
	data->img.player_3 = mlx_xpm_file_to_image(data->mlx, P_IMG_3_L, \
		&data->img.h, &data->img.w);
	data->img.player_4 = mlx_xpm_file_to_image(data->mlx, P_IMG_1_U, \
		&data->img.h, &data->img.w);
	data->img.player_5 = mlx_xpm_file_to_image(data->mlx, P_IMG_2_U, \
		&data->img.h, &data->img.w);
	data->img.player_6 = mlx_xpm_file_to_image(data->mlx, P_IMG_3_U, \
		&data->img.h, &data->img.w);
	data->img.player_7 = mlx_xpm_file_to_image(data->mlx, P_IMG_1_R, \
		&data->img.h, &data->img.w);
	data->img.player_8 = mlx_xpm_file_to_image(data->mlx, P_IMG_2_R, \
		&data->img.h, &data->img.w);
	data->img.player_9 = mlx_xpm_file_to_image(data->mlx, P_IMG_3_R, \
		&data->img.h, &data->img.w);
	data->img.player_10 = mlx_xpm_file_to_image(data->mlx, P_IMG_1_D, \
		&data->img.h, &data->img.w);
	data->img.player_11 = mlx_xpm_file_to_image(data->mlx, P_IMG_2_D, \
		&data->img.h, &data->img.w);
}

static void	init_coins(t_mlx_data *data)
{
	data->img.coin_0 = mlx_xpm_file_to_image(data->mlx, C_IMG_0, \
		&data->img.h, &data->img.w);
	data->img.coin_1 = mlx_xpm_file_to_image(data->mlx, C_IMG_1, \
		&data->img.h, &data->img.w);
	data->img.coin_2 = mlx_xpm_file_to_image(data->mlx, C_IMG_2, \
		&data->img.h, &data->img.w);
	data->img.coin_3 = mlx_xpm_file_to_image(data->mlx, C_IMG_3, \
		&data->img.h, &data->img.w);
	data->img.coin_4 = mlx_xpm_file_to_image(data->mlx, C_IMG_4, \
		&data->img.h, &data->img.w);
	data->img.coin_5 = mlx_xpm_file_to_image(data->mlx, C_IMG_5, \
		&data->img.h, &data->img.w);
}

static void	init_enemies(t_mlx_data *data)
{
	data->img.enemy_0 = mlx_xpm_file_to_image(data->mlx, ENEMY_RED_0, \
		&data->img.h, &data->img.w);
	data->img.enemy_1 = mlx_xpm_file_to_image(data->mlx, ENEMY_RED_1, \
		&data->img.h, &data->img.w);
	data->img.enemy_2 = mlx_xpm_file_to_image(data->mlx, ENEMY_RED_2, \
		&data->img.h, &data->img.w);
	data->img.enemy_3 = mlx_xpm_file_to_image(data->mlx, ENEMY_GREEN_0, \
		&data->img.h, &data->img.w);
	data->img.enemy_4 = mlx_xpm_file_to_image(data->mlx, ENEMY_GREEN_1, \
		&data->img.h, &data->img.w);
	data->img.enemy_5 = mlx_xpm_file_to_image(data->mlx, ENEMY_GREEN_2, \
		&data->img.h, &data->img.w);
	data->img.enemy_6 = mlx_xpm_file_to_image(data->mlx, ENEMY_SKY_0, \
		&data->img.h, &data->img.w);
	data->img.enemy_7 = mlx_xpm_file_to_image(data->mlx, ENEMY_SKY_1, \
		&data->img.h, &data->img.w);
	data->img.enemy_8 = mlx_xpm_file_to_image(data->mlx, ENEMY_SKY_2, \
		&data->img.h, &data->img.w);
	data->img.enemy_9 = mlx_xpm_file_to_image(data->mlx, ENEMY_PURPLE_0, \
		&data->img.h, &data->img.w);
	data->img.enemy_10 = mlx_xpm_file_to_image(data->mlx, ENEMY_PURPLE_1, \
		&data->img.h, &data->img.w);
	data->img.enemy_11 = mlx_xpm_file_to_image(data->mlx, ENEMY_PURPLE_2, \
		&data->img.h, &data->img.w);
}

static void	init_rest_walls(t_mlx_data *data)
{
	data->img.wall_4 = mlx_xpm_file_to_image(data->mlx, RTL, \
		&data->img.h, &data->img.w);
	data->img.wall_5 = mlx_xpm_file_to_image(data->mlx, RTB, \
		&data->img.h, &data->img.w);
	data->img.wall_6 = mlx_xpm_file_to_image(data->mlx, RL, \
		&data->img.h, &data->img.w);
	data->img.wall_7 = mlx_xpm_file_to_image(data->mlx, TB, \
		&data->img.h, &data->img.w);
	data->img.wall_8 = mlx_xpm_file_to_image(data->mlx, RB, \
		&data->img.h, &data->img.w);
	data->img.wall_9 = mlx_xpm_file_to_image(data->mlx, LB, \
		&data->img.h, &data->img.w);
	data->img.wall_10 = mlx_xpm_file_to_image(data->mlx, RT, \
		&data->img.h, &data->img.w);
	data->img.wall_11 = mlx_xpm_file_to_image(data->mlx, LT, \
		&data->img.h, &data->img.w);
	data->img.wall_12 = mlx_xpm_file_to_image(data->mlx, B, \
		&data->img.h, &data->img.w);
	data->img.wall_13 = mlx_xpm_file_to_image(data->mlx, T, \
		&data->img.h, &data->img.w);
	data->img.wall_14 = mlx_xpm_file_to_image(data->mlx, R, \
		&data->img.h, &data->img.w);
	data->img.wall_15 = mlx_xpm_file_to_image(data->mlx, L, \
		&data->img.h, &data->img.w);
}

void	init_images(t_mlx_data *data)
{
	data->img.w = IMG_W;
	data->img.h = IMG_H;
	init_player(data);
	init_coins(data);
	init_enemies(data);
	init_rest_walls(data);
	data->img.floor = mlx_xpm_file_to_image(data->mlx, FLOOR_IMG, \
		&data->img.h, &data->img.w);
	data->img.exit = mlx_xpm_file_to_image(data->mlx, EXIT_IMG, \
		&data->img.h, &data->img.w);
	data->img.wall_0 = mlx_xpm_file_to_image(data->mlx, WALL_IMG, \
		&data->img.h, &data->img.w);
	data->img.wall_1 = mlx_xpm_file_to_image(data->mlx, RTLB, \
		&data->img.h, &data->img.w);
	data->img.wall_2 = mlx_xpm_file_to_image(data->mlx, RBL, \
		&data->img.h, &data->img.w);
	data->img.wall_3 = mlx_xpm_file_to_image(data->mlx, LTB, \
		&data->img.h, &data->img.w);
	data->img.player_12 = mlx_xpm_file_to_image(data->mlx, P_IMG_3_D, \
		&data->img.h, &data->img.w);
}
