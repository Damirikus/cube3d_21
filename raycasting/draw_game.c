/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdominqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:32:00 by sdominqu          #+#    #+#             */
/*   Updated: 2021/11/24 14:32:06 by sdominqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_texture(t_data *data, int x)
{
	int	y;
	int	color;

	y = data->all.draw_start;
	while (y < data->all.draw_end)
	{
		data->all.tex_y = (int)(data->all.tex_pos) & (TEX_HEIGHT - 1);
		data->all.tex_pos += data->all.step;
		if (data->all.side == 0)
			draw_texture_part(data, &color);
		else
		{
			if (data->all.step_y < 0)
				color = data->arrays_for_color->color_west \
				[data->all.tex_x][data->all.tex_y];
			else
				color = data->arrays_for_color->color_east \
				[data->all.tex_x][data->all.tex_y];
			color = (color >> 1) & 8355711;
		}
		my_mlx_pixel_put(&data->img_buffer, x, y, color);
		y++;
	}
}

void	draw_texture_part(t_data *data, int *color)
{
	if (data->all.step_x > 0)
		(*color) = data->arrays_for_color->color_south \
				[data->all.tex_x][data->all.tex_y];
	else
		(*color) = data->arrays_for_color->color_north \
				[data->all.tex_x][data->all.tex_y];
}

void	draw_floor_ceiling(t_data *data, int x)
{
	int	temp;
	int	k;

	temp = 0;
	while (temp < data->all.draw_start)
	{
		my_mlx_pixel_put(&data->img_buffer, x, temp, \
		ft_rgb_handler(data->ceiling.r, data->ceiling.g, data->ceiling.b));
		temp++;
	}
	k = data->all.draw_end;
	while (k < PIXEL_HEIGHT)
	{
		my_mlx_pixel_put(&data->img_buffer, x, k, ft_rgb_handler(data->floor.r, \
		data->floor.g, data->floor.b));
		k++;
	}
}
