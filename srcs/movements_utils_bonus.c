/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <tkafanov@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 10:07:18 by tkafanov          #+#    #+#             */
/*   Updated: 2024/06/27 17:28:50 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	handle_up(t_mlx_data *data, int y, int x)
{
	if (data->map[y - 1][x] == ENEMY)
	{
		ft_printf(LOSE_MESS, STDOUT_FILENO);
		close_game(data);
	}
	if (data->map[y - 1][x] == EXIT)
	{
		if (data->coins == 0)
		{
			data->moves++;
			ft_printf(WIN_MESS, STDOUT_FILENO, data->moves);
			close_game(data);
		}
		return ;
	}
	if (data->map[y - 1][x] == COIN)
		data->coins--;
	data->map[y][x] = FLOOR;
	data->map[y - 1][x] = PLAYER;
	move_enemies(data);
	data->moves++;
	data->direction = 1;
}

void	handle_right(t_mlx_data *data, int y, int x)
{
	if (data->map[y][x + 1] == ENEMY)
	{
		ft_printf(LOSE_MESS, STDOUT_FILENO);
		close_game(data);
	}
	if (data->map[y][x + 1] == EXIT)
	{
		if (data->coins == 0)
		{
			data->moves++;
			ft_printf(WIN_MESS, STDOUT_FILENO, data->moves);
			close_game(data);
		}
		return ;
	}
	if (data->map[y][x + 1] == COIN)
		data->coins--;
	data->map[y][x] = FLOOR;
	data->map[y][x + 1] = PLAYER;
	move_enemies(data);
	data->moves++;
	data->direction = 2;
}

void	handle_left(t_mlx_data *data, int y, int x)
{
	if (data->map[y][x - 1] == ENEMY)
	{
		ft_printf(LOSE_MESS, STDOUT_FILENO);
		close_game(data);
	}
	if (data->map[y][x - 1] == EXIT)
	{
		if (data->coins == 0)
		{
			data->moves++;
			ft_printf(WIN_MESS, STDOUT_FILENO, data->moves);
			close_game(data);
		}
		return ;
	}
	if (data->map[y][x - 1] == COIN)
		data->coins--;
	data->map[y][x] = FLOOR;
	data->map[y][x - 1] = PLAYER;
	move_enemies(data);
	data->moves++;
	data->direction = 0;
}

void	handle_down(t_mlx_data *data, int y, int x)
{
	if (data->map[y + 1][x] == ENEMY)
	{
		ft_printf(LOSE_MESS, STDOUT_FILENO);
		close_game(data);
	}
	if (data->map[y + 1][x] == EXIT)
	{
		if (data->coins == 0)
		{
			data->moves++;
			ft_printf(WIN_MESS, STDOUT_FILENO, data->moves);
			close_game(data);
		}
		return ;
	}
	if (data->map[y + 1][x] == COIN)
		data->coins--;
	data->map[y][x] = FLOOR;
	data->map[y + 1][x] = PLAYER;
	move_enemies(data);
	data->moves++;
	data->direction = 3;
}
