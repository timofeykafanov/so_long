/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <tkafanov@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:48:34 by tkafanov          #+#    #+#             */
/*   Updated: 2024/06/24 17:34:05 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdbool.h>

int	count_width(char **map)
{
	int	width;

	width = 0;
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

char	**read_map(char *file_name, t_mlx_data *data)
{
	char	**map;
	char	*file_content;
	char	*line;
	int		fd;

	// TODO: modify gnl (error flag)
	file_content = NULL;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (ft_printf(ERR_MESS_FILE), NULL);
	line = get_next_line(fd, &data->flag, false);
	if (!line)
		return (NULL);
	while (line)
	{
		file_content = ft_strjoin_gnl(&file_content, &line);
		if (!file_content)
			return (get_next_line(fd, &data->flag, true), NULL);
		line = get_next_line(fd, &data->flag, false);
	}
	map = ft_split(file_content, NEW_LINE);
	free(file_content);
	if (close(fd) == -1 || data->flag == true)
		return (free_map(map), NULL);
	return (map);
}

bool	is_map_valid(t_mlx_data *data)
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

bool	is_filename_valid(char *filename)
{
	if (ft_strlen(filename) < 5)
		return (ft_printf(ERR_MESS_EXTEN), false);
	if (ft_strncmp(filename + ft_strlen(filename) - 4, ".ber", 4) != 0
		|| ft_strncmp(filename + ft_strlen(filename) - 5, "/.ber", 5) == 0)
		return (ft_printf(ERR_MESS_EXTEN), false);
	return (true);
}
