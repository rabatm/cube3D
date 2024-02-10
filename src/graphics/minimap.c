/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orauline <orauline@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 21:10:01 by orauline          #+#    #+#             */
/*   Updated: 2024/02/10 21:11:18 by orauline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/*Fonction qui dessine chaque pixel de la minimap zoomee*/
void	draw_pixel(t_game *game, int i, int j, int color)
{
	int	y;
	int	x;

	x = 0;
	y = 0;
	y = WINDOW_HEIGHT * MM_ZOOM * i;
	while (y < WINDOW_HEIGHT * MM_ZOOM * (i + 1))
	{
		x = WINDOW_HEIGHT * MM_ZOOM * j;
		while (x < WINDOW_HEIGHT * MM_ZOOM * (j + 1))
		{
			my_pix_put(game, x + 5, y + 5, color);
			x++;
		}
		y++;
	}
}

/*Fonction qui dessine la minimap à partir de la map d'int*/
void	draw_minimap(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->nb_cols)
	{
		j = 0;
		while (j < game->nb_rows)
		{
			if (game->int_map[game->nb_cols - 1 - i][j])
				draw_pixel(game, j, i, WALLS_MM_COLOR);
			j++;
		}
		i++;
	}
	draw_pixel(game, game->player.pos_y, game->nb_cols - game->player.pos_x, \
		PL_MM_COLOR);
}
