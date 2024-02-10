#include "../../includes/cub3d.h"

/*Fonction qui dessine les rayons sur la minimap*/
void	draw_minimap_ray(t_game *game)
{
	double	p_pos_x;
	double	p_pos_y;
	double mm_max_x;
	double mm_max_y;
	int i = -1;

	p_pos_x = (double)game->player.pos_x * (WINDOW_HEIGHT * MM_ZOOM) + 5;
	p_pos_y = (double)game->player.pos_y * (WINDOW_HEIGHT * MM_ZOOM) + 5;
	mm_max_y = (game->nb_rows * (WINDOW_HEIGHT * MM_ZOOM) + 5);
	mm_max_x = (game->nb_cols * (WINDOW_HEIGHT * MM_ZOOM) + 5);
	// printf("max y = %lf\n", mm_max_y);
	my_pix_put(game, p_pos_x, p_pos_y, RED);
	while (++i < mm_max_y - p_pos_y || i < mm_max_x - p_pos_x || p_pos_x + i > 5 || p_pos_y + i > 5)
	{
		if (game->int_map[(int)((p_pos_x - 5) / 24)][(int)((p_pos_y + i - 5) / 24)])
			break ;
		my_pix_put(game, p_pos_x, p_pos_y + i, RED);
		// printf("valeur pos x = %d, pos y + i = %d\n", (((int)(p_pos_x - 5) / 24)), ((int)(p_pos_y + i - 5) / 24));
		// printf("valeur de int map de ces coordonnees = %d\n", game->int_map[(int)((p_pos_x - 5) / 24)][(int)((p_pos_y + i - 5) / 24)]);
	}
}

/*Fonction qui dessine chaque pixel*/
void draw_pixel(t_game *game, int i, int j, int color)
{
	int y;
	int x;

	x = 0;
	y = 0;
	y = WINDOW_HEIGHT * MM_ZOOM * i;
	while (y < WINDOW_HEIGHT * MM_ZOOM * (i + 1))
	{
		x = WINDOW_HEIGHT * MM_ZOOM * j;
		while (x < WINDOW_HEIGHT * MM_ZOOM * (j + 1))
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
			if (game->int_map[game->nb_cols - 1 - i][j])
				draw_pixel(game, j, i, WALLS_MM_COLOR);
			j++;
		}
		i++;
	}
	draw_pixel(game, game->player.pos_y, game->nb_cols - game->player.pos_x, PL_MM_COLOR);
}

