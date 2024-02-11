#include "../../includes/cub3d.h"
//fonction qui gere le click de la souris, 
//si on appuie sur le click gauche, on met la variable left_click a 1
//on enregistre la position x de la souris
int	handle_mouse_click(int button, int x, int y, t_game *game)
{
	(void)y;
	if (button == 1)
		game->left_click = 1;
	game->prev_m_x = x;
	return (0);
}

//fonction qui gere le relachement du click de la souris
//si on relache le click gauche, on met la variable left_click a 0
int	handle_mouse_release(int button, int x, int y, t_game *game)
{
	(void)y;
	(void)x;
	if (button == 1)
		game->left_click = 0;
	return (0);
}

//fonction qui gere le mouvement de la souris
//si on bouge la souris vers la droite, 
//on lance la fonction pour tourner a droite
//si on bouge la souris vers la gauche, 
//on lance la fonction pour tourner a gauche
int	handle_mouse_move(int x, int y, t_game *game)
{
	(void)y;
	if (game->left_click == 1)
	{
		if (x > game->prev_m_x)
			rotate_right_key(game);
		else if (x < game->prev_m_x)
			rotate_left_key(game);
		game->prev_m_x = x;
	}
	return (0);
}
