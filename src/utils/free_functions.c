#include "../../includes/cub3d.h"

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
}
