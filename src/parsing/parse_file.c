/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orauline <orauline@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 20:51:43 by orauline          #+#    #+#             */
/*   Updated: 2024/02/14 10:54:50 by orauline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/*Fonction qui vérifie si l'extension de fichier est valide*/
void	check_file_extension(char *str, char *ext)
{
	if (ft_strncmp(&str[ft_strlen(str) - 4], ext, 4))
		ft_error("Invalid configuration file extension.");
}

static char	*ft_open_x_2(char *str, int fd)
{
	if (close(fd) == -1)
		return (NULL);
	return (str);
}

static char	*ft_readfile(char *filename)
{
	int		fd;
	int		ret;
	int		len_total;
	char	buf[BUFFER_SIZE];
	char	*str;

	len_total = 0;
	ret = BUFFER_SIZE;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	while (ret)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		len_total += ret;
	}
	if (close(fd) == -1)
		return (NULL);
	str = malloc(sizeof(char) * len_total + 1);
	if (!str)
		return (NULL);
	fd = open(filename, O_RDONLY);
	ret = read(fd, str, len_total);
	str[len_total] = '\0';
	return (ft_open_x_2(str, fd));
}

static void	check_if_file_exist(char *str)
{
	if (str == NULL)
	{
		ft_error("File doesn't exist. Choose another one.");
		exit(EXIT_FAILURE);
	}
	if (str[0] == 0)
	{
		free(str);
		ft_error("Configuration file is empty !");
		exit(0);
	}
}

void	read_file(t_game *game, char *filename)
{
	int		i;
	char	*str;

	i = 0;
	check_file_extension(filename, ".cub");
	str = ft_readfile(filename);
	check_if_file_exist(str);
	game->config = ft_split(str, '\n');
	free(str);
	if (!game->config)
		exit(EXIT_FAILURE);
	while (game->config[i])
		i++;
	if (i <= 6)
	{
		free_array(game->config);
		ft_error("Invalid configuration file.");
		exit(0);
	}
	game->max_line_len = i;
}
