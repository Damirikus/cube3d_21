#include "cub3d.h"

int main(int argc, char **argv)
{
	t_data *data;
	if (argc != 2)
	{
		printf("Error: ./cub3D <filename>\n");
		return (0);
	}
	data = ft_init(argc, argv);

	int i;
	i = 0;
	while (data->map_array[i])
	{
		int k;
		k = 0;
		while (k < ft_strlen(data->map_array[i]))
		{
			printf("%d ", data->map_array_int[i][k]);
			k++;
		}
		printf("\n");
		i++;
	}


	ft_start_game(data);

	return 0;
}


void ft_draw_buffer_tmp(t_data *data)
{
	data->img_buffer.img = mlx_new_image(data->mlx, PIXEL_WIDTH, PIXEL_HEIGHT);
	data->img_buffer.addr = mlx_get_data_addr(data->img_buffer.img, &data->img_buffer.bits_per_pixel, &data->img_buffer.line_length, &data->img_buffer.endian);

	int x;
	int y;
	y = 0;
	while (y < PIXEL_HEIGHT)
	{
		x = 0;
		while (x < PIXEL_WIDTH)
		{
			my_mlx_pixel_put(&data->img_buffer, x, y, ft_rgb_handler(0, 255, 222));
			x++;
		}
		y++;
	}
}


void ft_start_game(t_data *data)
{
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, PIXEL_WIDTH, PIXEL_HEIGHT, "Cube 3D");
	ft_draw_map(data);
	ft_draw_buffer_tmp(data);

//	printf("posX = %f\nposY = %f\n", data->start_position_int.posX, data->start_position_int.posY);
//	printf("dirX = %f\ndirY = %f\n", data->start_position_int.dirX, data->start_position_int.dirY);
//	printf("planeX = %f\nplaneY = %f\n", data->start_position_int.planeX, data->start_position_int.planeY);
//	write(1, "\n", 1);
//	printf("width = %d\nheight = %d\n", data->size_map.width, data->size_map.height);

	// mlx_hook(data->mlx_win, 2, 1L << 0, ft_key_handler, main);
	mlx_hook(data->mlx_win, 17, 1L << 17, ft_mlx_close, data);
	mlx_loop_hook(data->mlx, ft_game, data);
	mlx_loop(data->mlx);
}






int ft_game(t_data *data)
{
	int x;
	x = 0;
	while (x < PIXEL_WIDTH)
	{
		double camera_x = 2 * x / (double)PIXEL_WIDTH - 1;
		double raydir_x = data->start_position_int.dir_x + data->start_position_int.plane_x * camera_x;
		double raydir_y = data->start_position_int.dir_y + data->start_position_int.plane_y * camera_x;

		int map_x = (int)data->start_position_int.pos_x;
		int map_y = (int)data->start_position_int.pos_y;

//		printf("%d\n", map_x);
//		printf("%d\n", map_y);
//		exit(0);

		double side_dist_x;
		double side_dist_y;

		double delta_dist_x = (raydir_x == 0) ? 1e30 : fabs(1 / raydir_x);
		double delta_dist_y = (raydir_y == 0) ? 1e30 : fabs(1 / raydir_y);

		double perp_wall_dist;

		int step_x;
		int step_y;

		int hit = 0;
		int side;

		if(raydir_x < 0)
		{
			step_x = -1;
			side_dist_x = (data->start_position_int.pos_x - map_x) * delta_dist_x;
		}
		else
		{
			step_x = 1;
			side_dist_x = (map_x + 1.0 - data->start_position_int.pos_x) * delta_dist_x;
		}
		if(raydir_y < 0)
		{
			step_y = -1;
			side_dist_y = (data->start_position_int.pos_y - map_y) * delta_dist_y;
		}
		else
		{
			step_y = 1;
			side_dist_y = (map_y + 1.0 - data->start_position_int.pos_y) * delta_dist_y;
		}

		while (hit == 0)
		{
			if (side_dist_x < side_dist_y)
			{
				side_dist_x += delta_dist_x;
				map_x += step_x;
				side = 0;
			}
			else
			{
				side_dist_y += delta_dist_y;
				map_y += step_y;
				side = 1;
			}
			//Check if ray has hit a wall
			if (data->map_array_int[map_x][map_y] > 0 && data->map_array_int[map_x][map_y] != 5)
			{
				hit = 1;
			}
		}



		x++;
	}

	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_buffer.img, 0, 0);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_map.img, ((PIXEL_WIDTH / 2) - ((data->size_map.width /2) * PIXEL_MAP)), (PIXEL_HEIGHT - (data->size_map.height * PIXEL_MAP)));

	return (0);
}




int ft_rgb_handler(int r, int g, int b)
{
	int rgb;

	rgb = r*65536+g*256+b;
	return (rgb);
}




int	ft_mlx_close(t_data *data)
{
	mlx_destroy_window(data->mlx,data->mlx_win);
	// ft_free_all(data);
	exit(0);
}


void my_mlx_pixel_put(t_img_addr *img, int x, int y, int color)
{
	// data->addr[(1000 * y) + x] = color;

	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}




