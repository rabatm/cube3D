/*
	fichier parser.c
	ce fichier contient les fonctions qui gèrent le parsing des fichiers
	il gerer l'ouverture des fichier pub destinés 
	à être parsés pour générer le jeux.
*/

#include "../includes/cube3d.h"

//fonction aui traite la resolution 
void parse_resolution(char *line, t_game *game)
{
//code
}

//fonction aui traite les texture ex NO SO WE EA
void parse_texture(char *line, t_game *game)
{
	if (line[0] == 'N' && line[1] == 'O')
	{
		game->texture_north = ft_strdup(line + 3);
	}
	else if (line[0] == 'S' && line[1] == 'O')
	{
		game->texture_south = ft_strdup(line + 3);
	}
	else if (line[0] == 'W' && line[1] == 'E')
	{
		game->texture_west = ft_strdup(line + 3);
	}
	else if (line[0] == 'E' && line[1] == 'A')
	{
		game->texture_east = ft_strdup(line + 3);
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

void parse_color(char *line, t_game *game)
{
	if (line[0] == 'F')
		game->color_floor = parse_rgb_values(line + 2);
	else if (line[0] == 'C')
		game->color_ceiling = parse_rgb_values(line + 2);
	else
	{
		ft_printf("Error\nInvalid line in file\n");
		exit(0);
	}
}

//fonction qui traite la carte du labyrinthe
void parse_map(char *line, t_game *game)
{
	if(game->map == NULL)
	{
		game->map = ft_strdup(line);
	}
	else
	{
		game->map = ft_strjoin(game->map, line);
	}
}

//fonction qui traite les lignes du fichier
// et les envoies aux fonctions de traitement
void parse_line(char *line, t_game *game)
{
	if (line[0] == 'N' && line[1] == 'O')
		parse_texture(line, game);
	else if (line[0] == 'S' && line[1] == 'O')
		parse_texture(line, game);
	else if (line[0] == 'W' && line[1] == 'E')
		parse_texture(line, game);
	else if (line[0] == 'E' && line[1] == 'A')
		parse_texture(line, game);
	else if (line[0] == 'F')
		parse_color(line, game);
	else if (line[0] == 'C')
		parse_color(line, game);
	else if (line[0] == ' ' || line[0] == '1')
		parse_map(line, game);
	else
	{
		ft_printf("Error\nInvalid line in file\n");
		exit(0);
	}
}

//fonction qui ouvre le fichier et le lit ligne par ligne
void parse_file(char *file, t_game *game)
{
	int	fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\nFile %s not found\n", file);
		exit(0);
	}
	while (get_next_line(fd, &line))
	{
		parse_line(line, game);
		free(line);
	}
	free(line);
	close(fd);
}
