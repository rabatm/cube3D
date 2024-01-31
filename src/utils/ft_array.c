/*
fichier qui va contenir les fonctions destinée a gérer les tableau.
*/

#include "../../includes/cub3d.h"

void	ft_free_char_array(char **my_array)
{
	int	i;

	i = 0;
	while (my_array[i])
	{
		free(my_array[i]);
		i++;
	}
	free(my_array);
}
