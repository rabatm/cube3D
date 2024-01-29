#include "../includes/cub3d.h"

/*Fonction qui récupère seulement la map du fichier de config à partir de la 6ème ligne de config afin de faire les check*/
void	get_map_from_config(t_game *game)
{
	int	i;
	int	j;
	int	map_size;

	i = 6;
	while (game->config[++i])
		;
	map_size = i - 6;
	game->tab = malloc(sizeof(char *) * (map_size + 1));
	game->tab[map_size] = NULL;
	i = 5;
	while (++i < map_size + 6)
	{
		game->tab[i - 6] = malloc(sizeof(char) * (ft_strlen(game->config[i]) + 1));
		game->tab[i - 6][ft_strlen(game->config[i])] = '\0';
	}
	i = 5;
	while (game->config[++i])
	{
		j = -1;
		while (game->config[i][++j])
			game->tab[i - 6][j] = game->config[i][j];
	}
}
/*Fonction qui remplit la map d'espaces afin de simplifier les vérifications utlérieures de la map*/
void	get_map_rectangular(t_game *game)
{
	int	i;
	int	j;

	if (game->nb_lines < 3 || game->max_line_len < 3)
		free_errors2(game, "Map is too small.");
	game->matrix = malloc(sizeof(char *) * (game->nb_lines + 1));
	game->matrix[game->nb_lines] = NULL;
	i = -1;
	while (++i < game->nb_lines)
	{
		j = -1;
		game->matrix[i] = malloc(sizeof(char) * (game->max_line_len + 1));
		game->matrix[i][game->max_line_len] = '\0';
		while (++j < game->max_line_len)
			game->matrix[i][j] = ' ';
	}
	i = -1;
	while (game->tab[++i])
	{
		j = -1;
		while (game->tab[i][++j])
		{
			game->matrix[i][j] = game->tab[i][j];
		}
	}
}
