/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <tkafanov@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 08:23:05 by tkafanov          #+#    #+#             */
/*   Updated: 2024/06/26 12:30:37 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	handle_input(int key, t_mlx_data *data)
{
	if (key == XK_Escape)
	{
		mlx_destroy_window(data->mlx, data->wdw);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		free_map(data->map);
		exit(1);
	}
	if (key == XK_Up || key == XK_Down || key == XK_Right || key == XK_Left)
	{
		if (key == XK_Up)
			move_up(data);
		else if (key == XK_Down)
			move_down(data);
		else if (key == XK_Right)
			move_right(data);
		else if (key == XK_Left)
			move_left(data);
		display_game(data);
	}
	return (SUCCESS);
}

int	so_long(char *file)
{
	static t_mlx_data	data;

	ft_bzero(&data, 8);
	if (init_map(&data, file) == ERROR)
		return (ERROR);
	data.mlx = mlx_init();
	if (!data.mlx)
		return (free_map(data.map), ERROR);
	data.wdw = mlx_new_window(data.mlx, data.width * IMG_W, \
		data.height * IMG_H + 45, GAME);
	if (!data.wdw)
	{
		free_map(data.map);
		mlx_destroy_display(data.mlx);
		free(data.mlx);
		return (ERROR);
	}
	mlx_key_hook(data.wdw, handle_input, &data);
	display_game(&data);
	mlx_loop_hook(data.mlx, display_game, &data);
	mlx_loop(data.mlx);
	// free_map(data.map);
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