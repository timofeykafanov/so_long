/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <tkafanov@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:15:34 by tkafanov          #+#    #+#             */
/*   Updated: 2024/06/18 14:11:28 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdbool.h>

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
	if (key == XK_Escape)
	{
		ft_printf("The %d key (ESC) has been pressed\n", key);
		mlx_destroy_window(data->mlx, data->wdw);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
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
	char	*file_content;
	char	*line;
	int		fd;

	file_content = NULL;
	fd = open(file_name, O_RDONLY);
	if (!fd)
		return (NULL);
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

t_img	*return_img(t_mlx_data data, char c)
{
	static t_img	img = {NULL, IMG_W, IMG_H};
	if (c == WALL)
		img.img = mlx_xpm_file_to_image(data.mlx, WALL_IMG, &img.w, &img.h);
	else if (c == FLOOR)
		img.img = mlx_xpm_file_to_image(data.mlx, FLOOR_IMG, &img.w, &img.h);
	else if (c == PLAYER)
		img.img = mlx_xpm_file_to_image(data.mlx, PLAYER_IMG, &img.w, &img.h);
	return (&img);
}

void display_img(t_mlx_data data, int y, int x)
{
	t_img	*img;

	img = return_img(data, data.map[y][x]);
	if (!img->img)
		return ;
	mlx_put_image_to_window(data.mlx, data.wdw, img->img, x * img->w, y * img->h);
	mlx_destroy_image(data.mlx, img->img);
}

void display_game(t_mlx_data data)
{
	int 	y;
	int		x;

	y = 0;
	while (y < count_height(data.map))
	{
		x = 0;
		while (x < count_width(data.map))
			display_img(data, y, x++);
		y++;
	}
}

int	main(int argc, char **argv)
{
	static t_mlx_data	data = {NULL, NULL, 0, 0, NULL};

	if (argc == 2)
	{
		data.map = read_map(argv[1]);
		if (!data.map)
			return (ERROR);
		data.width = count_width(data.map) * IMG_W;
		data.height = count_height(data.map) * IMG_H;
		if (!is_map_valid(data.map))
			return (free_map(data.map), ERROR);
		data.mlx = mlx_init();
		if (!data.mlx)
			return (free_map(data.map), ERROR);
		data.wdw = mlx_new_window(data.mlx, data.width, data.height, "so_long");
		if (!data.wdw)
			return (free_map(data.map), mlx_destroy_display(data.mlx), free(data.mlx), ERROR);
		mlx_key_hook(data.wdw, handle_input, &data);
		display_game(data);
		mlx_loop(data.mlx);
	}
	else
		ft_printf("Usage: %s [map file path]\n", argv[0]);
	return (SUCCESS);
}
