/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <tkafanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:48:34 by tkafanov          #+#    #+#             */
/*   Updated: 2024/06/28 14:21:03 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static bool	check_newline(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == NEW_LINE && line[i + 1] == NEW_LINE)
			return (false);
		i++;
	}
	return (true);
}

static char	**read_map(char *file_name, t_mlx_data *data)
{
	t_read_map	read_map;

	read_map.content = NULL;
	read_map.fd = open(file_name, O_RDONLY);
	if (read_map.fd == -1)
		return (ft_printf(ERR_MESS_FILE, STDERR_FILENO), NULL);
	read_map.line = get_next_line(read_map.fd, &data->flag, false);
	if (!read_map.line)
		return (ft_printf(ERR_MESS_EMPTY, STDERR_FILENO), NULL);
	while (read_map.line)
	{
		read_map.content = ft_strjoin_gnl(&read_map.content, &read_map.line);
		if (!read_map.content)
			return (get_next_line(read_map.fd, &data->flag, true), NULL);
		read_map.line = get_next_line(read_map.fd, &data->flag, false);
	}
	read_map.map = ft_split(read_map.content, NEW_LINE);
	if (!check_newline(read_map.content) && read_map.map)
		return (free_map(read_map.map), free(read_map.content), \
		ft_printf(ERR_MESS_NEWLINE, STDERR_FILENO), NULL);
	free(read_map.content);
	if (close(read_map.fd) == -1 || (data->flag && read_map.map))
		return (free_map(read_map.map), \
			ft_printf(ERR_MESS_READ, STDERR_FILENO), NULL);
	return (read_map.map);
}

static inline bool	is_map_valid(t_mlx_data *data)
{
	bool	coins;
	bool	shape;
	bool	perimeter;
	bool	start_and_end;
	bool	valid_symbols;

	coins = contains_coins(data);
	shape = is_map_rectangular(data->map);
	perimeter = is_perimeter_true(data->map);
	start_and_end = has_start_and_and(data->map);
	valid_symbols = has_only_valid_symbols(data->map);
	return (coins && shape && perimeter && start_and_end && valid_symbols);
}

int	init_map(t_mlx_data *data, char *file)
{
	bool	path;

	data->map = read_map(file, data);
	if (!data->map)
		return (ERROR);
	data->width = count_width(data->map);
	if (!data->width)
		return (ft_printf(ERR_MESS_EMPTY, STDERR_FILENO), ERROR);
	data->height = count_height(data->map);
	if (!is_map_valid(data))
		return (free_map(data->map), ERROR);
	path = has_valid_path(data);
	if (!path)
		return (free_map(data->map), \
		ft_printf(ERR_MESS_PATH, STDERR_FILENO), ERROR);
	free_map(data->map);
	data->map = read_map(file, data);
	if (!data->map)
		return (ERROR);
	return (SUCCESS);
}
