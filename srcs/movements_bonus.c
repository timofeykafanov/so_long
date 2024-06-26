/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <tkafanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 08:56:00 by tkafanov          #+#    #+#             */
/*   Updated: 2024/06/26 18:51:23 by tkafanov         ###   ########.fr       */
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
		|| data->map[y - 1][x] == EXIT || data->map[y - 1][x] == ENEMY)
	{
		if (data->map[y - 1][x] == ENEMY)
		{
			ft_printf("You died!\n");
			close_game(data);
		}
		if (data->map[y - 1][x] == EXIT)
		{
			if (data->coins == 0)
			{
				data->moves++;
				ft_printf("You won! Result: %d\n", data->moves);
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
}

void	move_down(t_mlx_data *data)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	find_player(data, &y, &x);
	if (data->map[y + 1][x] == FLOOR || data->map[y + 1][x] == COIN
		|| data->map[y + 1][x] == EXIT || data->map[y + 1][x] == ENEMY)
	{
		if (data->map[y + 1][x] == ENEMY)
		{
			ft_printf("You died!\n");
			close_game(data);
		}
		if (data->map[y + 1][x] == EXIT)
		{
			if (data->coins == 0)
			{
				data->moves++;
				ft_printf("You won! Result: %d\n", data->moves);
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
}

void	move_right(t_mlx_data *data)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	find_player(data, &y, &x);
	if (data->map[y][x + 1] == FLOOR || data->map[y][x + 1] == COIN
		|| data->map[y][x + 1] == EXIT || data->map[y][x + 1] == ENEMY)
	{
		if (data->map[y][x + 1] == ENEMY)
		{
			ft_printf("You died!\n");
			close_game(data);
		}
		if (data->map[y][x + 1] == EXIT)
		{
			if (data->coins == 0)
			{
				data->moves++;
				ft_printf("You won! Result: %d\n", data->moves);
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
}

void	move_left(t_mlx_data *data)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	find_player(data, &y, &x);
	if (data->map[y][x - 1] == FLOOR || data->map[y][x - 1] == COIN
		|| data->map[y][x - 1] == EXIT || data->map[y][x - 1] == ENEMY)
	{
		if (data->map[y][x - 1] == ENEMY)
		{
			ft_printf("You died!\n");
			close_game(data);
		}
		if (data->map[y][x - 1] == EXIT)
		{
			if (data->coins == 0)
			{
				data->moves++;
				ft_printf("You won! Result: %d\n", data->moves);
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
}
