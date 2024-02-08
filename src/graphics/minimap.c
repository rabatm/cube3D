#include "../../includes/cub3d.h"

/*Fonction qui affiche la minimap à retravailler*/
void draw_minimap(t_game *game)
{
    int i = 0;
    int j = 0;
    int x_offset = 110; // Décalage horizontal
    int y_offset = 407; // Décalage vertical
    int target_width = 150; // Largeur cible
    int target_height = 63; // Hauteur cible
    double x_scale = (double)target_width / game->max_line_len;
    double y_scale = (double)target_height / game->nb_lines;

    while (i < game->nb_lines && i < target_height)
    {
        j = 0;
        while (j < game->max_line_len && j < target_width)
        {
            if (game->tab[i][j] == '1')
            {
                // Dessiner deux points "M" pour chaque pixel correspondant
                mlx_pixel_put(game->mlx_ptr, game->win_ptr, (int)(j * x_scale) + x_offset, (int)(i * y_scale) + y_offset, 0x00C0C0C0);
                mlx_pixel_put(game->mlx_ptr, game->win_ptr, (int)(j * x_scale) + x_offset + 1, (int)(i * y_scale) + y_offset, 0x00C0C0C0);

                // Dessiner un trait horizontal plus épais
                if (j > 0 && game->tab[i][j - 1] == '1')
                {
                    int x1 = (int)(j * x_scale) + x_offset;
                    int x2 = (int)((j + 1) * x_scale) + x_offset;
                    int y = (int)(i * y_scale) + y_offset;
                    for (int k = x1; k <= x2; k++)
                    {
                        mlx_pixel_put(game->mlx_ptr, game->win_ptr, k, y, 0x00C0C0C0);
                    }
                }
            }
            else if (game->tab[i][j] == '0')
            {
                // Dessiner deux points "M" pour chaque pixel correspondant
                mlx_pixel_put(game->mlx_ptr, game->win_ptr, (int)(j * x_scale) + x_offset, (int)(i * y_scale) + y_offset, 0x000000FF);
                mlx_pixel_put(game->mlx_ptr, game->win_ptr, (int)(j * x_scale) + x_offset + 1, (int)(i * y_scale) + y_offset, 0x000000FF);
            }

            j++;
        }
        i++;
    }
}
