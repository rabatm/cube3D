#include "../includes/cub3d.h"

/**
fichier main du projet cub3d
ce fichier contient la fonction main
qui est la fonction principale du programme

*/
int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
	{
		ft_init_game(&game);
		/*fonction qui lit le fichier*/
		read_file(argv[1], &game);
		/*fonction pour parser la config*/
		parse_config(&game);
		/*fonction qui extrait la map du fichier de config*/
		get_map_from_config(&game);
		/*fonction qui verifie que la map est OK*/
		check_map(&game);
	}
	else
		ft_error("You must have 2 arguments.");
	/*fonction de debug*/
	//display_struct_values(&game);
	init_window(&game);
	/*fonction qui free tous éléments malloc*/
	free_all(&game);
	return (0);
}
