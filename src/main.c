#include "../includes/cub3d.h"

int main(int argc, char **argv)
{
	t_game game;
    game.flag = 0;
	if (argc == 2)
	{
		/*fonction qui lit le fichier*/
		read_file(argv[1], &game);
		/*fonction qui extrait la map du fichier de config*/
		get_map_from_config(&game);
		/*fonction qui verifie que la map est OK*/
		check_map(&game);
	}
	else
		ft_error("You must have 2 arguments.");
	/*fonction de debug*/
	display_struct_values(&game);
	// create_window(&game);
	free_all(&game);
	return (0);
}
