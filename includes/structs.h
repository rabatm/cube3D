
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
	int		x;
	int		y;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
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
	int		**int_map;
	int		nb_lines;
	int		max_line_len;
	int		nb_cols;
	int		nb_rows;
	char	**matrix;
	int		resolution_x;
	int		resolution_y;
	void	*mlx_ptr;
	void	*win_ptr;
	char	init_dir;
	double	plane_x;
	double	plane_y;
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		mov_x;
	int		mov_y;
	int		rotate_x;
	int		rotate_y;
	int		left_straf;
	int		right_straf;
	float	speed;
	float	rot;
	int		**textures;

    void	*buffer; //emplacement en memoire sur lequel on construit l image qu on va afficher
    char	*addr;
    int		bpp; /* bits per pixel */
    int		line_len;
    int		endian;

	t_ctext	color_texture;
	t_point	player;
}		t_game;

typedef struct s_img
{
	void	*img; 
	int		*data;

	int		size_line;
	int		bpp;
	int		endian;
	int		img_width;
	int		img_height;
}			t_img;


#endif