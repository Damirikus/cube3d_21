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
	ft_start_game(data);

	return 0;
}


int ft_draw_map(t_data *data)
{
	int i;
	int k;
	int x;
	int y;
	int a, b;
	data->img_map.img = mlx_new_image(data->mlx, 1920, 1080);
	data->img_map.addr = mlx_get_data_addr(data->img_map.img, &data->img_map.bits_per_pixel, &data->img_map.line_length, &data->img_map.endian);
	i = 8;
	while (data->map_array[i])
	{
		k = 0;
		while (k < ft_strlen(data->map_array[i]))
		{
			if (data->map_array[i][k] == '1')
			{
				x = i * PIXEL_MAP;
				y = k * PIXEL_MAP;
				a = 0;
				while (a < PIXEL_MAP)
				{
					b = 0;
					while (b < PIXEL_MAP)
					{
						my_mlx_pixel_put(&data->img_map, y + a, x + b,ft_rgb_handler(122,122,122));
						b++;
					}
					a++;
				}
				

			}
			k++;
		}
		i++;
	}


	return 0;
}

void ft_start_game(t_data *data)
{
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, 1920, 1080, "Cube 3D");
	ft_draw_map(data);
	

	// mlx_hook(data->mlx_win, 2, 1L << 0, ft_key_handler, main);
	mlx_hook(data->mlx_win, 17, 1L << 17, ft_mlx_close, data);
	mlx_loop_hook(data->mlx, ft_game, data);
	mlx_loop(data->mlx);
}




int ft_game(t_data *data)
{


	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_map.img, 0, 0);
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




