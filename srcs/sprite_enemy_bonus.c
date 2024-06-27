/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_enemy_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <tkafanov@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:17:33 by tkafanov          #+#    #+#             */
/*   Updated: 2024/06/27 09:48:00 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	*sprite_red(t_mlx_data data, t_img *img, int frame)
{
	if (frame < 3)
		return (mlx_xpm_file_to_image(data.mlx, ENEMY_RED_0, &img->w, &img->h));
	else if (frame < 6)
		return (mlx_xpm_file_to_image(data.mlx, ENEMY_RED_1, &img->w, &img->h));
	else if (frame < 9)
		return (mlx_xpm_file_to_image(data.mlx, ENEMY_RED_0, &img->w, &img->h));
	else
		return (mlx_xpm_file_to_image(data.mlx, ENEMY_RED_2, &img->w, &img->h));
	return (NULL);
}

static void	*sprite_purple(t_mlx_data data, t_img *img, int frame)
{
	if (frame < 3)
		return (mlx_xpm_file_to_image(data.mlx, ENEMY_PURPLE_0, \
		&img->w, &img->h));
	else if (frame < 6)
		return (mlx_xpm_file_to_image(data.mlx, ENEMY_PURPLE_1, \
		&img->w, &img->h));
	else if (frame < 9)
		return (mlx_xpm_file_to_image(data.mlx, ENEMY_PURPLE_0, \
		&img->w, &img->h));
	else
		return (mlx_xpm_file_to_image(data.mlx, ENEMY_PURPLE_2, \
		&img->w, &img->h));
	return (NULL);
}

static void	*sprite_sky(t_mlx_data data, t_img *img, int frame)
{
	if (frame < 3)
		return (mlx_xpm_file_to_image(data.mlx, ENEMY_SKY_0, &img->w, &img->h));
	else if (frame < 6)
		return (mlx_xpm_file_to_image(data.mlx, ENEMY_SKY_1, &img->w, &img->h));
	else if (frame < 9)
		return (mlx_xpm_file_to_image(data.mlx, ENEMY_SKY_0, &img->w, &img->h));
	else
		return (mlx_xpm_file_to_image(data.mlx, ENEMY_SKY_2, &img->w, &img->h));
	return (NULL);
}

static void	*sprite_green(t_mlx_data data, t_img *img, int frame)
{
	if (frame < 3)
		return (mlx_xpm_file_to_image(data.mlx, ENEMY_GREEN_0, \
		&img->w, &img->h));
	else if (frame < 6)
		return (mlx_xpm_file_to_image(data.mlx, ENEMY_GREEN_1, \
		&img->w, &img->h));
	else if (frame < 9)
		return (mlx_xpm_file_to_image(data.mlx, ENEMY_GREEN_0, \
		&img->w, &img->h));
	else
		return (mlx_xpm_file_to_image(data.mlx, ENEMY_GREEN_2, \
		&img->w, &img->h));
	return (NULL);
}

void	*put_enemy_sprite(t_mlx_data *data, t_img *img, int frame)
{
	data->enemy++;
	if (data->enemy % 4 == 0)
		return (sprite_red(*data, img, frame));
	else if (data->enemy % 4 == 1)
		return (sprite_purple(*data, img, frame));
	else if (data->enemy % 4 == 2)
		return (sprite_sky(*data, img, frame));
	else
		return (sprite_green(*data, img, frame));
	return (NULL);
}
