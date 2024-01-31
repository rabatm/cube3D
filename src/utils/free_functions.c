#include "../../includes/cub3d.h"

static void free_color_texture(t_ctext *color_texture) {
    free(color_texture->texture_north);
    free(color_texture->texture_south);
    free(color_texture->texture_west);
    free(color_texture->texture_east);
    // libérer d'autres champs si nécessaire
}
/*Fonction qui free les tableaux précédemment malloc en cas d'erreur*/
void	free_errors(t_game *game)
{
	int	i;

	i = -1;
	while (game->tab[++i])
		free(game->tab[i]);
	free(game->tab);
	i = -1;
	while (game->config[++i])
		free(game->config[i]);
	free(game->config);
	i = -1;
	while (game->matrix[++i])
		free(game->matrix[i]);
	free(game->matrix);
	free_color_texture(&(game->color_texture));
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
	int	i;

	i = -1;
	while (game->tab[++i])
		free(game->tab[i]);
	free(game->tab);
	i = -1;
	while (game->config[++i])
		free(game->config[i]);
	free(game->config);
	i = -1;
	while (game->matrix[++i])
		free(game->matrix[i]);
	free(game->matrix);
	free_color_texture(&(game->color_texture));
}
