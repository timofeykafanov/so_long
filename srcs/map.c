/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <tkafanov@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:48:34 by tkafanov          #+#    #+#             */
/*   Updated: 2024/06/19 17:43:16 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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

char	**read_map(char *file_name)
{
	char	**map;
	char	*file_content;
	char	*line;
	int		fd;

	file_content = NULL;
	fd = open(file_name, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		return (NULL);
	while (line)
	{
		file_content = ft_strjoin_gnl(&file_content, &line);
		if (!file_content)
			return (get_next_line(-1), NULL);
		line = get_next_line(fd);
	}
	map = ft_split(file_content, '\n');
	free(file_content);
	if (close(fd) == -1)
		return (free_map(map), NULL);
	return (map);
}

bool	is_map_valid(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i + 1])
	{
		if (ft_strlen(map[i]) != ft_strlen(map[i + 1]))
			return (ft_printf("Error! Map should be rectangular!\n"), false);
		i++;
	}
	return (true);
}
