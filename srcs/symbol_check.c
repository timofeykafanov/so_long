/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symbol_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <tkafanov@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 09:05:42 by tkafanov          #+#    #+#             */
/*   Updated: 2024/06/27 17:08:23 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

bool	has_only_valid_symbols(char **map)
{
	int		i;
	int		j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != PLAYER && map[i][j] != FLOOR
				&& map[i][j] != WALL && map[i][j] != COIN
				&& map[i][j] != EXIT)
				return (ft_printf(ERR_MESS_SYMB, STDERR_FILENO), false);
			j++;
		}
		i++;
	}
	return (true);
}
