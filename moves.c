#include "cub3d.h"


int ft_key_handler(int key, t_data *data)
{
	if (key == 53)
	{
//		ft_free_all(main);
		exit(1);
	}
	if (key == 13)
	{
		if (!data->map_array_int[(int)(data->start_position_int.pos_x + data->start_position_int.dir_x * MOVE_SPEED)]
		[(int)(data->start_position_int.pos_y)])
			data->start_position_int.pos_x += data->start_position_int.dir_x * MOVE_SPEED;
		if (!data->map_array_int[(int)(data->start_position_int.pos_x)]
		[(int)(data->start_position_int.pos_y + data->start_position_int.dir_y * MOVE_SPEED)])
			data->start_position_int.pos_y += data->start_position_int.dir_y * MOVE_SPEED;
	}
	if (key == 1)
	{
		if (!data->map_array_int[(int)(data->start_position_int.pos_x - data->start_position_int.dir_x * MOVE_SPEED)]
		[(int)(data->start_position_int.pos_y)])
			data->start_position_int.pos_x -= data->start_position_int.dir_x * MOVE_SPEED;
		if (!data->map_array_int[(int)(data->start_position_int.pos_x)]
		[(int)(data->start_position_int.pos_y - data->start_position_int.dir_y * MOVE_SPEED)])
			data->start_position_int.pos_y -= data->start_position_int.dir_y * MOVE_SPEED;
	}
	if (key == 2)
	{
		double  old_dir_x = data->start_position_int.dir_x;
		data->start_position_int.dir_x =data->start_position_int.dir_x * cos(-ROT_SPEED) - data->start_position_int.dir_y * sin(-ROT_SPEED);
		data->start_position_int.dir_y = old_dir_x * sin(-ROT_SPEED) + data->start_position_int.dir_y * cos(-ROT_SPEED);
		double old_plane_x = data->start_position_int.plane_x;
		data->start_position_int.plane_x = data->start_position_int.plane_x * cos(-ROT_SPEED) - data->start_position_int.plane_y * sin(-ROT_SPEED);
		data->start_position_int.plane_y = old_plane_x * sin(-ROT_SPEED) + data->start_position_int.plane_y * cos(-ROT_SPEED);
	}
	if (key == 0)
	{
		double  old_dir_x = data->start_position_int.dir_x;
		data->start_position_int.dir_x = data->start_position_int.dir_x * cos(ROT_SPEED) - data->start_position_int.dir_y * sin(ROT_SPEED);
		data->start_position_int.dir_y = old_dir_x * sin(ROT_SPEED) + data->start_position_int.dir_y * cos(ROT_SPEED);
		double old_plane_x = data->start_position_int.plane_x;
		data->start_position_int.plane_x = data->start_position_int.plane_x * cos(ROT_SPEED) - data->start_position_int.plane_y * sin(ROT_SPEED);
		data->start_position_int.plane_y = old_plane_x * sin(ROT_SPEED) + data->start_position_int.plane_y * cos(ROT_SPEED);
	}
	return 0;
}