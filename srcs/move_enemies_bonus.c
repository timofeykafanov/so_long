/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemies_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <tkafanov@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:32:07 by tkafanov          #+#    #+#             */
/*   Updated: 2024/06/26 17:40:39 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void choose_direction(char **map, int *i, int *j)
{
	int	num;

	num = rand() % 4;
	if (num == 0 && map[*i][*j + 1] == FLOOR)
	{
		map[*i][*j] = FLOOR;
		map[*i][*j + 1] = ENEMY;
		j++;
	}
	else if (num == 1 && map[*i + 1][*j] == FLOOR)
	{
		map[*i][*j] = FLOOR;
		map[*i + 1][*j] = ENEMY;
		i++;
	}
	else if (num == 2 && map[*i - 1][*j] == FLOOR)
	{
		map[*i][*j] = FLOOR;
		map[*i - 1][*j] = ENEMY;
	}
	else if (num == 3 && map[*i][*j - 1] == FLOOR)
	{
		map[*i][*j] = FLOOR;
		map[*i][*j - 1] = ENEMY;
	}
}

void	move_enemies(char **map)
{
	int	i;
	int	j;

	srand(time(NULL));
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == ENEMY)
				choose_direction(map, &i, &j);
			j++;
		}
		i++;
	}
}
