/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <tkafanov@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 08:24:44 by tkafanov          #+#    #+#             */
/*   Updated: 2024/06/26 14:41:23 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	*put_wall(t_mlx_data data, t_img *img, int y, int x)
{
	if (y == 0 || x == 0 || y == data.height - 1
		|| x == data.width - 1)
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

static t_img	*put_img(t_mlx_data *data, char c, t_coord coord, int frame)
{
	static t_img	img = {NULL, IMG_W, IMG_H};

	if (c == WALL)
		img.img = put_wall(*data, &img, coord.y, coord.x);
	else if (c == FLOOR)
		img.img = mlx_xpm_file_to_image(data->mlx, FLOOR_IMG, &img.w, &img.h);
	else if (c == PLAYER)
		img.img = put_player_sprite(*data, &img, frame);
	else if (c == COIN)
		img.img = put_coin_sprite(*data, &img, frame);
	else if (c == EXIT)
		img.img = mlx_xpm_file_to_image(data->mlx, EXIT_IMG, &img.w, &img.h);
	else if (c == ENEMY)
		img.img = put_enemy_sprite(data, &img, frame);
	return (&img);
}

static void	display_img(t_mlx_data *data, t_coord coord, int frame)
{
	t_img	*img;

	img = put_img(data, data->map[coord.y][coord.x], coord, frame);
	if (!img->img)
		return ;
	mlx_put_image_to_window(data->mlx, data->wdw, img->img, \
		coord.x * img->w, coord.y * img->h + 45);
	mlx_destroy_image(data->mlx, img->img);
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
	mlx_string_put(data.mlx, data.wdw, \
		data.width * IMG_W / 2 - 25, 30, 0, moves);
	free(prev);
	free(moves);
	num = ft_itoa(data.moves);
	if (!num)
		return ;
	moves = ft_strjoin("Moves: ", num);
	if (!moves)
		return (free(num));
	mlx_string_put(data.mlx, data.wdw, data.width * IMG_W / 2 - 25, \
		30, 7777777, moves);
	free(num);
	free(moves);
}

int	display_game(t_mlx_data *data)
{
	t_coord		coord;

	display_moves(*data);
	coord.y = 0;
	data->enemy = 0;
	while (coord.y < data->height)
	{
		coord.x = 0;
		while (coord.x < data->width)
		{
			display_img(data, coord, data->frame);
			coord.x++;
		}
		coord.y++;
	}
	data->frame++;
	if (data->frame == 12)
		data->frame = 0;
	return (SUCCESS);
}
