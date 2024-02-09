// #include "../../includes/cub3d.h"

// void	show_pic(t_game *game, char *pic, int x, int y)
// {
// 	int img_width, img_height;
// 	t_img image;

// 	image.addr = mlx_xpm_file_to_image(game->mlx_ptr, pic, &img_width, &img_height);
// 	if (!image.addr)
// 		write(2, "File could not be read\n", 23);
// 	else
// 		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, image.addr, x, y);
// }
// char* img_alea() {
//     // Initialisation du générateur pseudo-aléatoire avec l'heure actuelle
//     srand(time(NULL));

//     // Génère un nombre aléatoire entre 1 et 10
//     int numero_fichier = rand() % 10 + 1;

//     // Alloue de la mémoire pour le nom de fichier
//     char* nom_fichier = (char*)malloc(50 * sizeof(char)); // Assurez-vous d'allouer suffisamment d'espace

//     // Construit le nom de fichier
//     snprintf(nom_fichier, 50, "././assets/w%d.xpm", numero_fichier);

//     return nom_fichier;
// }

// void	r_head(t_game *game)
// {
// 	char *aleImg;
// 	aleImg = img_alea();
// 	show_pic(game, aleImg , 400, 400);
// 	free(aleImg);
// }


// void	my_heal_bar(t_game *game)
// {
// 	//show barr
// 	show_pic(game, "././assets/barre.xpm", 0, 401);
// }
