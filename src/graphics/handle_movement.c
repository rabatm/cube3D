/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orauline <orauline@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 20:43:37 by orauline          #+#    #+#             */
/*   Updated: 2024/02/10 21:18:50 by orauline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/*Fonction qui gere la rotation droite du joueur*/
void	rotate_right_key(t_game *game)
{
	double	tmp_plane_x;
	double	tmp_dir_x;

	tmp_plane_x = game->plane_x;
	tmp_dir_x = game->player.dir_x;
	game->player.dir_x = game->player.dir_x * cos(-game->rot) - \
		game->player.dir_y * sin(-game->rot);
	game->player.dir_y = tmp_dir_x * sin(-game->rot) + game->player.dir_y * \
		cos(-game->rot);
	game->plane_x = game->plane_x * cos(-game->rot) - game->plane_y * \
		sin(-game->rot);
	game->plane_y = tmp_plane_x * sin(-game->rot) + game->plane_y * \
		cos(-game->rot);
}

/*Fonction qui gere la rotation gauche du joueur*/
void	rotate_left_key(t_game *game)
{
	double	tmp_plane_x;
	double	tmp_dir_x;

	tmp_plane_x = game->plane_x;
	tmp_dir_x = game->player.dir_x;
	game->player.dir_x = game->player.dir_x * cos(game->rot) - \
		game->player.dir_y * sin(game->rot);
	game->player.dir_y = tmp_dir_x * sin(game->rot) + game->player.dir_y * \
		cos(game->rot);
	game->plane_x = game->plane_x * cos(game->rot) - game->plane_y * \
		sin(game->rot);
	game->plane_y = tmp_plane_x * sin(game->rot) + game->plane_y * \
		cos(game->rot);
}

/*Fonction qui gere les mouvements du player*/
void	update_player_movement(t_game *game)
{
	if (game->mov_x == 1)
		z_key(game);
	if (game->mov_y == 1)
		s_key(game);
	if (game->left_straf == 1)
		q_key(game);
	if (game->right_straf == 1)
		d_key(game);
	if (game->rotate_x == 1)
		rotate_left_key(game);
	if (game->rotate_y == 1)
		rotate_right_key(game);
}

/*Fonction qui gere quand on presse des touches*/
int	key_press(int keycode, t_game *game)
{
	if (keycode == XK_w || keycode == XK_Up)
		game->mov_x = 1;
	else if (keycode == XK_s || keycode == XK_Down)
		game->mov_y = 1;
	else if (keycode == XK_a)
		game->left_straf = 1;
	else if (keycode == XK_d)
		game->right_straf = 1;
	else if (keycode == XK_q || keycode == XK_Left)
		game->rotate_x = 1;
	else if (keycode == XK_e || keycode == XK_Right)
		game->rotate_y = 1;
	else if (keycode == XK_Escape)
		close_everything(game);
	return (0);
}

/*Fonction qui gere le relachement des touches*/
int	key_release(int keycode, t_game *game)
{
	if (keycode == XK_w || keycode == XK_Up)
		game->mov_x = 0;
	else if (keycode == XK_s || keycode == XK_Down)
		game->mov_y = 0;
	else if (keycode == XK_a)
		game->left_straf = 0;
	else if (keycode == XK_d)
		game->right_straf = 0;
	else if (keycode == XK_q || keycode == XK_Left)
		game->rotate_x = 0;
	else if (keycode == XK_e || keycode == XK_Right)
		game->rotate_y = 0;
	return (0);
}
