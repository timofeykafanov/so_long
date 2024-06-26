/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <tkafanov@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 13:43:39 by tkafanov          #+#    #+#             */
/*   Updated: 2024/06/26 11:09:26 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	flood_fill(t_mlx_data *data, int y, int x, char to_fill)
{
	if (x == 0 || y == 0 || x == data->width - 1
		|| y == data->height - 1 || (data->map[y][x] == WALL
		|| data->map[y][x] == EXIT || data->map[y][x] == to_fill))
		return ;
	data->map[y][x] = to_fill;
	flood_fill(data, y, x - 1, to_fill);
	flood_fill(data, y, x + 1, to_fill);
	flood_fill(data, y - 1, x, to_fill);
	flood_fill(data, y + 1, x, to_fill);
}

static bool	check_exit(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == EXIT)
			{
				if (map[i - 1][j] == FILL || map[i + 1][j] == FILL
				|| map[i][j - 1] == FILL || map[i][j + 1] == FILL)
					return (true);
			}
			j++;
		}
		i++;
	}
	return (false);
}

static bool	check_coins(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == COIN)
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	has_valid_path(t_mlx_data *data)
{
	int		y;
	int		x;
	bool	exit;
	bool	coins;

	y = 0;
	x = 0;
	find_player(data, &y, &x);
	flood_fill(data, y, x, FILL);
	y = 0;
	exit = check_exit(data->map);
	coins = check_coins(data->map);
	return (exit && coins);
}
