/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkafanov <tkafanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 15:12:40 by tkafanov          #+#    #+#             */
/*   Updated: 2024/06/28 15:16:50 by tkafanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACRO_H
# define MACRO_H

# define SUCCESS 0
# define ERROR 1

# define IMG_H 32
# define IMG_W 32

# define GAME "Packman"

# define WALL	'1'
# define FLOOR	'0'
# define PLAYER	'P'
# define COIN	'C'
# define EXIT	'E'
# define ENEMY	'G'
# define FILL	'F'

# define NEW_LINE '\n'

# define ERR_MESS_PER		"Error\nThe map should be surrounded by walls!\n"
# define ERR_MESS_EXTEN		"Error\nInvalid file extention!\n"
# define ERR_MESS_FILE		"Error\nFile doesn't exist!\n"
# define ERR_MESS_SHAPE		"Error\nMap should be rectangular!\n"
# define ERR_MESS_PLAYER	"Error\nThere should be 1 player!\n"
# define ERR_MESS_EXIT		"Error\nThere should be 1 exit!\n"
# define ERR_MESS_COINS		"Error\nThere should be at least 1 collectible!\n"
# define ERR_MESS_READ		"Error\nError reading file!\n"
# define ERR_MESS_EMPTY		"Error\nEmpty map!\n"
# define ERR_MESS_PATH		"Error\nThere is no valid path!\n"
# define ERR_MESS_SYMB		"Error\nInvalid symbol found!\n"
# define ERR_MESS_NEWLINE	"Error\nInvalid newline found!\n"
# define ERR_MESS_ARGS		"Error\nUsage: %s [map file path]\n"

# define LOSE_MESS	"You died!\n"
# define MOVES_MESS	"Moves: %d\n"
# define WIN_MESS	"You won! Result: %d\n"

#endif // MACRO_H