/*
Fichier qui contient les fonctions d'initiationsation et de supresion
*/
#include "../../includes/cub3d.h"

static t_color	init_color(void)
{
	t_color	color;

	color.r = -1;
	color.g = -1;
	color.b = -1;
	return (color);
}

void	ft_init_game(t_game *game)
{
	game->flag = 0;
	game->color_texture.color_ceiling = init_color();
	game->color_texture.color_floor = init_color();
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
