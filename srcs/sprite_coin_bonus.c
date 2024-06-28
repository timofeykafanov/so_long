/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_coin_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <tkafanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:01:15 by tkafanov          #+#    #+#             */
/*   Updated: 2024/06/28 14:17:04 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	display_coin_sprite(t_mlx_data data, int y, int x, int frame)
{
	if (frame < 2)
		mlx_put_image_to_window(data.mlx, data.wdw, data.img.coin_0, \
			x * data.img.w, y * data.img.h + 45);
	else if (frame < 4)
		mlx_put_image_to_window(data.mlx, data.wdw, data.img.coin_1, \
			x * data.img.w, y * data.img.h + 45);
	else if (frame < 6)
		mlx_put_image_to_window(data.mlx, data.wdw, data.img.coin_2, \
			x * data.img.w, y * data.img.h + 45);
	else if (frame < 8)
		mlx_put_image_to_window(data.mlx, data.wdw, data.img.coin_3, \
			x * data.img.w, y * data.img.h + 45);
	else if (frame < 10)
		mlx_put_image_to_window(data.mlx, data.wdw, data.img.coin_4, \
			x * data.img.w, y * data.img.h + 45);
	else
		mlx_put_image_to_window(data.mlx, data.wdw, data.img.coin_5, \
			x * data.img.w, y * data.img.h + 45);
}
