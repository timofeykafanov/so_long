/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <tkafanov@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:29:02 by tkafanov          #+#    #+#             */
/*   Updated: 2024/06/26 13:48:06 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	*sprite_left(t_mlx_data data, t_img *img, int frame)
{
	if (frame < 2)
		return (mlx_xpm_file_to_image(data.mlx, P_IMG_0, &img->w, &img->h));
	else if (frame < 4)
		return (mlx_xpm_file_to_image(data.mlx, P_IMG_1_L, &img->w, &img->h));
	else if (frame < 6)
		return (mlx_xpm_file_to_image(data.mlx, P_IMG_2_L, &img->w, &img->h));
	else if (frame < 8)
		return (mlx_xpm_file_to_image(data.mlx, P_IMG_3_L, &img->w, &img->h));
	else if (frame < 10)
		return (mlx_xpm_file_to_image(data.mlx, P_IMG_2_L, &img->w, &img->h));
	else
		return (mlx_xpm_file_to_image(data.mlx, P_IMG_1_L, &img->w, &img->h));
	return (NULL);
}

static void	*sprite_up(t_mlx_data data, t_img *img, int frame)
{
	if (frame < 2)
		return (mlx_xpm_file_to_image(data.mlx, P_IMG_0, &img->w, &img->h));
	else if (frame < 4)
		return (mlx_xpm_file_to_image(data.mlx, P_IMG_1_U, &img->w, &img->h));
	else if (frame < 6)
		return (mlx_xpm_file_to_image(data.mlx, P_IMG_2_U, &img->w, &img->h));
	else if (frame < 8)
		return (mlx_xpm_file_to_image(data.mlx, P_IMG_3_U, &img->w, &img->h));
	else if (frame < 10)
		return (mlx_xpm_file_to_image(data.mlx, P_IMG_2_U, &img->w, &img->h));
	else
		return (mlx_xpm_file_to_image(data.mlx, P_IMG_1_U, &img->w, &img->h));
	return (NULL);
}

static void	*sprite_right(t_mlx_data data, t_img *img, int frame)
{
	if (frame < 2)
		return (mlx_xpm_file_to_image(data.mlx, P_IMG_0, &img->w, &img->h));
	else if (frame < 4)
		return (mlx_xpm_file_to_image(data.mlx, P_IMG_1_R, &img->w, &img->h));
	else if (frame < 6)
		return (mlx_xpm_file_to_image(data.mlx, P_IMG_2_R, &img->w, &img->h));
	else if (frame < 8)
		return (mlx_xpm_file_to_image(data.mlx, P_IMG_3_R, &img->w, &img->h));
	else if (frame < 10)
		return (mlx_xpm_file_to_image(data.mlx, P_IMG_2_R, &img->w, &img->h));
	else
		return (mlx_xpm_file_to_image(data.mlx, P_IMG_1_R, &img->w, &img->h));
	return (NULL);
}

static void	*sprite_down(t_mlx_data data, t_img *img, int frame)
{
	if (frame < 2)
		return (mlx_xpm_file_to_image(data.mlx, P_IMG_0, &img->w, &img->h));
	else if (frame < 4)
		return (mlx_xpm_file_to_image(data.mlx, P_IMG_1_D, &img->w, &img->h));
	else if (frame < 6)
		return (mlx_xpm_file_to_image(data.mlx, P_IMG_2_D, &img->w, &img->h));
	else if (frame < 8)
		return (mlx_xpm_file_to_image(data.mlx, P_IMG_3_D, &img->w, &img->h));
	else if (frame < 10)
		return (mlx_xpm_file_to_image(data.mlx, P_IMG_2_D, &img->w, &img->h));
	else
		return (mlx_xpm_file_to_image(data.mlx, P_IMG_1_D, &img->w, &img->h));
	return (NULL);
}

void	*put_player_sprite(t_mlx_data data, t_img *img, int frame)
{
	if (data.direction == 0)
		return (sprite_left(data, img, frame));
	else if (data.direction == 1)
		return (sprite_up(data, img, frame));
	else if (data.direction == 2)
		return (sprite_right(data, img, frame));
	else
		return (sprite_down(data, img, frame));
	return (NULL);
}
