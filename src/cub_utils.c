#include "../includes/cub3d.h"

/*Fonction qui affiche le message d'erreur et termine le programme correctement*/
void	ft_error(char *str)
{
	ft_printf("Error :\n%s\n", str);
	exit(EXIT_FAILURE);
}

/*Fonction qui récupère la valeur de la ligne la plus longue*/
void	get_max_line_len(t_game *game)
{
	int	i;
	int	j;
	int	max;

	i = -1;
	max = 0;
	while (game->tab[++i])
	{
		j = 0;
		while (game->tab[i][j])
			j++;
		if (j > max)
			max = j;
	}
	game->max_line_len = max;
	ft_printf("Max line = %d\n", game->max_line_len);
}

/*Fonction qui récupère la valeur du nombre de lignes*/
void	get_nb_lines(t_game *game)
{
	int	i;

	i = -1;
	while (game->tab[++i])
		;
	game->nb_lines = i;
	ft_printf("Nb lines = %d\n", game->nb_lines);
}

/*Fonction qui affiche les élements de la structure
Sert principalement pour débugger*/
void	display_struct_values(t_game *game)
{
	int i;

	i = -1;
	ft_printf("Nb cols = %d\n", game->max_line_len);
	ft_printf("Nb rows = %d\n", game->nb_lines);

	// ft_printf("\nPlayer x pos = %d\n", game->player.x);
	// ft_printf("Player y pos = %d\n", game->player.y);
	// ft_printf("\nNb colls = %d\n", game->nb_colls);
	// i = -1;
	// ft_printf("\n   Collectibles:   \n");
	// while (++i < game->nb_colls)
	// 	ft_printf(" x = %d  - y = %d\n", game->c[i].x, game->c[i].y);

	i = -1;
	ft_printf("\n   Config file:	\n");
	while (game->config[++i])
		ft_printf("%s\n", game->config[i]);
	i = -1;
	ft_printf("\n   Map:	\n");
	while (game->tab[++i])
		ft_printf("%s\n", game->tab[i]);

	i = -1;
	ft_printf("\n   Map after became rectangular:	\n");
	while (game->matrix[++i])
		ft_printf("%s\n", game->matrix[i]);
}
