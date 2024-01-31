/*
Fichier qui contient les fonctions d'initiationsation et de supresion
*/
#include "../../includes/cub3d.h"

void	ft_init_game(t_game *game)
{
	game->flag = 0;
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
}