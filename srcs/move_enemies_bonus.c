/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemies_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <tkafanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:32:07 by tkafanov          #+#    #+#             */
/*   Updated: 2024/06/26 19:09:13 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void choose_direction(t_mlx_data *data, int *i, int *j)
{
	int	num;

	num = rand() % 4;
	if (num == 0 && (data->map[*i][*j + 1] == FLOOR || data->map[*i][*j + 1] == PLAYER))
	{
		if (data->map[*i][*j + 1] == PLAYER)
			return (ft_printf("You died!\n"), close_game(data));
		data->map[*i][*j] = FLOOR;
		data->map[*i][*j + 1] = ENEMY;
		(*j)++;
	}
	else if (num == 1 && (data->map[*i + 1][*j] == FLOOR || data->map[*i + 1][*j] == PLAYER))
	{
		if (data->map[*i + 1][*j] == PLAYER)
			return (ft_printf("You died!\n"), close_game(data));
		data->map[*i][*j] = FLOOR;
		data->map[*i + 1][*j] = ENEMY;
		(*i)++;
	}
	else if (num == 2 && (data->map[*i - 1][*j] == FLOOR || data->map[*i - 1][*j] == PLAYER))
	{
		if (data->map[*i - 1][*j] == PLAYER)
			return (ft_printf("You died!\n"), close_game(data));
		data->map[*i][*j] = FLOOR;
		data->map[*i - 1][*j] = ENEMY;
	}
	else if (num == 3 && (data->map[*i][*j - 1] == FLOOR || data->map[*i][*j - 1] == PLAYER))
	{
		if (data->map[*i][*j - 1] == PLAYER)
			return (ft_printf("You died!\n"), close_game(data));
		data->map[*i][*j] = FLOOR;
		data->map[*i][*j - 1] = ENEMY;
	}
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
