#include "../../includes/cub3d.h"

/*Fonction qui vérifie qu'il n'y a que des espaces,
// des 0, des 1, et soit S, N, W, E dans la map*/
static int	check_chars_in_map(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->tab[++i])
	{
		j = 0;
		while (game->tab[i][j])
		{
			if (game->tab[i][j] != ' ' && game->tab[i][j] != '0' \
				&& game->tab[i][j] != '1' && game->tab[i][j] != 'S' \
				&& game->tab[i][j] != 'N' && game->tab[i][j] != 'W' \
				&& game->tab[i][j] != 'E')
				free_errors2(game, "Map contains invalid characters. \
					Valid characters are 1, 0, spaces, N, S, W, or E");
			j++;
		}
	}
	return (0);
}

/*Fonction qui verifie qu'il n'y a qu'un seul joueur sur la map*/
static int	check_player(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	game->player.x = 0;
	game->player.y = 0;
	while (game->tab[++i])
	{
		j = 0;
		while (game->tab[i][j])
		{
			if (game->tab[i][j] == 'N' || game->tab[i][j] == 'S' \
				|| game->tab[i][j] == 'E' || game->tab[i][j] == 'W')
			{
				if (game->player.x != 0)
					free_errors2(game, "Only 1 player is allowed on the map.");
				game->player.x = j;
				game->player.y = i;
				game->init_dir = game->tab[i][j];
			}
			j++;
		}
	}
	if (game->player.x == 0)
		free_errors2(game, "There is no player in this map.");
	return (0);
}

/*Fonction qui verifie que la map est valide*/
void	check_map(t_game *game)
{
	get_max_line_len(game);
	get_nb_lines(game);
	check_chars_in_map(game);
	get_map_rectangular(game);
	check_player(game);
	check_walls(game);
	/*fonction qui transforme la map de chars en map d int*/
	dup_matrix_into_int_map(game);
}
