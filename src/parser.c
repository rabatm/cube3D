/*
	fichier parser.c
	ce fichier contient les fonctions qui gèrent le parsing des fichiers
	il gerer l'ouverture des fichier pub destinés 
	à être parsés pour générer le jeux.
*/

#include "include/cube3d.h"

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
		printf("Error\nInvalid line in file\n");
		exit(0);
	}
}
//fonction aui traite les couleurs ex F C
void parse_color(char *line, t_game *game)
{
	if (line[0] == 'F')
	{
		game->floor_color = ft_strdup(line + 2);
	}
	else if (line[0] == 'C')
	{
		game->ceiling_color = ft_strdup(line + 2);
	}
	else
	{
		printf("Error\nInvalid line in file\n");
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
		printf("Error\nInvalid line in file\n");
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
		printf("Error\nFile %s not found\n", file);
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
