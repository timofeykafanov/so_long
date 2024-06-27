/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemies_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <tkafanov@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:32:07 by tkafanov          #+#    #+#             */
/*   Updated: 2024/06/27 09:57:52 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	choose_direction(t_mlx_data *data, int *i, int *j)
{
	int	num;

	num = rand() % 4;
	if (num == 0 && (data->map[*i][*j + 1] == FLOOR
		|| data->map[*i][*j + 1] == PLAYER))
		move_enemy_right(data, i, j);
	else if (num == 1 && (data->map[*i + 1][*j] == FLOOR
		|| data->map[*i + 1][*j] == PLAYER))
		move_enemy_down(data, i, j);
	else if (num == 2 && (data->map[*i - 1][*j] == FLOOR
		|| data->map[*i - 1][*j] == PLAYER))
		move_enemy_up(data, i, j);
	else if (num == 3 && (data->map[*i][*j - 1] == FLOOR
		|| data->map[*i][*j - 1] == PLAYER))
		move_enemy_left(data, i, j);
}

void	move_enemies(t_mlx_data *data)
{
	int	i;
	int	j;

	srand(time(NULL));
	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == ENEMY)
				choose_direction(data, &i, &j);
			j++;
		}
		i++;
	}
}
