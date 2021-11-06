#include "cub3d.h"

int ft_draw_map(t_data *data)
{
	int i;
	int k;
	int x;
	int y;
	int a, b;

	data->img_map.img = mlx_new_image(data->mlx, data->size_map.width * PIXEL_MAP, data->size_map.height * PIXEL_MAP);
	data->img_map.addr = mlx_get_data_addr(data->img_map.img, &data->img_map.bits_per_pixel, &data->img_map.line_length, &data->img_map.endian);
	i = 0;
	while (data->map_array[i])
	{
		k = 0;
		while (k < ft_strlen(data->map_array[i]))
		{
			if (data->map_array[i][k] == 'N')
			{
				data->start_position_int.pos_x = i;
				data->start_position_int.pos_y = k;
				data->start_position_int.dir_x = 0;
				data->start_position_int.dir_y = -1;
			}
			else if (data->map_array[i][k] == 'S')
			{
				data->start_position_int.pos_x = i;
				data->start_position_int.pos_y = k;
				data->start_position_int.dir_x = 0;
				data->start_position_int.dir_y = 1;
			}
			else if (data->map_array[i][k] == 'E')
			{
				data->start_position_int.pos_x = i;
				data->start_position_int.pos_y = k;
				data->start_position_int.dir_x = 1;
				data->start_position_int.dir_y = 0;
			}
			else if (data->map_array[i][k] == 'W')
			{
				data->start_position_int.pos_x = i;
				data->start_position_int.pos_y = k;
				data->start_position_int.dir_x = -1;
				data->start_position_int.dir_y = 0;
			}
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