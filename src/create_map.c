#include "../includes/cub3d.h"

void	create_window(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == NULL)
		return (1);
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->res_y * game->max_line_len, \
		game->res_x * game->nb_lines, "Cub3D");
	if (game->win_ptr == NULL)
	{
		free(game->win_ptr);
		return (1);
	}
	// display_text(game);
	// mlx_loop_hook(game->mlx_ptr, &display_pix, game);
	// mlx_hook(game->win_ptr, KeyPress, KeyPressMask, &handle_keypress, game);
	// mlx_hook(game->win_ptr, 17, 1L << 0, &close_everything, game);
	mlx_loop(game->mlx_ptr);
}
