/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <tkafanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:15:26 by tkafanov          #+#    #+#             */
/*   Updated: 2024/06/28 15:18:43 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_img
{
	void	*img;
	void	*floor;
	void	*exit;
	void	*wall_0;
	void	*wall_1;
	void	*wall_2;
	void	*wall_3;
	void	*wall_4;
	void	*wall_5;
	void	*wall_6;
	void	*wall_7;
	void	*wall_8;
	void	*wall_9;
	void	*wall_10;
	void	*wall_11;
	void	*wall_12;
	void	*wall_13;
	void	*wall_14;
	void	*wall_15;
	void	*player_0;
	void	*player_1;
	void	*player_2;
	void	*player_3;
	void	*player_4;
	void	*player_5;
	void	*player_6;
	void	*player_7;
	void	*player_8;
	void	*player_9;
	void	*player_10;
	void	*player_11;
	void	*player_12;
	void	*coin_0;
	void	*coin_1;
	void	*coin_2;
	void	*coin_3;
	void	*coin_4;
	void	*coin_5;
	void	*enemy_0;
	void	*enemy_1;
	void	*enemy_2;
	void	*enemy_3;
	void	*enemy_4;
	void	*enemy_5;
	void	*enemy_6;
	void	*enemy_7;
	void	*enemy_8;
	void	*enemy_9;
	void	*enemy_10;
	void	*enemy_11;
	int		w;
	int		h;
}	t_img;

typedef struct s_mlx_data
{
	void	*mlx;
	void	*wdw;
	int		width;
	int		height;
	char	**map;
	int		moves;
	int		coins;
	bool	flag;
	int		direction;
	int		enemy;
	int		frame;
	t_img	img;
}	t_mlx_data;

typedef struct s_validation
{
	int	player;
	int	exit;
}	t_validation;

typedef struct s_read_map
{
	char	**map;
	char	*content;
	char	*line;
	int		fd;
}	t_read_map;

#endif // STRUCTS_H