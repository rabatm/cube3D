#include "../../includes/cub3d.h"

void	init_player(t_game *game)
{
	game->player.pos_x = game->nb_cols -1 - game->player.x + 0.5;
	game->player.pos_y = game->player.y + 0.5;
	if (game->init_dir == 'N')
	{
		game->player.dir_y = -1;
		game->plane_x = -0.66;
	}
	if (game->init_dir == 'S')
	{
		game->player.dir_y = 1;
		game->plane_x = 0.66;
	}
	if (game->init_dir == 'W')
	{
		game->player.dir_x = 1;
		game->plane_y = -0.66;
	}
	if (game->init_dir == 'E')
	{
		game->player.dir_x = -1;
		game->plane_y = 0.66;
	}
}
