#include "../../includes/cub3d.h"



void	img_pix_put(t_img *img, int x, int y, int color)
{
    char    *pixel;

    pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
    *(int *)pixel = color;
}

/*Fonction qui affiche le sol et le ciel*/
void	draw_sky_n_floor(t_game *game, t_ctext *color_texture)
{
	int	i;
	int	j;

	i = -1;
	while (++i < WINDOW_HEIGHT / 2)
	{
		j = -1;
		while (++j < WINDOW_WIDTH)
			img_pix_put(&game->img, j, i, color_texture->color_ceiling);
	}
	while (i < WINDOW_HEIGHT)
	{
		j = -1;
		while (++j < WINDOW_WIDTH)
			img_pix_put(&game->img, j, i, color_texture->color_floor);
		i++;
	}
}
int	render(t_game *game)
{
	if (game->win_ptr == NULL)
		return (1);
	draw_sky_n_floor(game, &game->color_texture);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img.mlx_img, 0, 0);

	return (0);
}

/*Fonction qui affiche une fenetre vide pour l'instant avec minimap*/
int	init_window(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == NULL)
		return (1);
	game->win_ptr = mlx_new_window(game->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "./cub3D");
	if (game->win_ptr == NULL)
	{
		free(game->win_ptr);
		return (1);
	}
	//gestion de la touches ESC pour fermer la fenetre
	mlx_hook(game->win_ptr, KeyPress, KeyPressMask, &handle_escape, game);
	//gestion de la fermeture de la fenetre avec la croix
	mlx_hook(game->win_ptr, 17, 1L << 0, &close_everything, game);

	//fonction qui affiche la minimap mais à retravailler
	draw_minimap(game);
	game->img.mlx_img = mlx_new_image(game->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	game->img.addr = mlx_get_data_addr(game->img.mlx_img, &game->img.bpp,&game->img.line_len, &game->img.endian);
	mlx_loop_hook(game->mlx_ptr, &render, game);
	mlx_loop(game->mlx_ptr);
	return (0);
}
