/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <tkafanov@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:15:34 by tkafanov          #+#    #+#             */
/*   Updated: 2024/06/18 15:21:06 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdbool.h>

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
