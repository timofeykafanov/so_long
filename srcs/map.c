/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <tkafanov@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:48:34 by tkafanov          #+#    #+#             */
/*   Updated: 2024/06/25 13:48:30 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdbool.h>
#include <stdio.h>

int	count_width(char **map)
{
	int	width;

	width = 0;
	if (!map[0])
		return (0);
	while (map[0][width])
		width++;
	return (width);
}

int	count_height(char **map)
{
	int	height;

	height = 0;
	while (map[height])
		height++;
	return (height);
}

static char	**read_map(char *file_name, t_mlx_data *data)
{
	char	**map;
	char	*file_content;
	char	*line;
	int		fd;

	file_content = NULL;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (ft_printf(ERR_MESS_FILE), NULL);
	line = get_next_line(fd, &data->flag, false);
	if (!line)
		return (ft_printf(ERR_MESS_EMPTY), NULL);
	while (line)
	{
		file_content = ft_strjoin_gnl(&file_content, &line);
		if (!file_content)
			return (get_next_line(fd, &data->flag, true), NULL);
		line = get_next_line(fd, &data->flag, false);
	}
	map = ft_split(file_content, NEW_LINE);
	free(file_content);
	if (close(fd) == -1 || (data->flag && map))
		return (free_map(map), ft_printf(ERR_MESS_READ), NULL);
	return (map);
}

static bool	is_map_valid(t_mlx_data *data)
{
	bool	coins;
	bool	shape;
	bool	perimeter;
	bool	start_and_end;

	coins = contains_coins(data);
	shape = is_map_rectangular(data->map);
	perimeter = is_perimeter_true(data->map);
	start_and_end = has_start_and_and(data->map);
	return (coins && shape && perimeter && start_and_end);
}

int	init_map(t_mlx_data *data, char *file)
{
	bool	path;

	data->map = read_map(file, data);
	if (!data->map)
		return (ERROR);
	data->width = count_width(data->map) * IMG_W;
	if (!data->width)
		return (ft_printf(ERR_MESS_EMPTY), ERROR);
	data->height = count_height(data->map) * IMG_H + 45;
	if (!is_map_valid(data))
		return (free_map(data->map), ERROR);
	path = has_valid_path(data);
	if (!path)
		return (ft_printf(ERR_MESS_PATH), ERROR);
	free_map(data->map);
	data->map = read_map(file, data);
	if (!data->map)
		return (ERROR);
	return (SUCCESS);
}
