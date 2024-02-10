#include "../../includes/cub3d.h"

void	z_key(t_game *game)
{
	if (!game->int_map[(int)(game->player.pos_x + game->player.dir_x * game->speed)][(int)game->player.pos_y])
		game->player.pos_x += game->player.dir_x * game->speed;
	if (!game->int_map[(int)game->player.pos_x][(int)(game->player.pos_y + game->player.dir_y * game->speed)])
		game->player.pos_y += game->player.dir_y * game->speed;
}

void	s_key(t_game *game)
{
	if (!game->int_map[(int)(game->player.pos_x - game->player.dir_x * game->speed)][(int)game->player.pos_y])
		game->player.pos_x -= game->player.dir_x * game->speed;
	if (!game->int_map[(int)game->player.pos_x][(int)(game->player.pos_y - game->player.dir_y * game->speed)])
		game->player.pos_y -= game->player.dir_y * game->speed;
}

void	q_key(t_game *game)
{
	if (!game->int_map[(int)(game->player.pos_x - game->player.dir_y * game->speed)][(int)game->player.pos_y])
		game->player.pos_x -= game->player.dir_y * game->speed;
	if (!game->int_map[(int)game->player.pos_x][(int)(game->player.pos_y + game->player.dir_x * game->speed)])
		game->player.pos_y -= -game->player.dir_x* game->speed;
}

void	d_key(t_game *game)
{
	if (!game->int_map[(int)(game->player.pos_x + game->player.dir_y * game->speed)][(int)game->player.pos_y])
		game->player.pos_x += game->player.dir_y * game->speed;
	if (!game->int_map[(int)game->player.pos_x][(int)(game->player.pos_y - game->player.dir_x * game->speed)])
		game->player.pos_y += -game->player.dir_x * game->speed;
}

void	rotate_right_key(t_game *game)
{
	double	tmp_plane_x;
	double	tmp_dir_x;

	tmp_plane_x = game->plane_x;
	tmp_dir_x = game->player.dir_x;
	game->player.dir_x = game->player.dir_x * cos(-game->rot) - game->player.dir_y * sin(-game->rot);
	game->player.dir_y = tmp_dir_x * sin(-game->rot) + game->player.dir_y * cos(-game->rot);
	game->plane_x = game->plane_x * cos(-game->rot) - game->plane_y * sin(-game->rot);
	game->plane_y = tmp_plane_x * sin(-game->rot) + game->plane_y * cos(-game->rot);
}

void	rotate_left_key(t_game *game)
{
	double	tmp_plane_x;
	double	tmp_dir_x;

	tmp_plane_x = game->plane_x;
	tmp_dir_x = game->player.dir_x;
	game->player.dir_x = game->player.dir_x * cos(game->rot) - game->player.dir_y * sin(game->rot);
	game->player.dir_y = tmp_dir_x * sin(game->rot) + game->player.dir_y * cos(game->rot);
	game->plane_x = game->plane_x * cos(game->rot) - game->plane_y * sin(game->rot);
	game->plane_y = tmp_plane_x * sin(game->rot) + game->plane_y * cos(game->rot);
}