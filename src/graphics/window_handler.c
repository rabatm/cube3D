#include "../../includes/cub3d.h"

/*Fonction qui affiche une fenetre vide pour l'instant*/
int	init_window(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == NULL)
		return (1);
	game->win_ptr = mlx_new_window(game->mlx_ptr, TILE_SIZE \
		* game->max_line_len, TILE_SIZE * game->nb_lines, "./cub3D");
	if (game->win_ptr == NULL)
	{
		free(game->win_ptr);
		return (1);
	}
	//gestion de la touches ESC pour fermer la fenetre
	mlx_hook(game->win_ptr, KeyPress, KeyPressMask, &handle_escape, game);
	//gestion de la fermeture de la fenetre avec la croix
	mlx_hook(game->win_ptr, 17, 1L << 0, &close_everything, game);


	//display_map_on_window(game);
	// mlx_loop_hook(game->mlx_ptr, &display_pix, game);
	mlx_loop(game->mlx_ptr);
	return (0);
}

// void	display_map_on_window(t_game *game)
// {
// 	int	i;
// 	int	j;

// 	i = -1;
// 	while (++i < game->nb_lines)
// 	{
// 		j = -1;
// 		while (++j < game->max_line_len)
// 		{
// 			if (game->tab[i][j] == '1')
// 				mlx_pixel_put(game->mlx_ptr, game->win_ptr, j, i, 0x00FF0000);
// 			else if (game->tab[i][j] == '0')
// 				mlx_pixel_put(game->mlx_ptr, game->win_ptr, j, i, 0x000000FF);
// 		}
// 	}
// }
