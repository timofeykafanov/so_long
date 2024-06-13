/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <tkafanov@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:16:17 by tkafanov          #+#    #+#             */
/*   Updated: 2024/06/13 17:21:46 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"

# define SUCCESS 0
# define ERROR 1

# define ESC 65307
# define UP 119
# define LEFT 97
# define DOWN 115
# define RIGHT 100

typedef struct s_mlx_data
{
	void	*connect;
	void	*window;
	int		width;
	int		height;
	char	**map;
}	t_mlx_data;

typedef struct s_img
{
	void	*img;
	int		w;
	int		h;
	char	*addr;
}	t_img;

#endif // SO_LONG_H
