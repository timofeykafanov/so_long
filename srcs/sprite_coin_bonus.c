/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_coin_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <tkafanov@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:01:15 by tkafanov          #+#    #+#             */
/*   Updated: 2024/06/26 14:05:09 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	*put_coin_sprite(t_mlx_data data, t_img *img, int frame)
{
	if (frame < 2)
		return (mlx_xpm_file_to_image(data.mlx, C_IMG_0, &img->w, &img->h));
	else if (frame < 4)
		return (mlx_xpm_file_to_image(data.mlx, C_IMG_1, &img->w, &img->h));
	else if (frame < 6)
		return (mlx_xpm_file_to_image(data.mlx, C_IMG_2, &img->w, &img->h));
	else if (frame < 8)
		return (mlx_xpm_file_to_image(data.mlx, C_IMG_3, &img->w, &img->h));
	else if (frame < 10)
		return (mlx_xpm_file_to_image(data.mlx, C_IMG_4, &img->w, &img->h));
	else
		return (mlx_xpm_file_to_image(data.mlx, C_IMG_5, &img->w, &img->h));
	return (NULL);
}
