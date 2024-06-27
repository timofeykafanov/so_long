/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timeout.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <tkafanov@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 09:43:35 by tkafanov          #+#    #+#             */
/*   Updated: 2024/06/27 09:44:16 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	timeout(t_mlx_data *data)
{
	if (data->width * data->height < 100)
		usleep(4000);
	if (data->width * data->height < 200)
		usleep(4000);
	if (data->width * data->height < 300)
		usleep(4000);
	if (data->width * data->height < 400)
		usleep(4000);
	if (data->width * data->height < 500)
		usleep(4000);
}
