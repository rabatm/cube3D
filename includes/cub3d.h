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

typedef struct s_point
{
	int	x;
	int	y;
}				t_point;

typedef struct s_game
{
	int		flag;
	char	**tab;
	char	**config;
	int		nb_lines;
	int		max_line_len;
	char	**matrix;

	t_point	player;

	/*Variables dont on pourrait avoir besoin dans le projet*/

	// void    *mlx;
	// void    *win;
	// int     width;
	// int     height;
	// int     map_width;
	// int     map_height;
	// int     tile_size;
	// int     player_x;
	// int     player_y;
	// int     player_size;
	// int     player_turn_direction;
	// int     player_walk_direction;
	// int     player_side_direction;
	// int     player_rotation_angle;
	// int     walk_speed;
	// int     turn_speed;
}		t_game;


/*Structure dont on pourrait avoir besoin dans le projet*/
// typedef struct s_ray
// {
//     float   ray_angle;
//     float   wall_hit_x;
//     float   wall_hit_y;
//     float   distance;
//     int     was_hit_vertical;
//     int     is_ray_facing_up;
//     int     is_ray_facing_down;
//     int     is_ray_facing_left;
//     int     is_ray_facing_right;
//     int     wall_hit_content;
// }               t_ray;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;


/*------------Liste des fonctions présentes dans le projet---------------*/
/*Fonctions de parsing*/
void	read_file(char *file_path, t_game *game);
void	get_max_line_len(t_game *game);
void	get_nb_lines(t_game *game);
void	get_map_rectangular(t_game *game);
void	get_map_from_config(t_game *game);

/*Fonctions de gestion des éléments graphiques*/
// int		create_window(t_game *game);
// int		handle_keypress(int keysym, t_game *game);
// int		close_everything(t_game *game);

/*Fonctions de gestion du raycasting*/


/*Fonctions de gestion de la mémoire*/
// void    malloc_n_duplicate(t_game *game);
void	free_errors(t_game *game);
void	free_errors2(t_game *game, char *str);
void	free_all(t_game *game);


/*Fonctions de gestion des erreurs*/
void	ft_error(char *str);
void	display_struct_values(t_game *game);
void	check_map(t_game *game);
int		check_walls(t_game *game);

#endif
