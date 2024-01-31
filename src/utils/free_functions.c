#include "../../includes/cub3d.h"

void	free_ct_conf(t_game *game)
{
	free(game->color_texture.texture_north);
	free(game->color_texture.texture_south);
	free(game->color_texture.texture_west);
	free(game->color_texture.texture_east);
	ft_free_char_array(game->config);
}

/*Fonction qui free les tableaux précédemment malloc en cas d'erreur*/
void	free_errors(t_game *game)
{
	ft_free_char_array(game->tab);
	ft_free_char_array(game->matrix);
	free_ct_conf(game);
}

/*Fonction qui free les tableaux + indique le message d'erreur correspondant*/
void	free_errors2(t_game *game, char *str)
{
	free_errors(game);
	ft_error(str);
}

/*Fonction qui free tout en fin de programme*/
void	free_all(t_game *game)
{
	ft_free_char_array(game->tab);
	ft_free_char_array(game->matrix);
	free_ct_conf(game);
}

void	free_ct_conf_error(t_game *game, char *msg)
{
	free_ct_conf(game);
	ft_error(msg);
}
