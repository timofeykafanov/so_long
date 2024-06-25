/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <tkafanov@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:48:26 by tkafanov          #+#    #+#             */
/*   Updated: 2024/06/25 17:25:38 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <unistd.h>

static void	*put_wall(t_mlx_data data, t_img *img, int y, int x)
{
	if (y == 0 || x == 0 || y == count_height(data.map) - 1
		|| x == count_width(data.map) - 1)
		return (put_border(data, img, y, x));
	else if (is_cross(data, y, x))
		return (put_cross(data, img, y, x));
	else if (data.map[y - 1][x] == WALL && data.map[y + 1][x] == WALL)
		return (mlx_xpm_file_to_image(data.mlx, TB, &img->w, &img->h));
	else if (data.map[y][x - 1] == WALL && data.map[y][x + 1] == WALL)
		return (mlx_xpm_file_to_image(data.mlx, RL, &img->w, &img->h));
	else if (is_corner(data, y, x))
		return (put_corner(data, img, y, x));
	else if (data.map[y + 1][x] == WALL)
		return (mlx_xpm_file_to_image(data.mlx, B, &img->w, &img->h));
	else if (data.map[y - 1][x] == WALL)
		return (mlx_xpm_file_to_image(data.mlx, T, &img->w, &img->h));
	else if (data.map[y][x + 1] == WALL)
		return (mlx_xpm_file_to_image(data.mlx, R, &img->w, &img->h));
	else if (data.map[y][x - 1] == WALL)
		return (mlx_xpm_file_to_image(data.mlx, L, &img->w, &img->h));
	else
		return (mlx_xpm_file_to_image(data.mlx, WALL_IMG, &img->w, &img->h));
	return (NULL);
}

static t_img	*put_img(t_mlx_data data, char c, int y, int x, int frame)
{
	static t_img	img = {NULL, IMG_W, IMG_H};

	if (c == WALL)
		img.img = put_wall(data, &img, y, x);
	else if (c == FLOOR)
		img.img = mlx_xpm_file_to_image(data.mlx, FLOOR_IMG, &img.w, &img.h);
	else if (c == PLAYER)
	{
		if (frame < 2)
			img.img = mlx_xpm_file_to_image(data.mlx, P_IMG_0, &img.w, &img.h);
		else if (frame < 4)
			img.img = mlx_xpm_file_to_image(data.mlx, P_IMG_1, &img.w, &img.h);
		else if (frame < 6)
			img.img = mlx_xpm_file_to_image(data.mlx, P_IMG_2, &img.w, &img.h);
		else if (frame < 8)
			img.img = mlx_xpm_file_to_image(data.mlx, P_IMG_3, &img.w, &img.h);
		else if (frame < 10)
			img.img = mlx_xpm_file_to_image(data.mlx, P_IMG_2, &img.w, &img.h);
		else
			img.img = mlx_xpm_file_to_image(data.mlx, P_IMG_1, &img.w, &img.h);
	}
	else if (c == COIN)
	{
		if (frame < 2)
			img.img = mlx_xpm_file_to_image(data.mlx, C_IMG_0, &img.w, &img.h);
		else if (frame < 4)
			img.img = mlx_xpm_file_to_image(data.mlx, C_IMG_1, &img.w, &img.h);
		else if (frame < 6)
			img.img = mlx_xpm_file_to_image(data.mlx, C_IMG_2, &img.w, &img.h);
		else if (frame < 8)
			img.img = mlx_xpm_file_to_image(data.mlx, C_IMG_3, &img.w, &img.h);
		else if (frame < 10)
			img.img = mlx_xpm_file_to_image(data.mlx, C_IMG_4, &img.w, &img.h);
		else
			img.img = mlx_xpm_file_to_image(data.mlx, C_IMG_5, &img.w, &img.h);
	}
	else if (c == EXIT)
		img.img = mlx_xpm_file_to_image(data.mlx, EXIT_IMG, &img.w, &img.h);
	else if (c == ENEMY)
		img.img = mlx_xpm_file_to_image(data.mlx, ENEMY_IMG, &img.w, &img.h);
	return (&img);
}

static void	display_img(t_mlx_data data, int y, int x, int frame)
{
	t_img	*img;

	img = put_img(data, data.map[y][x], y, x, frame);
	if (!img->img)
		return ;
	mlx_put_image_to_window(data.mlx, data.wdw, img->img, \
		x * img->w, y * img->h + 45);
	mlx_destroy_image(data.mlx, img->img);
}

void	display_moves(t_mlx_data data)
{
	char	*moves;
	char	*num;
	char	*prev;

	prev = ft_itoa(data.moves - 1);
	if (!prev)
		return ;
	moves = ft_strjoin("Moves: ", prev);
	if (!moves)
		return (free(prev));
	// mlx_string_put(data.mlx, data.wdw, data.width / 2 - 25, 30, 0, moves);
	free(prev);
	free(moves);
	num = ft_itoa(data.moves);
	if (!num)
		return ;
	moves = ft_strjoin("Moves: ", num);
	if (!moves)
		return (free(num));
	// mlx_string_put(data.mlx, data.wdw, data.width / 2 - 25, 30, 7777777, moves);
	free(num);
	free(moves);
}

int	display_game(t_mlx_data *data)
{
	static int	frame = 0;
	int		y;
	int		x;

	// display_moves(data);
	y = 0;
	while (y < 24)
	{
		x = 0;
		while (x < count_width(data->map))
		{
			display_img(*data, y, x, frame);
			x++;
		}
		y++;
	}
	frame++;
	if (frame == 12)
		frame = 0;
	return 0;
}
