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
# include <X11/X.h>
# include "../lib/libft/libft.h"
# include "../lib/minilibx/mlx.h"
# include "structs.h"

# define WINDOW_WIDTH 1024
# define WINDOW_HEIGHT 768
# define BUFFER_SIZE 1024
# define WALLS_MM_COLOR 0x8E8E8E
# define PL_MM_COLOR 0x27CE06
# define MM_ZOOM 0.01
# define SPEED 0.05
# define ROTATION_SPEED 0.04
# define TEXTURE_WIDTH 64
# define TEXTURE_HEIGHT 64
# define NB_TEXTURES 4

# define RED 0xFF0000

/*------------Liste des fonctions présentes dans le projet---------------*/
/*Fonctions de parsing*/
void	read_file(t_game *game, char *filename);
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
void	draw_sky_n_floor(t_game *game);
void	my_pix_put(t_game *game, int x, int y, int color);
void	draw_pixel(t_game *game, int i, int j, int color);
void	draw_minimap(t_game *game);
void	init_textures(t_game *game);
void	texture_init(t_game *game);

/* ft for barre*/
void	my_heal_bar(t_game *game);
void	r_head(t_game *game);


/*Fonctions de gestion du raycasting*/
void	dup_matrix_into_int_map(t_game *game);
void	init_player(t_game *game);
void	draw_ray(t_game *game);
void	raycaster(t_game *game);

/*Fonctions de gestion des mouvements*/
void	update_player_movement(t_game *game);
int		key_press(int keycode, t_game *game);
int		key_release(int keycode, t_game *game);
void	z_key(t_game *game);
void	s_key(t_game *game);
void	q_key(t_game *game);
void	d_key(t_game *game);
void	rotate_left_key(t_game *game);
void	rotate_right_key(t_game *game);

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
void	init_player_position(t_game *game);

#endif
