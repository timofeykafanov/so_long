/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <tkafanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:15:34 by tkafanov          #+#    #+#             */
/*   Updated: 2024/06/24 19:58:49 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
	else if (key == XK_Up)
	{
		move_up(data);
		display_game(*data);
	}
	else if (key == XK_Down)
	{
		move_down(data);
		display_game(*data);
	}
	else if (key == XK_Right)
	{
		move_right(data);
		display_game(*data);
	}
	else if (key == XK_Left)
	{
		move_left(data);
		display_game(*data);
	}
	else
		ft_printf("The %d key has been pressed\n", key);
	return (SUCCESS);
}

int	so_long(char *file)
{
	// static t_mlx_data	data = {NULL, NULL, 0, 0, NULL, 0, 0};
	static t_mlx_data	data;

	ft_bzero(&data, 8);
	printf("i = %d\n", data.flag == true);
	data.map = read_map(file, &data);
	if (!data.map)
		return (ERROR);
	data.width = count_width(data.map) * IMG_W;
	data.height = count_height(data.map) * IMG_H + 45;
	if (!is_map_valid(&data))
		return (free_map(data.map), ERROR);
	// data.mlx = mlx_init();
	// if (!data.mlx)
	// 	return (free_map(data.map), ERROR);
	// data.wdw = mlx_new_window(data.mlx, data.width, data.height, GAME);
	// if (!data.wdw)
	// {
	// 	free_map(data.map);
	// 	mlx_destroy_display(data.mlx);
	// 	free(data.mlx);
	// 	return (ERROR);
	// }
	// mlx_key_hook(data.wdw, handle_input, &data);
	// display_game(data);
	// mlx_loop(data.mlx);
	free_map(data.map);
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (!is_filename_valid(argv[1]))
			return (ERROR);
		if (so_long(argv[1]) == ERROR)
			return (ERROR);
	}
	else
		ft_printf("Error! Usage: %s [map file path]\n", argv[0]);
	return (SUCCESS);
}
