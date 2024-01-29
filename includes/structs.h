
/**
	fichier cube3d.h
	Contient les structures de données Cube3D
*/

#ifndef STRUCTS_H
# define STRUCTS_H

/**
	Structure pour stocker les couleurs RGB
*/
typedef struct s_color {
	int r;
	int g;
	int b;
} t_color;

/**
	Structure pour stocker les données du jeu
*/

typedef struct s_game
{
	int			resolution_x;
	int			resolution_y;
	char		*texture_north;
	char		*texture_south;
	char		*texture_east;
	char		*texture_west;
	t_color		color_floor;
	t_color		color_ceiling;
	char 		**map;
} t_game;

#endif