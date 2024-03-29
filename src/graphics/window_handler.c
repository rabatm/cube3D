/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martin <martin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 21:06:25 by orauline          #+#    #+#             */
/*   Updated: 2024/02/11 17:05:49 by martin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/*Fonction qui gere tous les affichages*/
int	render(t_game *game)
{
	update_player_movement(game);
	raycaster(game);
	draw_minimap(game);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->buffer, 0, 0);
	my_heal_bar(game);
	r_head(game);
	return (0);
}

/*Fonction qui affiche la fenetre avec minimap*/
int	init_window(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == NULL)
		return (1);
	game->win_ptr = mlx_new_window(game->mlx_ptr, WINDOW_WIDTH, \
		WINDOW_HEIGHT, "./cub3D");
	if (game->win_ptr == NULL)
	{
		free(game->win_ptr);
		return (1);
	}
	init_textures(game);
	init_hb(game);
	init_head(game);
	game->buffer = mlx_new_image(game->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	game->addr = mlx_get_data_addr(game->buffer, &game->bpp, \
		&game->line_len, &game->endian);
	mlx_mouse_hook(game->win_ptr, handle_mouse_click, game);
	mlx_hook(game->win_ptr, 6, 1L << 6, handle_mouse_move, game);
	mlx_hook(game->win_ptr, KeyPress, 1, &key_press, game);
	mlx_hook(game->win_ptr, KeyRelease, 10, &key_release, game);
	mlx_hook(game->win_ptr, 5, 1L << 0, handle_mouse_release, game);
	mlx_loop_hook(game->mlx_ptr, &render, game);
	mlx_hook(game->win_ptr, 17, 1L << 0, &close_everything, game);
	mlx_loop(game->mlx_ptr);
	return (0);
}
