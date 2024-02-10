#include "../../includes/cub3d.h"

void	draw_line(t_game *game, int x, int draw_start, int draw_end, int color)
{
	while (draw_start <= draw_end)
	{
		my_pix_put(game, x, draw_start, color);
		draw_start++;
	}
}

void	raycaster(t_game *game)
{
	int	x;

	x = -1;
	while (++x < WINDOW_WIDTH)
	{
		//calculate ray position and direction
		game->camera_x = 2 * x / (double)WINDOW_WIDTH - 1; //x-coordinate in camera space
		game->ray_dir_x = game->player.dir_x + game->plane_x * game->camera_x;
		game->ray_dir_y = game->player.dir_y + game->plane_y * game->camera_x;
		int mapX = (int)(game->player.pos_x);
 		int mapY = (int)(game->player.pos_y);
		//length of ray from current position to next x or y-side
		double sideDistX;
		double sideDistY;
		double deltaDistX = fabs(1 / game->ray_dir_x);
		double deltaDistY = fabs(1 / game->ray_dir_y);
		double perpWallDist;
		//what direction to step in x or y-direction (either +1 or -1)
		int stepX;
		int stepY;

		int hit = 0; //was there a wall hit?
		int side; //was a NS or a EW wall hit?

		//calculate step and initial sideDist
		if(game->ray_dir_x < 0)
		{
			stepX = -1;
			sideDistX = (game->player.pos_x - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - game->player.pos_x) * deltaDistX;
		}
		if(game->ray_dir_y < 0)
		{
			stepY = -1;
			sideDistY = (game->player.pos_y - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - game->player.pos_y) * deltaDistY;
		}
		//perform DDA
		while(hit == 0)
		{
			//jump to next map square, either in x-direction, or in y-direction
			if(sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			//Check if ray has hit a wall
			if(game->int_map[mapX][mapY] > 0)
				hit = 1;
		}
		//Calculate distance projected on camera direction. This is the shortest distance from the point where the wall is
		//hit to the camera plane. Euclidean to center camera point would give fisheye effect!
		//This can be computed as (mapX - posX + (1 - stepX) / 2) / rayDirX for side == 0, or same formula with Y
		//for size == 1, but can be simplified to the code below thanks to how sideDist and deltaDist are computed:
		//because they were left scaled to |rayDir|. sideDist is the entire length of the ray above after the multiple
		//steps, but we subtract deltaDist once because one step more into the wall was taken above.
		if(side == 0)
			perpWallDist = (sideDistX - deltaDistX);
		else
			perpWallDist = (sideDistY - deltaDistY);

		//Calculate height of line to draw on screen
		int lineHeight = (int)(WINDOW_HEIGHT / perpWallDist);

		int pitch = 0;
		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + WINDOW_HEIGHT / 2 + pitch;
		if(drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + WINDOW_HEIGHT / 2 + pitch;
		if(drawEnd >= WINDOW_HEIGHT)
			drawEnd = WINDOW_HEIGHT - 1;

		//choose wall color
		// ColorRGB color;
		// switch(worldMap[mapX][mapY])
		// {
		// 	case 1:  color = RGB_Red;    break; //red
		// 	case 2:  color = RGB_Green;  break; //green
		// 	case 3:  color = RGB_Blue;   break; //blue
		// 	case 4:  color = RGB_White;  break; //white
		// 	default: color = RGB_Yellow; break; //yellow
		// }

		//give x and y sides different brightness
		// if(side == 1) {color = color / 2;}

		//draw the pixels of the stripe as a vertical line
		draw_line(game, x, drawStart, drawEnd, 0xC0C0C0);
	}
}
