/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   barrhealt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martin <martin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 01:20:18 by mrabat            #+#    #+#             */
/*   Updated: 2024/02/11 17:03:11 by martin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_hb(t_game *game)
{
	game->hbar.img = mlx_xpm_file_to_image(game->mlx_ptr,
			"././assets/hbar.xpm", &game->hbar.img_width,
			&game->hbar.img_height);
}

void	init_head(t_game *game)
{
	int		i;
	char	path[30];
	char	*num;

	i = 0;
	while (i < 14)
	{
		ft_strlcpy(path, "././assets/w", 13);
		num = ft_itoa(i + 1);
		ft_strlcat(path, num, 30);
		ft_strlcat(path, ".xpm", 30);
		game->head[i].img = mlx_xpm_file_to_image(game->mlx_ptr, path,
				&game->head[i].img_width, &game->head[i].img_height);
		i++;
		free(num);
	}
}

void	my_heal_bar(t_game *game)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->hbar.img,
		0, WINDOW_HEIGHT - 83);
}

void	r_head(t_game *game)
{
	game->last_head += 1;
	if (game->last_head == 60)
	{
		game->current_head++;
		game->last_head = 0;
	}
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->head[game->current_head].img, (WINDOW_WIDTH - 120) / 2,
		WINDOW_HEIGHT - 76);
	if (game->current_head == 13)
		game->current_head = 0;
}
