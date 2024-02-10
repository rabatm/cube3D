/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orauline <orauline@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 20:47:11 by orauline          #+#    #+#             */
/*   Updated: 2024/02/10 20:47:13 by orauline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
fichier qui va contenir les fonctions destinée a gérer les tableau.
*/

#include "../../includes/cub3d.h"

void	ft_free_char_array(char **my_array)
{
	int	i;

	i = 0;
	if (my_array[0] != NULL)
	{
		while (my_array[i])
		{
			free(my_array[i]);
			i++;
		}
		free(my_array);
	}
}
