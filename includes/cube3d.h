/**
	fichier cube3d.h
	Contient les prototypes des fonctions de cube3d.c
	ainsi que la structure de données Cube3D
*/

#ifndef CUBE3D_H
# define CUBE3D_H

# include "structs.h"
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>


/*
FT UTILS
*/
void ft_free_char_array(char **my_array, int len);
void ft_error(char *str);

/*
FT pour la structure
*/
void	ft_init_game(t_game *game);

#endif