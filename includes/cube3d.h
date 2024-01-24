/**
	fichier cube3d.h
	Contient les prototypes des fonctions de cube3d.c
	ainsi que la structure de données Cube3D
*/

#ifndef CUBE3D_H
#define CUBE3D_H

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>

#include "constantes.h"


/**
	Structure de données Cube3D
*/
typedef struc s_game
{
	int		resolution_x;
	int		resolution_y;
	char	*texture_north;
	char	*texture_south;
	char	*texture_east;
	char	*texture_west;
	int		color_floor;
	int		color_ceiling;
	char 	**map;
}