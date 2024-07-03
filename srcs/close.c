/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <tkafanov@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 11:10:26 by tkafanov          #+#    #+#             */
/*   Updated: 2024/07/03 08:59:29 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <unistd.h>

int	close_game_error(t_mlx_data *data)
{
	destroy_images(data);
	mlx_destroy_window(data->mlx, data->wdw);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free_map(data->map);
	ft_printf(ERR_MESS_IMG, STDERR_FILENO);
	exit(1);
}

int	close_game(t_mlx_data *data)
{
	destroy_images(data);
	mlx_destroy_window(data->mlx, data->wdw);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free_map(data->map);
	exit(0);
}
