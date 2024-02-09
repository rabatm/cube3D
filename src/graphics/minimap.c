#include "../../includes/cub3d.h"

/*Fonction qui dessine chaque pixel*/
static void draw_pixel(t_game *game, int i, int j, int color)
{
	int y;
	int x;

	x = 0;
	y = 0;
	y = WINDOW_HEIGHT * 0.01 * i;
	while (y < WINDOW_HEIGHT * 0.01 * (i + 1))
	{
		x = WINDOW_HEIGHT * 0.01 * j;
		while (x < WINDOW_HEIGHT * 0.01 * (j + 1))
		{
			my_pix_put(game, x + 5, y + 5, color);
			x++;
		}
		y++;
	}
}
/*Fonction qui dessine la minimap à partir de la map d'int*/
void draw_minimap(t_game *game)
{
	int i;
	int j;

	i = 0;
	while (i < game->nb_cols)
	{
		j = 0;
		while (j < game->nb_rows)
		{
			if (game->int_map[i][j])
				draw_pixel(game, j, i, WALLS_MM_COLOR);
			j++;
		}
		i++;
	}
	draw_pixel(game, game->player.y, game->player.x, PL_MM_COLOR);
}

/*Fonction qui affiche la minimap vesion Martin*/
// void draw_minimap(t_game *game)
// {
//     int i = 0;
//     int j = 0;
//     int x_offset = 110; // Décalage horizontal
//     int y_offset = 200; // Décalage vertical
//     int target_width = 150; // Largeur cible
//     int target_height = 63; // Hauteur cible
//     double x_scale = (double)target_width / (game->max_line_len / 2);
//     double y_scale = (double)target_height / (game->nb_lines / 2);

//     while (i < game->nb_lines && i < target_height)
//     {
//         j = 0;
//         while (j < game->max_line_len && j < target_width)
//         {
//             if (game->tab[i][j] == '1')
//             {
//                 // Dessiner deux points "M" pour chaque pixel correspondant
//                 mlx_pixel_put(game->mlx_ptr, game->win_ptr, (int)(j * x_scale) + x_offset, (int)(i * y_scale) + y_offset, 0x00C0C0C0);
//                 mlx_pixel_put(game->mlx_ptr, game->win_ptr, (int)(j * x_scale) + x_offset + 1, (int)(i * y_scale) + y_offset, 0x00C0C0C0);

//                 // Dessiner un trait horizontal plus épais
//                 if (j > 0 && game->tab[i][j - 1] == '1')
//                 {
//                     int x1 = (int)(j * x_scale) + x_offset;
//                     int x2 = (int)((j + 1) * x_scale) + x_offset;
//                     int y = (int)(i * y_scale) + y_offset;
//                     for (int k = x1; k <= x2; k++)
//                     {
//                         mlx_pixel_put(game->mlx_ptr, game->win_ptr, k, y, 0x00C0C0C0);
//                     }
//                 }
//             }
//             else if (game->tab[i][j] == '0')
//             {
//                 // Dessiner deux points "M" pour chaque pixel correspondant
//                 mlx_pixel_put(game->mlx_ptr, game->win_ptr, (int)(j * x_scale) + x_offset, (int)(i * y_scale) + y_offset, 0x000000FF);
//                 mlx_pixel_put(game->mlx_ptr, game->win_ptr, (int)(j * x_scale) + x_offset + 1, (int)(i * y_scale) + y_offset, 0x000000FF);
//             }

//             j++;
//         }
//         i++;
//     }
// }
