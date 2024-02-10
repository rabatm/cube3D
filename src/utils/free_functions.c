/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orauline <orauline@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 20:48:42 by orauline          #+#    #+#             */
/*   Updated: 2024/02/10 20:48:44 by orauline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	free_ct_conf(t_game *game)
{
	free(game->color_texture.texture_north);
	free(game->color_texture.texture_south);
	free(game->color_texture.texture_west);
	free(game->color_texture.texture_east);
}

/*Fonction qui free les tableaux précédemment malloc en cas d'erreur*/
void	free_errors(t_game *game)
{
	int	i;

	i = -1;
	while (game->tab[++i])
		free(game->tab[i]);
	free(game->tab);
	i = -1;
	while (game->config[++i])
		free(game->config[i]);
	free(game->config);
	i = -1;
	while (game->matrix[++i])
		free(game->matrix[i]);
	free(game->matrix);
}

/*Fonction qui free les tableaux + indique le message d'erreur correspondant*/
void	free_errors2(t_game *game, char *str)
{
	free_errors(game);
	ft_error(str);
}

/*Fonction qui free tout en fin de programme*/
void	free_all(t_game *game)
{
	int	i;

	free_ct_conf(game);
	i = -1;
	while (game->tab[++i])
		free(game->tab[i]);
	free(game->tab);
	i = -1;
	while (game->config[++i])
		free(game->config[i]);
	free(game->config);
	i = -1;
	while (game->matrix[++i])
		free(game->matrix[i]);
	free(game->matrix);
	i = -1;
	while (++i < game->nb_cols)
		free(game->int_map[i]);
	free(game->int_map);
	i = -1;
	while (++i < NB_TEXTURES)
		free(game->textures[i]);
	free(game->textures);
}

void	free_ct_conf_error(t_game *game, char *msg)
{
	free_ct_conf(game);
	ft_error(msg);
}
