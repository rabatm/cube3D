/*
	fichier parser.c
	ce fichier contient les fonctions qui gèrent le parsing des fichiers
	il gerer l'ouverture des fichier pub destinés 
	à être parsés pour générer le jeux.
*/

#include "../../includes/cub3d.h"

//fonction aui traite les texture ex NO SO WE EA
void parse_texture(char *line, t_ctext *color_texture)
{
	if (line[0] == 'N' && line[1] == 'O')
	{
		color_texture->texture_north = ft_strdup(line + 3);
	}
	else if (line[0] == 'S' && line[1] == 'O')
	{
		color_texture->texture_south = ft_strdup(line + 3);
	}
	else if (line[0] == 'W' && line[1] == 'E')
	{
		color_texture->texture_west = ft_strdup(line + 3);
	}
	else if (line[0] == 'E' && line[1] == 'A')
	{
		color_texture->texture_east = ft_strdup(line + 3);
	}
	else
	{
		ft_printf("Error\nInvalid line in file\n");
		exit(0);
	}
}
//fonction aui traite les couleurs ex F C
t_color parse_rgb_values(char *line)
{
	char 	**rgb_values;
	t_color color;

	rgb_values = ft_split(line, ',');
	color.r = ft_atoi(rgb_values[0]);
	color.g = ft_atoi(rgb_values[1]);
	color.b = ft_atoi(rgb_values[2]);
	ft_free_char_array(rgb_values, 3);
	return color;
}

void parse_color(char *line, t_ctext *color_texture)
{
	if (line[0] == 'F')
		color_texture->color_floor = parse_rgb_values(line + 2);
	else if (line[0] == 'C')
		color_texture->color_ceiling = parse_rgb_values(line + 2);
	else
	{
		ft_printf("Error\nInvalid line in file\n");
		exit(0);
	}
}

//fonction qui traite les lignes du fichier
// et les envoies aux fonctions de traitement
void parse_line(char *line, t_ctext *color_texture)
{
	if (line[0] == 'N' && line[1] == 'O')
		parse_texture(line, color_texture);
	else if (line[0] == 'S' && line[1] == 'O')
		parse_texture(line, color_texture);
	else if (line[0] == 'W' && line[1] == 'E')
		parse_texture(line, color_texture);
	else if (line[0] == 'E' && line[1] == 'A')
		parse_texture(line, color_texture);
	else if (line[0] == 'F')
		parse_color(line, color_texture);
	else if (line[0] == 'C')
		parse_color(line, color_texture);
	else
	{
		ft_printf("Error\nInvalid line in file\n");
		exit(0);
	}
}

//fonction qui recupere les informations depuis config de la structure
// pour le stocker au bon endroit dans la structure game 
void parse_file(t_game *game)
{
	int 	i;
	t_ctext	*color_texture;
	

	i = 0;
	while(i < 6)
	{
		parse_line(game->config[i], color_texture);
	}
}
