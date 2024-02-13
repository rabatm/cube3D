/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_walls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orauline <orauline@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 20:55:16 by orauline          #+#    #+#             */
/*   Updated: 2024/02/13 12:22:28 by orauline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// static int	check_chars(t_game *game)
// {
// 	if (game->matrix[i][j] == '0' || game->matrix[i][j] == ' ' || game->matrix[i][j] == 'N' ||)
// 	return (0);
// }

/*Fonction qui vérifie qu'il y a que des 1 sur les contours de la map*/
static int	check_outline(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->matrix[++i])
	{
		j = -1;
		while (game->matrix[i][++j])
		{
			if (i == 0 || i == game->nb_lines - 1)
			{
				if (game->matrix[i][j] != '1' && game->matrix[i][j] != ' ')
					free_errors2(game, "There isnt wall on 1st or last line.");
			}
			else
			{
				if (j == 0 || j == game->max_line_len - 1)
				{
					if (game->matrix[i][j] != '1' && game->matrix[i][j] != ' ')
						free_errors2(game, "No wall on 1st or last col.");
				}
			}
		}
	}
	return (0);
}

/*Fonction qui vérifie qu'il n'y a pas d'espaces autour des '0'
// sinon la map n'est pas entourée de murs*/
static int	check_spaces(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->matrix[++i])
	{
		j = 0;
		while (game->matrix[i][j])
		{
			if (game->matrix[i][j] == '0')
			{
				if (game->matrix[i][j - 1] == ' ' \
					|| game->matrix[i][j + 1] == ' ' \
					|| game->matrix[i - 1][j] == ' ' \
					|| game->matrix[i + 1][j] == ' ')
					free_errors2(game, "Map is not surrounded by walls.");
			}
			j++;
		}
	}
	return (0);
}

/*Fonction qui verifie que la map est entourée de murs*/
int	check_walls(t_game *game)
{
	check_outline(game);
	check_spaces(game);
	return (0);
}
