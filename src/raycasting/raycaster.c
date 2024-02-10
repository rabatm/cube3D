#include "../../includes/cub3d.h"

/*Fonction qui calcule les directions des rayons*/
void	calculate_direction(t_game *game)
{
	if (game->ray_dir_x < 0)
	{
		game->step_x = -1;
		game->side_dist_x = (game->player.pos_x - game->map_x) * \
			game->delta_distance_x;
	}
	else
	{
		game->step_x = 1;
		game->side_dist_x = (game->map_x + 1.0 - game->player.pos_x) * \
			game->delta_distance_x;
	}
	if (game->ray_dir_y < 0)
	{
		game->step_y = -1;
		game->side_dist_y = (game->player.pos_y - game->map_y) * \
			game->delta_distance_y;
	}
	else
	{
		game->step_y = 1;
		game->side_dist_y = (game->map_y + 1.0 - game->player.pos_y) * \
			game->delta_distance_y;
	}
}

/*Fonction qui calcue la distance avant de heurter un mur*/
void	calculate_hit_distance_side(t_game *game)
{
	while (game->hit_wall == 0)
	{
		if (game->side_dist_x < game->side_dist_y)
		{
			game->side_dist_x += game->delta_distance_x;
			game->map_x += game->step_x;
			game->which_side = 0;
		}
		else
		{
			game->side_dist_y += game->delta_distance_y;
			game->map_y += game->step_y;
			game->which_side = 1;
		}
		if (game->int_map[game->map_x][game->map_y] > 0)
			game->hit_wall = 1;
	}
	if (game->which_side == 0)
		game->perpendicular_wall_dist = (game->map_x - game->player.pos_x + \
			((1 - game->step_x) >> 1)) / game->ray_dir_x;
	else
		game->perpendicular_wall_dist = (game->map_y - game->player.pos_y + \
			((1 - game->step_y) >> 1)) / game->ray_dir_y;
	game->line_height = (int)(WINDOW_HEIGHT / game->perpendicular_wall_dist);
}

void	start_end_pixel_in_current_line(t_game *game)
{
	game->draw_start = -(game->line_height >> 1) + (WINDOW_HEIGHT >> 1);
	if (game->draw_start < 0)
		game->draw_start = 0;
	game->draw_end = (game->line_height >> 1) + (WINDOW_HEIGHT >> 1);
	if (game->draw_end >= WINDOW_HEIGHT)
		game->draw_end = WINDOW_HEIGHT;
	if (game->which_side == 0 && game->ray_dir_x > 0)
		game->texture_number = 0;
	else if (game->which_side == 1 && game->ray_dir_y > 0)
		game->texture_number = 2;
	else if (game->which_side == 0 && game->ray_dir_x <= 0)
		game->texture_number = 1;
	else if (game->which_side == 1 && game->ray_dir_y <= 0)
		game->texture_number = 3;
	if (game->which_side == 0)
		game->wall_x = game->player.pos_y + game->perpendicular_wall_dist * \
			game->ray_dir_y;
	else
		game->wall_x = game->player.pos_x + game->perpendicular_wall_dist * \
			game->ray_dir_x;
	game->wall_x -= (int)(game->wall_x);
}

/*Fonction qui calcule les coordonnees de la texture et la dessine*/
void	calculate_texture_coord_n_draw_texture(t_game *game, int *x)
{
	double	step;
	int		y;
	int		color;

	texture_init(game);
	step = (double)TEXTURE_HEIGHT / game->line_height;
	game->texture_pos = (game->draw_start - (WINDOW_HEIGHT >> 1) + \
		(game->line_height >> 1)) * step;
	y = -1;
	while (++y < game->draw_start)
		my_pix_put(game, *x, y, game->color_texture.color_ceiling);
	y = game->draw_start - 1;
	while (++y < game->draw_end)
	{
		game->texture_y = (int)game->texture_pos & (TEXTURE_HEIGHT - 1);
		game->texture_pos += step;
		color = game->textures[game->texture_number] \
			[TEXTURE_HEIGHT * game->texture_y + game->texture_x];
		my_pix_put(game, *x, y, color);
	}
	y = game->draw_end - 1;
	while (++y <= WINDOW_HEIGHT)
		my_pix_put(game, *x, y, game->color_texture.color_floor);
}

/*Fonction prinicpale du raycasting*/
void	raycaster(t_game *game)
{
	int x; 

	x= -1;
	while (++x < WINDOW_WIDTH)
	{
		//calculate ray position and direction
		game->camera_x = 2 * x / (double)WINDOW_WIDTH - 1; //x-coordinate in camera space
		game->ray_dir_x = game->player.dir_x + game->plane_x * game->camera_x;
		game->ray_dir_y = game->player.dir_y + game->plane_y * game->camera_x;
		game->map_x = (int)(game->player.pos_x);
		game->map_y = (int)(game->player.pos_y);
		game->delta_distance_x = fabs(1 / game->ray_dir_x);
		game->delta_distance_y = fabs(1 / game->ray_dir_y);
		game->hit_wall = 0;
		calculate_direction(game);
		calculate_hit_distance_side(game);
		start_end_pixel_in_current_line(game);
		calculate_texture_coord_n_draw_texture(game, &x);
	}
}
