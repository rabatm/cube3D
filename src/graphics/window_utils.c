#include "../../includes/cub3d.h"

/*Fonction qui affiche un pixel à l'écran - 
//reproduit reproduit mlx pixel put mais en mieux*/
void	my_pix_put(t_game *game, int x, int y, int color)
{
	char	*pixel;
	int		i;

	i = game->bpp - 8;
	pixel = game->addr + (y * game->line_len + x * (game->bpp / 8));
	while (i >= 0)
	{
		if (game->endian != 0)
			*pixel++ = (color >> (game->bpp - i)) & 0xFF;
		else 
			*pixel++ = (color >> (game->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}