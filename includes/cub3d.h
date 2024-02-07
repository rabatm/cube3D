#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <X11/Xlib.h>
# include <X11/Xutil.h>
# include <X11/Xos.h>
# include <X11/keysym.h>
# include "../lib/libft/libft.h"
# include "../lib/minilibx/mlx.h"
# include "../lib/libft/libft.h"
# include "structs.h"

# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 300

/*------------Liste des fonctions présentes dans le projet---------------*/
/*Fonctions de parsing*/
void	read_file(char *file_path, t_game *game);
void	get_max_line_len(t_game *game);
void	get_nb_lines(t_game *game);
void	get_map_rectangular(t_game *game);
void	get_map_from_config(t_game *game);
//function pour le parsing des textures
int		parse_texture(char *line, t_ctext *color_texture);
void	parse_config(t_game *game);
int		check_texture_color(char *line, t_ctext *color_texture);
int		parse_color(char *line, t_ctext *color_texture);

/*Fonctions de gestion des éléments graphiques*/
int		init_window(t_game *game);
int		handle_escape(int keysym, t_game *game);
int		close_everything(t_game *game);
void	draw_minimap(t_game *game);
void	draw_sky_n_floor(t_game *game, t_ctext *color_texture);

/*Fonctions de gestion du raycasting*/


/*Fonctions de gestion de la mémoire*/
// void    malloc_n_duplicate(t_game *game);
void	free_ct_conf_error(t_game *game, char *msg);
void	free_errors(t_game *game);
void	free_errors2(t_game *game, char *str);
void	free_all(t_game *game);
void	free_ct_conf(t_game *game);


/*Fonctions de gestion des erreurs*/
void	ft_error(char *str);
void	display_struct_values(t_game *game);
void	check_map(t_game *game);
int		check_walls(t_game *game);

/*
FT UTILS
*/
void	ft_free_char_array(char **my_array);
void	check_file_extension(char *str, char *ext);
/*
FT pour la structure
*/
void	ft_init_game(t_game *game);

#endif
