#include "../../includes/cub3d.h"

/*Fonction qui affiche le sol et le ciel*/
void	draw_sky_n_floor(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < WINDOW_HEIGHT / 2)
	{
		j = -1;
		while (++j < WINDOW_WIDTH)
			my_pix_put(game, j, i, game->color_texture.color_ceiling);
	}
	while (i < WINDOW_HEIGHT)
	{
		j = -1;
		while (++j < WINDOW_WIDTH)
			my_pix_put(game, j, i, game->color_texture.color_floor);
		i++;
	}
}

int	render(t_game *game)
{
	if (game->win_ptr == NULL)
		return (1);
	draw_sky_n_floor(game);
	draw_minimap(game);
	draw_ray(game);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->buffer, 0, 0);
	// r_head(game);
	//my_heal_bar(game);

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
	// my_heal_bar(game);
	game->buffer = mlx_new_image(game->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	game->addr = mlx_get_data_addr(game->buffer, &game->bpp, &game->line_len, &game->endian);
	//gestion de la touches ESC pour fermer la fenetre
	mlx_hook(game->win_ptr, KeyPress, KeyPressMask, &handle_escape, game);
	mlx_loop_hook(game->mlx_ptr, &render, game);
	//gestion de la fermeture de la fenetre avec la croix
	mlx_hook(game->win_ptr, 17, 1L << 0, &close_everything, game);
	mlx_loop(game->mlx_ptr);

	return (0);
}
