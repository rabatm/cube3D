#include "../../includes/cub3d.h"

/*Fonction qui gere les mouvements du player*/
void	update_player_movement(t_game *game)
{
	if (game->mov_x == 1)
		z_key(game);
	if (game->mov_y == 1)
		s_key(game);
	if (game->left_straf == 1)
		q_key(game);
	if (game->right_straf == 1)
		d_key(game);
	if (game->rotate_x == 1)
		rotate_left_key(game);
	if (game->rotate_y == 1)
		rotate_right_key(game);
}
/*Fonction qui gere quand on presse des touches*/
int key_press(int keycode, t_game *game)
{
	if (keycode == XK_w || keycode == XK_Up)
		game->mov_x = 1;
	else if (keycode == XK_s || keycode == XK_Down)
		game->mov_y = 1;
	else if (keycode == XK_a)
		game->left_straf = 1;
	else if (keycode == XK_d)
		game->right_straf = 1;
	else if (keycode == XK_q || keycode == XK_Left)
		game->rotate_x = 1;
	else if (keycode == XK_e || keycode == XK_Right)
		game->rotate_y = 1;
	else if (keycode == XK_Escape)
		close_everything(game);
	return (0);
}
/*Fonction qui gere le relachement des touches*/
int key_release(int keycode, t_game *game)
{
	if (keycode == XK_w || keycode == XK_Up)
		game->mov_x = 0;
	else if (keycode == XK_s || keycode == XK_Down)
		game->mov_y = 0;
	else if (keycode == XK_a)
		game->left_straf = 0;
	else if (keycode == XK_d)
		game->right_straf = 0;
	else if (keycode == XK_q || keycode == XK_Left)
		game->rotate_x = 0;
	else if (keycode == XK_e || keycode == XK_Right)
		game->rotate_y = 0;
	return (0);
}
