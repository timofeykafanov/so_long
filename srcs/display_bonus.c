/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <tkafanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 08:24:44 by tkafanov          #+#    #+#             */
/*   Updated: 2024/06/28 15:18:17 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	display_wall(t_mlx_data data, int y, int x)
{
	if (y == 0 || x == 0 || y == data.height - 1
		|| x == data.width - 1)
		put_border(data, y, x);
	else if (is_cross(data, y, x))
		put_cross(data, y, x);
	else if (data.map[y - 1][x] == WALL && data.map[y + 1][x] == WALL)
		mlx_put_image_to_window(data.mlx, data.wdw, data.img.wall_7, x \
			* data.img.w, y * data.img.h + 45);
	else if (data.map[y][x - 1] == WALL && data.map[y][x + 1] == WALL)
		mlx_put_image_to_window(data.mlx, data.wdw, data.img.wall_6, x \
			* data.img.w, y * data.img.h + 45);
	else if (is_corner(data, y, x))
		put_corner(data, y, x);
	else if (data.map[y + 1][x] == WALL || data.map[y - 1][x] == WALL
		|| data.map[y][x + 1] == WALL || data.map[y][x - 1] == WALL)
		put_edge(data, y, x);
	else
		mlx_put_image_to_window(data.mlx, data.wdw, data.img.wall_0, x \
			* data.img.w, y * data.img.h + 45);
}

static void	display_img(t_mlx_data *data, int y, int x, int frame)
{
	if (data->map[y][x] == FLOOR)
		mlx_put_image_to_window(data->mlx, data->wdw, data->img.floor, \
		x * data->img.w, y * data->img.h + 45);
	else if (data->map[y][x] == WALL)
		display_wall(*data, y, x);
	else if (data->map[y][x] == PLAYER)
		display_player_sprite(*data, y, x, frame);
	else if (data->map[y][x] == COIN)
		display_coin_sprite(*data, y, x, frame);
	else if (data->map[y][x] == EXIT)
		mlx_put_image_to_window(data->mlx, data->wdw, data->img.exit, \
		x * data->img.w, y * data->img.h + 45);
	else if (data->map[y][x] == ENEMY)
		display_enemy_sprite(data, y, x, frame);
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
	mlx_string_put(data.mlx, data.wdw, \
		data.width * IMG_W / 2 - 25, 30, 7777777, moves);
	free(num);
	free(moves);
}

int	display_game(t_mlx_data *data)
{
	int	y;
	int	x;

	display_moves(*data);
	y = 0;
	data->enemy = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			display_img(data, y, x, data->frame);
			x++;
		}
		y++;
	}
	usleep(30000);
	data->frame++;
	if (data->frame == 12)
		data->frame = 0;
	return (SUCCESS);
}
