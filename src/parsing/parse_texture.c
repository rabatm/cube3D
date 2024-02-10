/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orauline <orauline@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 20:53:16 by orauline          #+#    #+#             */
/*   Updated: 2024/02/10 20:53:17 by orauline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/*regroupe les fonctions pour le parsing de la texture*/
// fonction qui verifie que le fichier existe et est bien un .xpm
static int	check_file_extension_and_existence(char *filename)
{
	int		fd;
	char	*file_extension;
	char	buf;
	int		n;

	file_extension = strrchr(filename, '.');
	if (file_extension == NULL || strcmp(file_extension, ".xpm") != 0)
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	n = read(fd, &buf, 1);
	close(fd);
	if (n == 0)
		return (0);
	return (1);
}

// fonction qui verifie que les texture sont remplis dans la structure
// si elle sont remplis on renvoie 0
// sinon on renvoie 1
int	check_texture_color(char *line, t_ctext *color_texture)
{
	if ((line[0] == 'N' && line[1] == 'O')
		&& (color_texture->texture_north != NULL))
		return (0);
	else if ((line[0] == 'S' && line[1] == 'O')
		&& (color_texture->texture_south != NULL))
		return (0);
	else if ((line[0] == 'W' && line[1] == 'E')
		&& (color_texture->texture_west != NULL))
		return (0);
	else if ((line[0] == 'E' && line[1] == 'A')
		&& (color_texture->texture_east != NULL))
		return (0);
	else if ((line[0] == 'F') && (color_texture->color_floor != -1))
		return (0);
	else if ((line[0] == 'C') && (color_texture->color_ceiling != -1))
		return (0);
	return (1);
}

// fonction aui traite les texture ex NO SO WE EA
// on verifie que la texture n'est pas deja remplie
// on verifie ensuite que le fichier existe et et bien un .xpm
// si elle ne l'est pas on la remplie en supprimant les espaces
int	parse_texture(char *line, t_ctext *color_texture)
{
	char	*tmp;
	char	*str_for_trim;

	str_for_trim = " ";
	if (check_texture_color(line, color_texture) == 0)
		return (0);
	tmp = ft_strtrim(line + 3, str_for_trim);
	if (check_file_extension_and_existence(tmp) == 0)
		return (0);
	if (line[0] == 'N' && line[1] == 'O')
		color_texture->texture_north = ft_strdup(tmp);
	else if (line[0] == 'S' && line[1] == 'O')
		color_texture->texture_south = ft_strdup(tmp);
	else if (line[0] == 'W' && line[1] == 'E')
		color_texture->texture_west = ft_strdup(tmp);
	else if (line[0] == 'E' && line[1] == 'A')
		color_texture->texture_east = ft_strdup(tmp);
	free(tmp);
	return (1);
}
