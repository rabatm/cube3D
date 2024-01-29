
/**
	Contient les structures de données Cub3D
*/

#ifndef STRUCTS_H
# define STRUCTS_H

/**
	Structure pour stocker les couleurs RGB
*/
typedef struct s_color {
	int r;
	int g;
	int b;
} t_color;

typedef struct s_point
{
	int	x;
	int	y;
}				t_point;

typedef struct s_ctext
{
	char		*texture_north;
	char		*texture_south;
	char		*texture_east;
	char		*texture_west;
	t_color		color_floor;
	t_color		color_ceiling;
} t_ctext;


typedef struct s_game
{
	int		flag;
	char	**tab;
	char	**config;
	int		nb_lines;
	int		max_line_len;
	char	**matrix;
	int			resolution_x;
	int			resolution_y;
	t_ctext	color_texture;
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


#endif