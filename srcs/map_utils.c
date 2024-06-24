/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <tkafanov@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 15:15:10 by tkafanov          #+#    #+#             */
/*   Updated: 2024/06/24 15:17:02 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

bool	is_map_rectangular(char **map)
{
	int	i;

	i = 0;
	while (map[i + 1])
	{
		if (ft_strlen(map[i]) != ft_strlen(map[i + 1]))
			return (ft_printf("Error! Map should be rectangular!\n"), false);
		i++;
	}
	return (true);
}

bool	is_perimeter_true(char **map)
{
	int		i;
	int		j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (i == 0 || i == count_height(map) - 1
				|| j == 0 || j == count_width(map) - 1)
			{
				if (map[i][j] != WALL)
					return (ft_printf(ERR_MESS_PER), false);
			}
			j++;
		}
		i++;
	}
	return (true);
}

bool	has_start_and_and(char **map)
{
	int				i;
	int				j;
	t_validation	val;

	i = 0;
	val.player = 0;
	val.exit = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == PLAYER)
				val.player++;
			else if (map[i][j] == EXIT)
				val.exit++;
			j++;
		}
		i++;
	}
	if (val.player != 1)
		ft_printf("Error! There shold be 1 player!\n");
	if (val.exit != 1)
		ft_printf("Error! There shold be 1 exit!\n");
	return (val.player == 1 && val.exit == 1);
}

bool	contains_coins(t_mlx_data *data)
{
	int	i;
	int	j;

	data->coins = 0;
	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == COIN)
				data->coins++;
			j++;
		}
		i++;
	}
	if (data->coins == 0)
		ft_printf("Error! There should be at least 1 collectible!\n");
	return (data->coins > 0);
}
