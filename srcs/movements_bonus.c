/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <tkafanov@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 08:56:00 by tkafanov          #+#    #+#             */
/*   Updated: 2024/06/26 13:49:05 by tkafanov         ###   ########.fr       */
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
	{
		if (data->map[y - 1][x] == EXIT)
		{
			if (data->coins == 0)
			{
				data->moves++;
				ft_printf("Result: %d\n", data->moves);
				close_game(data);
			}
			return ;
		}
		if (data->map[y - 1][x] == COIN)
			data->coins--;
		data->map[y][x] = FLOOR;
		data->map[y - 1][x] = PLAYER;
		data->moves++;
		data->direction = 1;
	}
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
	{
		if (data->map[y + 1][x] == EXIT)
		{
			if (data->coins == 0)
			{
				data->moves++;
				ft_printf("Result: %d\n", data->moves);
				close_game(data);
			}
			return ;
		}
		if (data->map[y + 1][x] == COIN)
			data->coins--;
		data->map[y][x] = FLOOR;
		data->map[y + 1][x] = PLAYER;
		data->moves++;
		data->direction = 3;
	}
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
	{
		if (data->map[y][x + 1] == EXIT)
		{
			if (data->coins == 0)
			{
				data->moves++;
				ft_printf("Result: %d\n", data->moves);
				close_game(data);
			}
			return ;
		}
		if (data->map[y][x + 1] == COIN)
			data->coins--;
		data->map[y][x] = FLOOR;
		data->map[y][x + 1] = PLAYER;
		data->moves++;
		data->direction = 2;
	}
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
	{
		if (data->map[y][x - 1] == EXIT)
		{
			if (data->coins == 0)
			{
				data->moves++;
				ft_printf("Result: %d\n", data->moves);
				close_game(data);
			}
			return ;
		}
		if (data->map[y][x - 1] == COIN)
			data->coins--;
		data->map[y][x] = FLOOR;
		data->map[y][x - 1] = PLAYER;
		data->moves++;
		data->direction = 0;
	}
}
