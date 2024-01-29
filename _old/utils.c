#include "../includes/cube3d.h"

/*Fonction d'affichage des messages d'erreur*/
void	ft_error(char *str)
{
	ft_printf("Error :\n%s\n", str);
	exit(EXIT_FAILURE);
}

static void	check_file_extension(char *str)
{
	if (ft_strcmp(&str[ft_strlen(str) - 4], ".cub"))
		ft_error("Invalid file extension.");
}

/*Fonction d'affichage des éléments de la structure*/
/*Sert principalement pour le debug*/
/*
void	display_struct_values(t_game *game)
{
	int i;

	i = -1;
	ft_printf("Nb cols = %d\n", game->cols);
	ft_printf("Nb rows = %d\n", game->rows);
	ft_printf("\n   Map:	\n");
	while (game->tab[++i])
		ft_printf("%s\n", game->tab[i]);
	ft_printf("\nPlayer x pos = %d\n", game->p.x);
	ft_printf("Player y pos = %d\n", game->p.y);
	ft_printf("\nExit x pos = %d\n", game->e.x);
	ft_printf("Exit y pos = %d\n", game->e.y);
	ft_printf("\nNb colls = %d\n", game->nb_colls);
	i = -1;
	ft_printf("\n   Collectibles:   \n");
	while (++i < game->nb_colls)
		ft_printf(" x = %d  - y = %d\n", game->c[i].x, game->c[i].y);
	i = -1;
	ft_printf("\n   Map after V:	\n");
	while (game->map[++i])
		ft_printf("%s\n", game->map[i]);
}*/