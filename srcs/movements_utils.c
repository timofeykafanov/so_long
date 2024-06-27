/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <tkafanov@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 09:58:47 by tkafanov          #+#    #+#             */
/*   Updated: 2024/06/27 17:28:04 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	handle_up(t_mlx_data *data, int y, int x)
{
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
	data->moves++;
	data->direction = 1;
	ft_printf(MOVES_MESS, STDOUT_FILENO, data->moves);
}

void	handle_right(t_mlx_data *data, int y, int x)
{
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
	data->moves++;
	data->direction = 2;
	ft_printf("Moves: %d\n", STDOUT_FILENO, data->moves);
}

void	handle_left(t_mlx_data *data, int y, int x)
{
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
	data->moves++;
	data->direction = 0;
	ft_printf("Moves: %d\n", STDOUT_FILENO, data->moves);
}

void	handle_down(t_mlx_data *data, int y, int x)
{
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
	data->moves++;
	data->direction = 3;
	ft_printf("Moves: %d\n", STDOUT_FILENO, data->moves);
}
