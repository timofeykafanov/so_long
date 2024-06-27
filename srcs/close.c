/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <tkafanov@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 11:10:26 by tkafanov          #+#    #+#             */
/*   Updated: 2024/06/27 10:30:13 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	close_game(t_mlx_data *data)
{
	mlx_destroy_window(data->mlx, data->wdw);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free_map(data->map);
	exit(1);
}
