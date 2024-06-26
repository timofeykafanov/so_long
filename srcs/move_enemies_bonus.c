/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemies_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <tkafanov@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:32:07 by tkafanov          #+#    #+#             */
/*   Updated: 2024/06/26 17:00:29 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
			{
				if (rand() % 4 == 0 && map[i][j + 1] == FLOOR)
				{
					map[i][j] = FLOOR;
					map[i][j + 1] = ENEMY;
					j++;
				}
				else if (rand() % 4 == 1 &&map[i + 1][j] == FLOOR)
				{
					map[i][j] = FLOOR;
					map[i + 1][j] = ENEMY;
					i++;
				}
				else if (rand() % 4 == 2 &&map[i - 1][j] == FLOOR)
				{
					map[i][j] = FLOOR;
					map[i - 1][j] = ENEMY;
				}
				else if (rand() % 4 == 3 &&map[i][j - 1] == FLOOR)
				{
					map[i][j] = FLOOR;
					map[i][j - 1] = ENEMY;
				}
			}
			j++;
		}
		i++;
	}
}
