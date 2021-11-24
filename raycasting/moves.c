#include "../cub3d.h"

int	ft_key_handler(int key, t_data *data)
{
	if (key == 53)
	{
		ft_free_all(data);
		exit(1);
	}
	if (key == 13)
		move_up(data);
	if (key == 1)
		move_down(data);
	if (key == 2)
		turn_left(data);
	if (key == 0)
		turn_right(data);
	return (0);
}

void	move_up(t_data *data)
{
	if (!data->map_array_int \
	[(int)(data->start_position_int.pos_x \
	+ data->start_position_int.dir_x * MOVE_SPEED)] \
	[(int)(data->start_position_int.pos_y)])
		data->start_position_int.pos_x \
		+= data->start_position_int.dir_x * MOVE_SPEED;
	if (!data->map_array_int[(int)(data->start_position_int.pos_x)]
	[(int)(data->start_position_int.pos_y \
	+ data->start_position_int.dir_y * MOVE_SPEED)])
		data->start_position_int.pos_y \
		+= data->start_position_int.dir_y * MOVE_SPEED;
}

void	move_down(t_data *data)
{
	if (!data->map_array_int[(int)(data->start_position_int.pos_x \
	- data->start_position_int.dir_x * MOVE_SPEED)]
	[(int)(data->start_position_int.pos_y)])
		data->start_position_int.pos_x -= data->start_position_int.dir_x \
		* MOVE_SPEED;
	if (!data->map_array_int[(int)(data->start_position_int.pos_x)]
	[(int)(data->start_position_int.pos_y - data->start_position_int.dir_y \
	* MOVE_SPEED)])
		data->start_position_int.pos_y -= data->start_position_int.dir_y \
		* MOVE_SPEED;
}

void	turn_right(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->start_position_int.dir_x;
	data->start_position_int.dir_x = data->start_position_int.dir_x \
	* cos(ROT_SPEED) - data->start_position_int.dir_y * sin(ROT_SPEED);
	data->start_position_int.dir_y = old_dir_x * sin(ROT_SPEED) \
	+ data->start_position_int.dir_y * cos(ROT_SPEED);
	old_plane_x = data->start_position_int.plane_x;
	data->start_position_int.plane_x = data->start_position_int.plane_x \
	* cos(ROT_SPEED) - data->start_position_int.plane_y * sin(ROT_SPEED);
	data->start_position_int.plane_y = old_plane_x * sin(ROT_SPEED) \
	+ data->start_position_int.plane_y * cos(ROT_SPEED);
}

void	turn_left(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->start_position_int.dir_x;
	data->start_position_int.dir_x = data->start_position_int.dir_x \
	* cos(-ROT_SPEED) - data->start_position_int.dir_y * sin(-ROT_SPEED);
	data->start_position_int.dir_y = old_dir_x * sin(-ROT_SPEED) \
	+ data->start_position_int.dir_y * cos(-ROT_SPEED);
	old_plane_x = data->start_position_int.plane_x;
	data->start_position_int.plane_x = data->start_position_int.plane_x \
	* cos(-ROT_SPEED) - data->start_position_int.plane_y * sin(-ROT_SPEED);
	data->start_position_int.plane_y = old_plane_x * sin(-ROT_SPEED) \
	+ data->start_position_int.plane_y * cos(-ROT_SPEED);
}
