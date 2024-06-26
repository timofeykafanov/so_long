/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <tkafanov@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 10:34:20 by tkafanov          #+#    #+#             */
/*   Updated: 2024/06/27 10:03:56 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	find_player(t_mlx_data *data, int *y, int *x)
{
	while (data->map[*y])
	{
		*x = 0;
		while (data->map[*y][*x])
		{
			if (data->map[*y][*x] == PLAYER)
				break ;
			(*x)++;
		}
		if (data->map[*y][*x] == PLAYER)
			break ;
		(*y)++;
	}
}

void	move_up(t_mlx_data *data)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	find_player(data, &y, &x);
	if (data->map[y - 1][x] == FLOOR || data->map[y - 1][x] == COIN
		||data->map[y - 1][x] == EXIT)
		handle_up(data, y, x);
}

void	move_down(t_mlx_data *data)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	find_player(data, &y, &x);
	if (data->map[y + 1][x] == FLOOR || data->map[y + 1][x] == COIN
		||data->map[y + 1][x] == EXIT)
		handle_down(data, y, x);
}

void	move_right(t_mlx_data *data)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	find_player(data, &y, &x);
	if (data->map[y][x + 1] == FLOOR || data->map[y][x + 1] == COIN
		|| data->map[y][x + 1] == EXIT)
		handle_right(data, y, x);
}

void	move_left(t_mlx_data *data)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	find_player(data, &y, &x);
	if (data->map[y][x - 1] == FLOOR || data->map[y][x - 1] == COIN
		|| data->map[y][x - 1] == EXIT)
		handle_left(data, y, x);
}
