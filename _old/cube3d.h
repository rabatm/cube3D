/**
	fichier cube3d.h
	Contient les prototypes des fonctions de cube3d.c
	ainsi que la structure de données Cube3D
*/

#ifndef CUBE3D_H
#define CUBE3D_H

#include <fcntl.h>

/*Libmlx Libraries*/
#include "../lib/minilibx/mlx.h"
// #include <X11/keysim.h>
#include <X11/X.h>
#include <stdlib.h>


/**
	Structure de données Cube3D
*/
typedef struct s_game
{
	int		resolution_x;
	int		resolution_y;
	char	*texture_north;
	char	*texture_south;
	char	*texture_east;
	char	*texture_west;
	int		floor_color;
	int		ceiling_color;
	char 	**map;
}			t_game;

/*Fonctions de gestion de l'affichage*/
int		init_window(t_game *game);

/*Fonctions de parsing*/
void	parse_resolution(char *line, t_game *game);
void	parse_texture(char *line, t_game *game);
void	parse_color(char *line, t_game *game);
void	parse_map(char *line, t_game *game);
void	parse_line(char *line, t_game *game);
void	parse_file(char *file, t_game *game);
void	check_file_extension(char *str);

/*Fonctions de raycasting*/

/*Fonctions utilitaires*/
void	ft_error(char *str);


#endif