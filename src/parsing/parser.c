/*
	fichier parser.c
	ce fichier contient les fonctions qui gèrent le parsing des fichiers
	il gerer l'ouverture des fichier pub destinés
	à être parsés pour générer le jeux.
*/

#include "../../includes/cub3d.h"

// fonction qui vérifie que la couleur est bien comprise entre 0 et 255
// sans virgule, que c'est pas un caractère et que c'est pas un négatif
int	set_color_and_check(char *line)
{
	int	i;
	int	color;

	i = 0;
	while (line[i])
	{
		if (line[i] == ',')
			return (-1);
		if (line[i] < '0' || line[i] > '9')
			return (-1);
		i++;
	}
	color = ft_atoi(line);
	if (ft_atoi(line) < 0 || ft_atoi(line) > 255)
		return (-1);
	return (color);
}

// fonction aui traite les couleurs ex F C
t_color	parse_rgb_values(char *line)
{
	char	**rgb_values;
	t_color	color;

	rgb_values = ft_split(line, ',');
	if (ft_arraylen(rgb_values) != 3)
		color.r = -1;
	else
	{
		color.r = set_color_and_check(rgb_values[0]);
		color.g = set_color_and_check(rgb_values[1]);
		color.b = set_color_and_check(rgb_values[2]);
	}
	ft_free_char_array(rgb_values, 3);
	return (color);
}

int	parse_color(char *line, t_ctext *color_texture)
{
	t_color	color;

	if (!check_texture_color(line, color_texture))
		return (0);
	color = parse_rgb_values(line + 2);
	if (color.r == -1 || color.g == -1 || color.b == -1)
		return (0);
	if (line[0] == 'F')
		color_texture->color_floor = color;
	else
		color_texture->color_ceiling = color;
	return (1);
}

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
			free_all(game);
			ft_error("Invalid line in file\n");
		}
		i++;
	}
	if (game->color_texture.texture_north == NULL
		|| game->color_texture.texture_south == NULL
		|| game->color_texture.texture_east == NULL
		|| game->color_texture.texture_west == NULL
		|| game->color_texture.color_floor.r == -1
		|| game->color_texture.color_ceiling.r == -1)
	{
		free_all(game);
		ft_error("Information missing in confFile \n");
	}
}
