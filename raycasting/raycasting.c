#include "../cub3d.h"

void	init_start_param(t_data *data, int x)
{
	data->all.camera_x = 2 * x / (double)PIXEL_WIDTH - 1;
	data->all.raydir_x = data->start_position_int.dir_x + \
	data->start_position_int.plane_x * data->all.camera_x;
	data->all.raydir_y = data->start_position_int.dir_y + \
	data->start_position_int.plane_y * data->all.camera_x;
	data->all.map_x = (int)data->start_position_int.pos_x;
	data->all.map_y = (int)data->start_position_int.pos_y;
	data->all.delta_dist_x = fabs(1 / data->all.raydir_x);
	data->all.delta_dist_y = fabs(1 / data->all.raydir_y);
	data->all.hit = 0;
}

void	side_dist(t_data *data)
{
	if (data->all.raydir_x < 0)
	{
		data->all.step_x = -1;
		data->all.side_dist_x = (data->start_position_int.pos_x - \
		data->all.map_x) * data->all.delta_dist_x;
	}
	else
	{
		data->all.step_x = 1;
		data->all.side_dist_x = (data->all.map_x + 1.0 - \
		data->start_position_int.pos_x) * data->all.delta_dist_x;
	}
	if (data->all.raydir_y < 0)
	{
		data->all.step_y = -1;
		data->all.side_dist_y = (data->start_position_int.pos_y - \
		data->all.map_y) * data->all.delta_dist_y;
	}
	else
	{
		data->all.step_y = 1;
		data->all.side_dist_y = (data->all.map_y + 1.0 - \
		data->start_position_int.pos_y) * data->all.delta_dist_y;
	}
}

void	find_hit(t_data *data)
{
	while (data->all.hit == 0)
	{
		if (data->all.side_dist_x < data->all.side_dist_y)
		{
			data->all.side_dist_x += data->all.delta_dist_x;
			data->all.map_x += data->all.step_x;
			data->all.side = 0;
		}
		else
		{
			data->all.side_dist_y += data->all.delta_dist_y;
			data->all.map_y += data->all.step_y;
			data->all.side = 1;
		}
		if (data->map_array_int[data->all.map_x][data->all.map_y] > 0 \
		&& data->map_array_int[data->all.map_x][data->all.map_y] != 5)
		{
			data->all.hit = 1;
		}
	}
}

void	get_start_end_draw(t_data *data)
{
	if (data->all.side == 0)
		data->all.perp_wall_dist = (data->all.side_dist_x - \
		data->all.delta_dist_x);
	else
		data->all.perp_wall_dist = (data->all.side_dist_y - \
		data->all.delta_dist_y);
	data->all.line_height = (int)(PIXEL_HEIGHT / data->all.perp_wall_dist);
	data->all.draw_start = -data->all.line_height / 2 + PIXEL_HEIGHT / 2;
	if (data->all.draw_start < 0)
		data->all.draw_start = 0;
	data->all.draw_end = data->all.line_height / 2 + PIXEL_HEIGHT / 2;
	if (data->all.draw_end >= PIXEL_HEIGHT)
		data->all.draw_end = PIXEL_HEIGHT - 1;
}

void	get_texture_color(t_data *data)
{
	if (data->all.side == 0)
		data->all.wall_x = data->start_position_int.pos_y + \
		data->all.perp_wall_dist * data->all.raydir_y;
	else
		data->all.wall_x = data->start_position_int.pos_x + \
		data->all.perp_wall_dist * data->all.raydir_x;
	data->all.wall_x -= floor(data->all.wall_x);
	data->all.tex_x = (int)(data->all.wall_x * (double)(TEX_WIDTH));
	if (data->all.side == 0 && data->all.raydir_x > 0)
		data->all.tex_x = TEX_WIDTH - data->all.tex_x - 1;
	if (data->all.side == 1 && data->all.raydir_y < 0)
		data->all.tex_x = TEX_WIDTH - data->all.tex_x - 1;
	data->all.step = 1.0 * TEX_HEIGHT / data->all.line_height;
	data->all.tex_pos = (data->all.draw_start - PIXEL_HEIGHT / 2 + \
	data->all.line_height / 2) * data->all.step;
}
