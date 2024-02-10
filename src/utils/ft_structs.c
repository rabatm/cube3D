/*
Fichier qui contient les fonctions d'initiationsation et de supresion
*/
#include "../../includes/cub3d.h"

void	ft_init_game(t_game *game)
{
	game->color_texture.color_ceiling = -1;
	game->color_texture.color_floor = -1;
	game->color_texture.texture_north = NULL;
	game->color_texture.texture_south = NULL;
	game->color_texture.texture_west = NULL;
	game->color_texture.texture_east = NULL;
	game->config = NULL;
	game->tab = NULL;
	game->matrix = NULL;
	game->nb_lines = 0;
	game->max_line_len = 0;
	game->resolution_x = 0;
	game->resolution_y = 0;
	game->player.dir_x = 0;
	game->player.dir_y = 0;
	game->plane_x = 0;
	game->plane_y = 0;
	game->speed = SPEED;
	game->mov_x = 0;
	game->mov_y = 0;
	game->rotate_x = 0;
	game->rotate_y = 0;
	game->left_straf = 0;
	game->right_straf = 0;
	game->rot = ROTATION_SPEED;
}
