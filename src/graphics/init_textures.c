/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orauline <orauline@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 20:44:07 by orauline          #+#    #+#             */
/*   Updated: 2024/02/10 21:06:07 by orauline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	texture_init(t_game *game)
{
	game->texture_x = (int)(game->wall_x * (double)TEXTURE_WIDTH);
	if (game->which_side == 0 && game->ray_dir_x > 0)
		game->texture_x = TEXTURE_WIDTH - game->texture_x - 1;
	if (game->which_side == 1 && game->ray_dir_y < 0)
		game->texture_x = TEXTURE_WIDTH - game->texture_x - 1;
}

/*Fonction qui transforme les xpm en image et récupère l addresse pour 
// l'afficher puis detruit l image comme ca on a pas a gerer d eventuels 
//leaks lies a la mlx*/
void	load_image(t_game *game, int *texture, char *file, t_img *img)
{
	int	x;
	int	y;

	img->img = mlx_xpm_file_to_image(game->mlx_ptr, file, &img->img_width, \
		&img->img_height);
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp, \
		&img->size_line, &img->endian);
	y = 0;
	while (y < img->img_height)
	{
		x = 0;
		while (x < img->img_width)
		{
			texture[img->img_width * y + x] = img->data[img->img_width * y + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(game->mlx_ptr, img->img);
}

/*Fonction qui récupère les textures correspondantes*/
void	load_textures(t_game *game)
{
	t_img	img;

	load_image(game, game->textures[0], \
		game->color_texture.texture_north, &img);
	load_image(game, game->textures[1], \
		game->color_texture.texture_south, &img);
	load_image(game, game->textures[2], \
		game->color_texture.texture_west, &img);
	load_image(game, game->textures[3], \
		game->color_texture.texture_east, &img);
}

/*Fonction qui initialise les textures à 0*/
void	init_textures(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	game->textures = (int **)malloc(sizeof(int *) * NB_TEXTURES);
	while (++i < NB_TEXTURES)
		game->textures[i] = (int *)malloc(sizeof(int) \
			* TEXTURE_WIDTH * TEXTURE_HEIGHT);
	i = -1;
	while (++i < NB_TEXTURES)
	{
		j = -1;
		while (++j < TEXTURE_WIDTH * TEXTURE_HEIGHT)
			game->textures[i][j] = 0;
	}
	load_textures(game);
}
