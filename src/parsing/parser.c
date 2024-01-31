/*
	fichier parser.c
	ce fichier contient les fonctions qui gèrent le parsing des fichiers
	il gerer l'ouverture des fichier pub destinés
	à être parsés pour générer le jeux.
*/

#include "../../includes/cub3d.h"

// fonction qui traite les lignes du fichier
// et les envoies aux fonctions de traitement
int	parse_line(char *line, t_ctext *color_texture)
{
	if (line[0] == 'N' && line[1] == 'O')
		return (parse_texture(line, color_texture));
	else if (line[0] == 'S' && line[1] == 'O')
		return (parse_texture(line, color_texture));
	else if (line[0] == 'W' && line[1] == 'E')
		return (parse_texture(line, color_texture));
	else if (line[0] == 'E' && line[1] == 'A')
		return (parse_texture(line, color_texture));
	else if (line[0] == 'F')
		return (parse_color(line, color_texture));
	else if (line[0] == 'C')
		return (parse_color(line, color_texture));
	return (0);
}

// fonction qui recupere les informations depuis config de la structure
// pour le stocker au bon endroit dans la structure game
void	parse_config(t_game *game)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (parse_line(game->config[i], &(game->color_texture)) == 0)
		{
			fprintf(stderr, "Error %s\n", game->config[i]);
			free_ct_conf(game);
			ft_error("Invalid line in file\n");
		}
		i++;
	}
	if (game->color_texture.texture_north == NULL
		|| game->color_texture.texture_south == NULL
		|| game->color_texture.texture_east == NULL
		|| game->color_texture.texture_west == NULL
		|| game->color_texture.color_floor == -1
		|| game->color_texture.color_ceiling == -1)
	{
		free_ct_conf(game);
		ft_error("Information missing in confFile \n");
	}
}
