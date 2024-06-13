/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <tkafanov@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:15:34 by tkafanov          #+#    #+#             */
/*   Updated: 2024/06/13 17:21:53 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

#include <stdio.h>

int	handle_input(int key, t_mlx_data *data)
{
	if (key == ESC)
	{
		printf("The %d key (ESC) has been pressed\n", key);
		mlx_destroy_window(data->connect, data->window);
		mlx_destroy_display(data->connect);
		free(data->connect);
		exit(1);
	}
	printf("The %d key has been pressed\n", key);
	return (SUCCESS);
}

int	count_width()
{
	return (5);
}

int	count_height()
{
	return (5);
}

int	main(void)
{
	t_mlx_data	data;
	t_img		img;

	data.connect = mlx_init();
	data.map = ft_split("11111\n10001\n10P01\n10001\n10101", '\n');
	img.w = 32;
	img.h = 32;
	data.width = count_width() * img.w;
	data.height = count_height() * img.h;
	img.img = mlx_xpm_file_to_image(data.connect, "../images/hero_opened.xmp", &img.w, &img.h);
	if (!data.connect)
		return (ERROR);
	data.window = mlx_new_window(data.connect, data.width, data.height, "so_long");
	if (!data.window)
		return (mlx_destroy_display(data.connect), free(data.connect), ERROR);
	mlx_key_hook(data.window, handle_input, &data);
	mlx_loop(data.connect);
	mlx_destroy_window(data.connect, data.window);
	mlx_destroy_display(data.connect);
	free(data.connect);
	return (SUCCESS);
}
