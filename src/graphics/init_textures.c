#include "../../includes/cub3d.h"

void	load_image(t_game *game, int *texture, char *file, t_img *img)
{
	int	x;
	int	y;

	img->img = mlx_xpm_file_to_image(game->mlx_ptr, file, &img->img_width, &img->img_height);
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp, &img->size_line, &img->endian);
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

void	load_textures(t_game *game)
{
	t_img	img;

	load_image(game, game->textures[0], game->color_texture.texture_north, &img);
	load_image(game, game->textures[1], game->color_texture.texture_south, &img);
	load_image(game, game->textures[2], game->color_texture.texture_west, &img);
	load_image(game, game->textures[3], game->color_texture.texture_east, &img);
}

void	init_textures(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	game->textures = (int **)malloc(sizeof(int *) * NB_TEXTURES);
	while (++i < NB_TEXTURES)
		game->textures[i] = (int *)malloc(sizeof(int) * TEXTURE_WIDTH * TEXTURE_HEIGHT);
	i = -1;
	while (++i < NB_TEXTURES)
	{
		j = -1;
		while (++j < TEXTURE_WIDTH * TEXTURE_HEIGHT)
			game->textures[i][j] = 0;
	}
	load_textures(game);
}
