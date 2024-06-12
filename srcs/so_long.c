/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <tkafanov@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:15:34 by tkafanov          #+#    #+#             */
/*   Updated: 2024/06/12 16:09:26 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

#include <stdio.h>

int	handle_input(int key, t_mlx_data *data)
{
	if (key == ESC)
	{
		printf("The %d key (ESC) has been pressed\n", key);
		mlx_destroy_window(data->connect, data->window);
		mlx_destroy_display(data->connect);
		free(data->connect);
		exit(1);
	}
	printf("The %d key has been pressed\n", key);
	return (SUCCESS);
}

int	main(void)
{
	t_mlx_data	data;

	data.connect = mlx_init();
	if (!data.connect)
		return (ERROR);
	data.window = mlx_new_window(data.connect, 400, 400, "so_long");
	if (!data.window)
		return (mlx_destroy_display(data.connect), free(data.connect), ERROR);
	mlx_key_hook(data.window, handle_input, &data);
	mlx_loop(data.connect);
	mlx_destroy_window(data.connect, data.window);
	mlx_destroy_display(data.connect);
	free(data.connect);
	return (SUCCESS);
}
