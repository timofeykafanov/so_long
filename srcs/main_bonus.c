/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <tkafanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 08:23:05 by tkafanov          #+#    #+#             */
/*   Updated: 2024/06/28 09:21:43 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	handle_input(int key, t_mlx_data *data)
{
	if (key == XK_Escape)
		close_game(data);
	if (key == XK_Up || key == XK_Down || key == XK_Right || key == XK_Left
		|| key == XK_W || key == XK_S || key == XK_D || key == XK_A
		|| key == XK_w || key == XK_s || key == XK_d || key == XK_a)
	{
		if (key == XK_Up || key == XK_W || key == XK_w)
			move_up(data);
		else if (key == XK_Down || key == XK_S || key == XK_s)
			move_down(data);
		else if (key == XK_Right || key == XK_D || key == XK_d)
			move_right(data);
		else if (key == XK_Left || key == XK_A || key == XK_a)
			move_left(data);
	}
	return (SUCCESS);
}

int	so_long(char *file)
{
	static t_mlx_data	data;

	ft_bzero(&data, 11);
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
	mlx_hook(data.wdw, DestroyNotify, StructureNotifyMask, &close_game, &data);
	mlx_loop_hook(data.mlx, display_game, &data);
	mlx_loop(data.mlx);
	return (SUCCESS);
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
	{
		ft_printf(ERR_MESS_ARGS, STDERR_FILENO, argv[0]);
		return (ERROR);
	}
	return (SUCCESS);
}
