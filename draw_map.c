#include "cub3d.h"

int ft_draw_map(t_data *data)
{
	int i;
	int k;

	i = 0;
	while (data->map[i])
	{
		k = 0;
		while (k < ft_strlen(data->map[i]))
		{
			if (data->map[i][k] == 'N')
			{
				data->start_position_int.pos_x = i;
				data->start_position_int.pos_y = k;
				data->start_position_int.dir_x = 0;
				data->start_position_int.dir_y = -1;
			}
			else if (data->map[i][k] == 'S')
			{
				data->start_position_int.pos_x = i;
				data->start_position_int.pos_y = k;
				data->start_position_int.dir_x = 0;
				data->start_position_int.dir_y = 1;
			}
			else if (data->map[i][k] == 'E')
			{
				data->start_position_int.pos_x = i;
				data->start_position_int.pos_y = k;
				data->start_position_int.dir_x = 1;
				data->start_position_int.dir_y = 0;
			}
			else if (data->map[i][k] == 'W')
			{
				data->start_position_int.pos_x = i;
				data->start_position_int.pos_y = k;
				data->start_position_int.dir_x = -1;
				data->start_position_int.dir_y = 0;
			}
			k++;
		}
		i++;
	}
	return 0;
}