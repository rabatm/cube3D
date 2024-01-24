
#include "include/cube3d.h"
/**
fichier main du projet cub3d
ce fichier contient la fonction main
qui est la fonction principale du programme

*/
int main(int argc, char **argv)
{
	t_game game;
	//on initialise la structure game
	init_game(&game);
	//on parse le fichier .cub
	parse_file(argv[1], &game);
	/*
	init_window(&game);
	//on initialise les textures
	init_textures(&game);
	//on initialise les sprites
	init_sprites(&game);
	//on lance le jeu
	game_loop(&game);
	//on libere la memoire*/
	free_memory(&game);
	return (0);
}