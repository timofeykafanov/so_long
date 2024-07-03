/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_images.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <tkafanov@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 08:33:57 by tkafanov          #+#    #+#             */
/*   Updated: 2024/07/03 08:58:34 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

bool	check_images(t_mlx_data *data)
{
	if (data->img.floor && data->img.exit && data->img.coin_0
		&& data->img.coin_1 && data->img.coin_2 && data->img.coin_3
		&& data->img.coin_4 && data->img.coin_5 && data->img.wall_0
		&& data->img.wall_1 && data->img.wall_2 && data->img.wall_3
		&& data->img.wall_4 && data->img.wall_5 && data->img.wall_6
		&& data->img.wall_7 && data->img.wall_8 && data->img.wall_9
		&& data->img.wall_10 && data->img.wall_11 && data->img.wall_12
		&& data->img.wall_13 && data->img.wall_14 && data->img.wall_15
		&& data->img.enemy_0 && data->img.enemy_1 && data->img.enemy_2
		&& data->img.enemy_3 && data->img.enemy_4 && data->img.enemy_5
		&& data->img.enemy_6 && data->img.enemy_7 && data->img.enemy_8
		&& data->img.enemy_9 && data->img.enemy_10 && data->img.enemy_11
		&& data->img.player_0 && data->img.player_1 && data->img.player_2
		&& data->img.player_3 && data->img.player_4 && data->img.player_5
		&& data->img.player_6 && data->img.player_7 && data->img.player_8
		&& data->img.player_9 && data->img.player_10 && data->img.player_11
		&& data->img.player_12)
		return (true);
	else
		return (false);
}
