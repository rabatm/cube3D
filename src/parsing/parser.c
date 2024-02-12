/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabat <mrabat@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 20:53:37 by orauline          #+#    #+#             */
/*   Updated: 2024/02/12 18:40:46 by mrabat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	char	*tmp;

	if (!line)
		return (-2);
	tmp = remove_spaces(line);
	fprintf(stderr, "parse |%s|\n", tmp);
	if (tmp[0] == 'N' && tmp[1] == 'O')
		return (parse_texture(tmp, color_texture));
	else if (tmp[0] == 'S' && tmp[1] == 'O')
		return (parse_texture(tmp, color_texture));
	else if (tmp[0] == 'W' && tmp[1] == 'E')
		return (parse_texture(tmp, color_texture));
	else if (tmp[0] == 'E' && tmp[1] == 'A')
		return (parse_texture(tmp, color_texture));
	else if (tmp[0] == 'F')
		return (parse_color(tmp, color_texture));
	else if (tmp[0] == 'C')
		return (parse_color(tmp, color_texture));
	free(tmp);
	return (-2);
}

// fonction qui recupere les informations depuis config de la structure
// pour le stocker au bon endroit dans la structure game
void	parse_config(t_game *game)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (1)
	{
		ret = parse_line(game->config[i++], &(game->color_texture));
		if (ret == 0)
			free_ct_conf_error(game, "Invalid color or texture in conf file.");
		if (ret == -2)
			break ;
	}
	fprintf(stderr, "parse_config %s\n", game->color_texture.texture_north);
	if (game->color_texture.texture_north == NULL
		|| game->color_texture.texture_south == NULL
		|| game->color_texture.texture_east == NULL
		|| game->color_texture.texture_west == NULL
		|| game->color_texture.color_floor == -1
		|| game->color_texture.color_ceiling == -1)
		free_ct_conf_error(game, "Information missing in conf file.\n");
}
