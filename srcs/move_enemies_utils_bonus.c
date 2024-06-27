/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemies_utils_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <tkafanov@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 09:55:58 by tkafanov          #+#    #+#             */
/*   Updated: 2024/06/27 17:19:45 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_enemy_right(t_mlx_data *data, int *i, int *j)
{
	if (data->map[*i][*j + 1] == PLAYER)
	{
		ft_printf(LOSE_MESS, STDOUT_FILENO);
		close_game(data);
	}
	data->map[*i][*j] = FLOOR;
	data->map[*i][*j + 1] = ENEMY;
	(*j)++;
}

void	move_enemy_left(t_mlx_data *data, int *i, int *j)
{
	if (data->map[*i][*j - 1] == PLAYER)
	{
		ft_printf(LOSE_MESS, STDOUT_FILENO);
		close_game(data);
	}
	data->map[*i][*j] = FLOOR;
	data->map[*i][*j - 1] = ENEMY;
}

void	move_enemy_up(t_mlx_data *data, int *i, int *j)
{
	if (data->map[*i - 1][*j] == PLAYER)
	{
		ft_printf(LOSE_MESS, STDOUT_FILENO);
		close_game(data);
	}
	data->map[*i][*j] = FLOOR;
	data->map[*i - 1][*j] = ENEMY;
}

void	move_enemy_down(t_mlx_data *data, int *i, int *j)
{
	if (data->map[*i + 1][*j] == PLAYER)
	{
		ft_printf(LOSE_MESS, STDOUT_FILENO);
		close_game(data);
	}
	data->map[*i][*j] = FLOOR;
	data->map[*i + 1][*j] = ENEMY;
	(*i)++;
}
