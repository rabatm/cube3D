/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orauline <orauline@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 20:53:37 by orauline          #+#    #+#             */
/*   Updated: 2024/02/10 20:54:02 by orauline         ###   ########.fr       */
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
			free_ct_conf_error(game, "Invalid line in configuration file.\n");
		if (ret == -2)
			break ;
	}
	if (game->color_texture.texture_north == NULL
		|| game->color_texture.texture_south == NULL
		|| game->color_texture.texture_east == NULL
		|| game->color_texture.texture_west == NULL
		|| game->color_texture.color_floor == -1
		|| game->color_texture.color_ceiling == -1)
		free_ct_conf_error(game, "Information missing in conf file.\n");
}
