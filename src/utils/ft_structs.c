/*
Fichier qui contient les fonctions d'initiationsation et de supresion
*/
#include "../../includes/cube3d.h"

void	ft_init_game(t_game *game)
{
	game = malloc(sizeof(t_game));
	if (game == NULL)
		ft_error("malloc error");
	
}