/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <tkafanov@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:15:34 by tkafanov          #+#    #+#             */
/*   Updated: 2024/06/18 11:11:50 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

int	handle_input(int key, t_mlx_data *data)
{
	if (key == ESC)
	{
		ft_printf("The %d key (ESC) has been pressed\n", key);
		mlx_destroy_window(data->connect, data->window);
		mlx_destroy_display(data->connect);
		free(data->connect);
		free_map(data->map);
		exit(1);
	}
	ft_printf("The %d key has been pressed\n", key);
	return (SUCCESS);
}

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
	int		fd;
	char	*file_content;
	char	*line;
	char	*tmp;

	file_content = NULL;
	fd = open(file_name, O_RDONLY);
	if (!fd)
		return (NULL);
	line = get_next_line(fd);
	if (!line)
		return (NULL);
	while (line)
	{
		tmp = file_content;
		file_content = ft_strjoin_gnl(&tmp, &line);
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

int	main(int argc, char **argv)
{
	static t_mlx_data	data = {NULL, NULL, 0, 0, NULL};
	static t_img		img = {NULL, IMG_W, IMG_H, NULL};
	int					x;
	int					y;

	if (argc == 2)
	{
		data.map = read_map(argv[1]);
		if (!data.map)
			return (ERROR);
		data.width = count_width(data.map) * img.w;
		data.height = count_height(data.map) * img.h;
		data.connect = mlx_init();
		if (!data.connect)
			return (free_map(data.map), ERROR);
		data.window = mlx_new_window(data.connect, data.width, data.height, "so_long");
		if (!data.window)
			return (free_map(data.map), mlx_destroy_display(data.connect), free(data.connect), ERROR);
		y = 0;
		while (y < count_height(data.map))
		{
			x = 0;
			while (x < count_width(data.map))
			{
				if (data.map[y][x] == '1')
				{
					img.img = mlx_xpm_file_to_image(data.connect, "./images/wall.xpm", &img.w, &img.h);
					if (!img.img)
						break ;
				}
				else if (data.map[y][x] == '0')
				{
					img.img = mlx_xpm_file_to_image(data.connect, "./images/floor.xpm", &img.w, &img.h);
					if (!img.img)
						break ;
				}
				else if (data.map[y][x] == 'P')
				{
					img.img = mlx_xpm_file_to_image(data.connect, "./images/hero_opened.xpm", &img.w, &img.h);
					if (!img.img)
						break ;
				}
				mlx_put_image_to_window(data.connect, data.window, img.img, x * img.w, y * img.h);
				mlx_destroy_image(data.connect, img.img);
				x++;
			}
			y++;
		}
		mlx_key_hook(data.window, handle_input, &data);
		mlx_loop(data.connect);
	}
	else
		ft_printf("Usage: %s [map file path]\n", argv[0]);
	return (SUCCESS);
}
