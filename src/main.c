/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabat <mrabat@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 21:00:59 by orauline          #+#    #+#             */
/*   Updated: 2024/02/11 02:11:33 by mrabat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
fichier main du projet cub3d
ce fichier contient la fonction main
qui est la fonction principale du programme

*/
int	main(int argc, char **argv)
{
	t_game	game;

	if (argc == 2)
	{
		ft_init_game(&game);
		read_file(&game, argv[1]);
		parse_config(&game);
		get_map_from_config(&game);
		check_map(&game);
	}
	else
		ft_error("You must have 2 arguments. Run ./cub3d with a conf file.");
	init_player(&game);
	homePageMain();
	//init_window(&game);
	free_all(&game);
	return (0);
}
