#include "../../includes/cub3d.h"

/*Fonction qui affiche le message d'erreur
// et termine le programme correctement*/
void	ft_error(char *str)
{
	ft_printf("\033[31mError : %s\n\033[0m", str);
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
	game->nb_cols = game->max_line_len;
	// ft_printf("Max line = %d\n", game->max_line_len);
}

/*Fonction qui récupère la valeur du nombre de lignes*/
void	get_nb_lines(t_game *game)
{
	int	i;

	i = -1;
	while (game->tab[++i])
		;
	game->nb_lines = i;
	game->nb_rows = game->nb_lines;
	// ft_printf("Nb lines = %d\n", game->nb_lines);
}
/*Fonction qui free proprement les éléments alloués 
// lorsque l on ferme la fenetre avec escape ou avec la croix*/
int	close_everything(t_game *game)
{
	free_all(game);
	mlx_destroy_image(game->mlx_ptr, game->buffer);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	exit(0);
}

/*Fonction qui affiche les élements de la structure
Sert principalement pour débugger*/
void	display_struct_values(t_game *game)
{
	int	i;

	// i = -1;
	// ft_printf("Nb cols = %d\n", game->max_line_len);
	// ft_printf("Nb rows = %d\n", game->nb_lines);
	// ft_printf("Nb cols = %d\n", game->nb_cols);
	// ft_printf("Nb rows = %d\n", game->nb_rows);
	// ft_printf("F color = %d\n", game->color_texture.color_floor);
	// ft_printf("C color = %d\n", game->color_texture.color_ceiling);
	// ft_printf("\nPlayer x pos = %d\n", game->player.x);
	// ft_printf("Player y pos = %d\n", game->player.y);
	// ft_printf("\nNb colls = %d\n", game->nb_colls);
	// i = -1;
	// ft_printf("\n   Collectibles:   \n");
	// while (++i < game->nb_colls)
	// 	ft_printf(" x = %d  - y = %d\n", game->c[i].x, game->c[i].y);
	// i = -1;
	// ft_printf("\n   Config file:	\n");
	// while (game->config[++i])
	// 	ft_printf("%s\n", game->config[i]);
	// i = -1;
	// ft_printf("\n   Map:	\n");
	// while (game->tab[++i])
	// 	ft_printf("%s\n", game->tab[i]);
	// i = -1;
	// ft_printf("\n   Map after became rectangular:	\n");
	// while (game->matrix[++i])
	// 	ft_printf("%s\n", game->matrix[i]);
	i = -1;
	int j;
	ft_printf("\n  ------------------------- Map after became int:--------------	\n");
	while (++i < game->nb_rows)
	{
		j = -1;
		while (++j < game->nb_cols)
			ft_printf("%d", game->int_map[j][i]);
		ft_printf("\n");
	}
	ft_printf("\n");
}
