#include "../../includes/cub3d.h"

void	draw_ray(t_game *game)
{
	double	p_pos_x;
	double	p_pos_y;
	int i = -1;

	p_pos_x = (double)game->player.pos_x * (WINDOW_HEIGHT * MM_ZOOM) + 5;
	p_pos_y = (double)game->player.pos_y * (WINDOW_HEIGHT * MM_ZOOM) + 5;
	double mm_max_y = (game->nb_rows * (WINDOW_HEIGHT * MM_ZOOM) + 5);
	// printf("max y = %lf\n", mm_max_y);
	my_pix_put(game, p_pos_x, p_pos_y, RED);
	while (++i < mm_max_y - p_pos_y)
	{
		if (game->int_map[(int)((p_pos_x - 5) / 24)][(int)((p_pos_y + i - 5) / 24)])
			break ;
		my_pix_put(game, p_pos_x, p_pos_y + i, RED);
		printf("valeur pos x = %d, pos y + i = %d\n", (((int)(p_pos_x - 5) / 24)), ((int)(p_pos_y + i - 5) / 24));
		printf("valeur de int map de ces coordonnees = %d\n", game->int_map[(int)((p_pos_x - 5) / 24)][(int)((p_pos_y + i - 5) / 24)]);
	}
}