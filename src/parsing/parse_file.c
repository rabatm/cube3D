#include "../../includes/cub3d.h"

/*Fonction qui lit le fd*/
static char	*ft_read_fd(int fd, char *buffer, char *stash)
{
	int		nb_read;
	char	*tmp;

	nb_read = 1;
	while (nb_read != '0')
	{
		nb_read = read(fd, buffer, 1024);
		if (nb_read == -1)
			return (0);
		else if (nb_read == 0)
			break ;
		buffer[nb_read] = '\0';
		if (!stash)
			stash = ft_strdup("");
		tmp = stash;
		stash = ft_strjoin(tmp, buffer);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (stash);
}

/*Fonction qui vérifie si l'extension de fichier est valide*/
void	check_file_extension(char *str, char *ext)
{
	if (ft_strncmp(&str[ft_strlen(str) - 4], ext, 4))
		ft_error("Invalid file extension.");
}

/*Fonction qui lit le fichier en entier et le stocke dans **config*/
void	read_file(char *file_path, t_game *game)
{
	int		fd;
	char	*buffer;
	char	*stash;

	check_file_extension(file_path, ".cub");
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		ft_error("Incorrect file name or file path.");
	buffer = (char *)malloc(sizeof(char) * (1025));
	stash = NULL;
	stash = ft_read_fd(fd, buffer, stash);
	if (!stash)
	{
		free(buffer);
		free(stash);
		ft_error("File is empty.");
	}
	close(fd);
	free(buffer);
	game->config = ft_split(stash, '\n');
	free(stash);
}
