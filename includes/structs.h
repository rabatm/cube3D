
/**
	Contient les structures de données Cub3D
*/

#ifndef STRUCTS_H
# define STRUCTS_H

/**
	Structure pour stocker les couleurs RGB
*/
typedef struct s_color
{
	int		r;
	int		g;
	int		b;
}			t_color;

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
	int			color_floor;
	int			color_ceiling;
}		t_ctext;


typedef struct s_game
{
	int		flag;
	char	**tab;
	char	**config;
	int		nb_lines;
	int		max_line_len;
	char	**matrix;
	int		resolution_x;
	int		resolution_y;
	void	*mlx_ptr;
	void	*win_ptr;
	// int		window_width;
	// int		window_height;
	t_ctext	color_texture;
	t_point	player;
	t_point	direction;
	t_point	plane;

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
