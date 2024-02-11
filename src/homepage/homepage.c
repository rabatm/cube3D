#include "../../includes/cub3d.h"

// Fonction pour gérer les événements clavier
int handle_key_press(int keycode, void *param)
{
	t_game *game = (t_game *)param;
	
	printf("Touche pressée : %d\n", keycode);
	if (keycode == XK_Escape)
		close_everything(game);
	//else 
		//init_window(game);
	return 0;
}

int homePageMain(t_game *game)
{
    void *mlx_ptr;
    void *win_ptr;
    void *img_ptr;
	int img_width;
	int img_height;

    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 800, 800, "Cub3D");
    img_ptr = mlx_xpm_file_to_image(mlx_ptr, "././assets/hpage.xpm", &img_width, &img_height);
    mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0);
    mlx_key_hook(win_ptr, handle_key_press, game);
    mlx_loop(mlx_ptr);

    return 0;
}
