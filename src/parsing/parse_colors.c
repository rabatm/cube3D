/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orauline <orauline@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 20:51:15 by orauline          #+#    #+#             */
/*   Updated: 2024/02/12 14:38:07 by orauline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
/*
fichier qui va contenir toutes les fonctions de parsing
pour la color
*/

//fonction quie retourne la couleur en int
// en fonction des valeurs rgb
// on décale les bits de 16 pour le rouge
// de 8 pour le vert
// et on ajoute le bleu
int	mlx_rgb_to_pixel(t_color color)
{
	return ((color.r << 16) | (color.g << 8) | color.b);
}

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
	free_array(rgb_values);
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
		color_texture->color_floor = mlx_rgb_to_pixel(color);
	else
		color_texture->color_ceiling = mlx_rgb_to_pixel(color);
	return (1);
}
