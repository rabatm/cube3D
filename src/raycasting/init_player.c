#include "../../includes/cub3d.h"

void	init_player(t_game *game)
{
	game->player.pos_x = game->player.x + 0.5;
	game->player.pos_y = game->player.y + 0.5;
	game->player.dir_x = 0;
	game->player.dir_y = 0;
	if (game->init_dir == 'N')
		game->player.dir_y = -1;
	if (game->init_dir == 'S')
		game->player.dir_y = 1;
	if (game->init_dir == 'W')
		game->player.dir_x = -1;
	if (game->init_dir == 'E')
		game->player.dir_x = 1;
	// printf("Dir x = %lf, dir y = %lf \n", game->player.dir_x, game->player.dir_y);
	// printf("Pos x = %lf, pos y = %lf \n", game->player.pos_x, game->player.pos_y);
}