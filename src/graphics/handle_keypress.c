#include "../../includes/cub3d.h"

int	handle_escape(int keysym, t_game *game)
{
	if (keysym == XK_Escape)
		close_everything(game);
	return (0);
}
