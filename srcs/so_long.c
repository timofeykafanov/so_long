/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <tkafanov@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:15:34 by tkafanov          #+#    #+#             */
/*   Updated: 2024/06/14 14:06:24 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

#include <stdio.h>

// int count_width(char **map) {
//     int width = 0;

//     while (map[0][width] != '\0')
//         width++;
//     return width;
// }

// int count_height(char **map) {
//     int height = 0;

//     while (map[height] != NULL)
//         height++;
//     return height;
// }

// void handle_input(int key, t_mlx_data *data) {
//     if (key == 65307) {  // Escape key
//         mlx_destroy_window(data->connect, data->window);
//         mlx_destroy_display(data->connect);
//         free(data->connect);
//         exit(SUCCESS);
//     }
// }

// int main(void) {
//     t_mlx_data data;
//     t_img img;

//     data.connect = mlx_init();
//     if (!data.connect) {
//         perror("Error initializing mlx");
//         return ERROR;
//     }

//     data.map = ft_split("11111\n10001\n10P01\n10001\n10101", '\n');
//     if (!data.map) {
//         perror("Error splitting map");
//         return ERROR;
//     }

//     img.w = 32;
//     img.h = 32;
//     data.width = count_width(data.map) * img.w;
//     data.height = count_height(data.map) * img.h;

//     img.img = mlx_xpm_file_to_image(data.connect, "./images/hero_opened.xmp", &img.w, &img.h);
//     if (!img.img) {
//         perror("Error loading image");
//         mlx_destroy_display(data.connect);
//         free(data.connect);
//         return ERROR;
//     }

//     data.window = mlx_new_window(data.connect, data.width, data.height, "so_long");
//     if (!data.window) {
//         mlx_destroy_display(data.connect);
//         free(data.connect);
//         return ERROR;
//     }

//     mlx_put_image_to_window(data.connect, data.window, img.img, 32, 32);
//     mlx_key_hook(data.window, (int (*)())handle_input, &data);
//     mlx_loop(data.connect);

//     mlx_destroy_window(data.connect, data.window);
//     mlx_destroy_display(data.connect);
//     free(data.connect);
//     return SUCCESS;
// }

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
	int			x;
	int			y;

	img.w = 32;
	img.h = 32;
	data.map = ft_split("11111\n10001\n10101\n101P1\n11111", '\n');
	if (!data.map)
		return (ERROR);
	data.width = count_width() * img.w;
	data.height = count_height() * img.h;
	data.connect = mlx_init();
	if (!data.connect)
		return (ERROR);
	data.window = mlx_new_window(data.connect, data.width, data.height, "so_long");
	if (!data.window)
		return (mlx_destroy_display(data.connect), free(data.connect), ERROR);
	y = 0;
	while (y < count_width())
	{
		x = 0;
		while (x < count_height())
		{
			if (data.map[y][x] == '1')
			{
				img.img = mlx_xpm_file_to_image(data.connect, "./images/wall.xpm", &img.w, &img.h);
				if (!img.img)
					break ;
			}
			else if (data.map[y][x] == '0')
			{
				img.img = mlx_xpm_file_to_image(data.connect, "./images/floor.xpm", &img.w, &img.h);
				if (!img.img)
					break ;
			}
			else if (data.map[y][x] == 'P')
			{
				img.img = mlx_xpm_file_to_image(data.connect, "./images/hero_opened.xpm", &img.w, &img.h);
				if (!img.img)
					break ;
			}
			mlx_put_image_to_window(data.connect, data.window, img.img, y * img.w, x * img.h);
			x++;
		}
		y++;
	}
	// img.img = mlx_xpm_file_to_image(data.connect, "./images/enemy.xpm", &img.w, &img.h);
	// mlx_put_image_to_window(data.connect, data.window, img.img, 0, 0);
	mlx_key_hook(data.window, handle_input, &data);
	mlx_loop(data.connect);
	mlx_destroy_window(data.connect, data.window);
	mlx_destroy_display(data.connect);
	free(data.connect);
	return (SUCCESS);
}
