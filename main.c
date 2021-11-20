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

unsigned int ft_get_color(t_img_addr *temp, int i, int j)
{
	char *str;
	unsigned int c;

	str = temp->addr + (j * temp->line_length + i * (temp->bits_per_pixel / 8));
	c = *(unsigned int *)str;
	return (c);
}

int get_all_colors_texture(t_data *data, int ***colors, char *path)
{
	t_img_addr temp;
	int i;
	int j;
	i = 0;
	j = 0;

	temp.img = mlx_xpm_file_to_image(data->mlx, path, &j, &i);
	temp.addr = mlx_get_data_addr(temp.img, &temp.bits_per_pixel, &temp.line_length, &temp.endian);

	(*colors) = malloc(sizeof(int *) * TEX_HEIGHT);
	i = 0;
	while (i < TEX_HEIGHT)
	{
		(*colors)[i] = malloc(sizeof(int) * TEX_WIDTH);
		j = 0;
		while (j < TEX_WIDTH)
		{
			(*colors)[i][j] = ft_get_color(&temp, i, j);
			j++;
		}
		i++;
	}
	mlx_destroy_image(data->mlx, temp.img);
	return 0;
}

void ft_start_game(t_data *data)
{
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, PIXEL_WIDTH, PIXEL_HEIGHT, "Cube 3D");
	ft_draw_map(data);


	get_all_colors_texture(data, &data->arrays_for_color->color_north, data->north_texture.path);
	get_all_colors_texture(data, &data->arrays_for_color->color_south, data->south_texture.path);


	mlx_hook(data->mlx_win, 2, 1L << 0, ft_key_handler, data);
	mlx_hook(data->mlx_win, 17, 1L << 17, ft_mlx_close, data);
	mlx_loop_hook(data->mlx, ft_game, data);
	mlx_loop(data->mlx);
}


int ft_game(t_data *data)
{
	data->img_buffer.img = mlx_new_image(data->mlx, PIXEL_WIDTH, PIXEL_HEIGHT);
	data->img_buffer.addr = mlx_get_data_addr(data->img_buffer.img, &data->img_buffer.bits_per_pixel, &data->img_buffer.line_length, &data->img_buffer.endian);

	int x;
	x = 0;
	while (x < PIXEL_WIDTH)
	{
		double camera_x = 2 * x / (double)PIXEL_WIDTH - 1;
		double raydir_x = data->start_position_int.dir_x + data->start_position_int.plane_x * camera_x;
		double raydir_y = data->start_position_int.dir_y + data->start_position_int.plane_y * camera_x;

		int map_x = (int)data->start_position_int.pos_x;
		int map_y = (int)data->start_position_int.pos_y;

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

		while (hit == 0) {
			if (side_dist_x < side_dist_y) {
				side_dist_x += delta_dist_x;
				map_x += step_x;
				side = 0;
			} else {
				side_dist_y += delta_dist_y;
				map_y += step_y;
				side = 1;
			}
			//Check if ray has hit a wall
			if (data->map_array_int[map_x][map_y] > 0 && data->map_array_int[map_x][map_y] != 5) {
				hit = 1;
			}
		}
		if (side == 0)
			perp_wall_dist = (side_dist_x - delta_dist_x);
//			perp_wall_dist = (map_x - data->start_position_int.pos_x + (1 - step_x) / 2) / data->start_position_int.dir_x;
		else
			perp_wall_dist = (side_dist_y - delta_dist_y);
//			perp_wall_dist = (map_y - data->start_position_int.pos_y + (1 - step_y) / 2) / data->start_position_int.dir_y;
		int line_height = (int) (PIXEL_HEIGHT / perp_wall_dist);

		int draw_start = -line_height / 2 + PIXEL_HEIGHT / 2;
		if (draw_start < 0)
			draw_start = 0;
		int draw_end = line_height / 2 + PIXEL_HEIGHT / 2;
		if (draw_end >= PIXEL_HEIGHT)
			draw_end = PIXEL_HEIGHT - 1;


//		int tex_num = data->map_array_int[map_x][map_y] - 1;
		double wall_x;
		if (side == 0)
			wall_x = data->start_position_int.pos_y + perp_wall_dist * raydir_y;
		else
			wall_x = data->start_position_int.pos_x + perp_wall_dist * raydir_x;
		wall_x -= floor(wall_x);

		int tex_x = (int)(wall_x * (double)(TEX_WIDTH));
		if (side == 0 && raydir_x > 0)
			tex_x = TEX_WIDTH - tex_x - 1;
		if (side == 1 && raydir_y < 0)
			tex_x = TEX_WIDTH - tex_x - 1;

		double step = 1.0  * TEX_HEIGHT / line_height;

		double tex_pos = (draw_start - PIXEL_HEIGHT/2 + line_height/2) * step;


		int y;
		y = draw_start;
		while (y < draw_end)
		{
			int tex_y = (int)(tex_pos) & (TEX_HEIGHT - 1);
			tex_pos += step;
			int color;
			if (side == 0)
			{
				if (step_x > 0)
					color = data->arrays_for_color->color_north[tex_x][tex_y];
				else
					color = data->arrays_for_color->color_south[tex_x][tex_y];
			}
			else
			{
				if (step_y < 0)
					color = data->arrays_for_color->color_north[tex_x][tex_y];
				else
					color = data->arrays_for_color->color_south[tex_x][tex_y];
				color = (color >> 1) & 8355711;
			}
			my_mlx_pixel_put(&data->img_buffer, x, y, color);
			y++;
		}
		int temp;
		temp = 0;
		while (temp < draw_start)
		{
			my_mlx_pixel_put(&data->img_buffer, x, temp, ft_rgb_handler(0, 154, 255));
			temp++;
		}
		int k;
		k = draw_end;
		while (k < PIXEL_HEIGHT)
		{
			my_mlx_pixel_put(&data->img_buffer, x, k, ft_rgb_handler(119, 69, 3));
			k++;
		}

		x++;
	}

	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_buffer.img, 0, 0);
//	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_map.img, ((PIXEL_WIDTH / 2) - ((data->size_map.width /2) * PIXEL_MAP)), (PIXEL_HEIGHT - (data->size_map.height * PIXEL_MAP)));
	mlx_destroy_image(data->mlx, data->img_buffer.img);
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




