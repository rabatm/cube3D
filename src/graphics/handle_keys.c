/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orauline <orauline@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 20:41:34 by orauline          #+#    #+#             */
/*   Updated: 2024/02/10 21:16:40 by orauline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	z_key(t_game *game)
{
	if (!game->int_map[(int)(game->player.pos_x + game->player.dir_x * \
		game->speed)][(int)game->player.pos_y])
		game->player.pos_x += game->player.dir_x * game->speed;
	if (!game->int_map[(int)game->player.pos_x][(int)(game->player.pos_y + \
		game->player.dir_y * game->speed)])
		game->player.pos_y += game->player.dir_y * game->speed;
}

void	s_key(t_game *game)
{
	if (!game->int_map[(int)(game->player.pos_x - game->player.dir_x * \
		game->speed)][(int)game->player.pos_y])
		game->player.pos_x -= game->player.dir_x * game->speed;
	if (!game->int_map[(int)game->player.pos_x][(int)(game->player.pos_y - \
		game->player.dir_y * game->speed)])
		game->player.pos_y -= game->player.dir_y * game->speed;
}

void	q_key(t_game *game)
{
	if (!game->int_map[(int)(game->player.pos_x - game->player.dir_y * \
		game->speed)][(int)game->player.pos_y])
		game->player.pos_x -= game->player.dir_y * game->speed;
	if (!game->int_map[(int)game->player.pos_x][(int)(game->player.pos_y + \
		game->player.dir_x * game->speed)])
		game->player.pos_y -= -game->player.dir_x * game->speed;
}

void	d_key(t_game *game)
{
	if (!game->int_map[(int)(game->player.pos_x + game->player.dir_y * \
		game->speed)][(int)game->player.pos_y])
		game->player.pos_x += game->player.dir_y * game->speed;
	if (!game->int_map[(int)game->player.pos_x][(int)(game->player.pos_y - \
		game->player.dir_x * game->speed)])
		game->player.pos_y += -game->player.dir_x * game->speed;
}
