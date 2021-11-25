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

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2)
	{
		printf("Error: ./cub3D <filename>\n");
		return (0);
	}
	data = ft_init(argc, argv);
	if (!data)
		return (0);

	if (ft_start_game(data))
		printf("Invalid path\n");
	return (0);
}

int	ft_start_game(t_data *data)
{
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, PIXEL_WIDTH, \
	PIXEL_HEIGHT, "Cube 3D");
	ft_draw_map(data);
	if (get_all_colors_texture(data, &data->arrays_for_color->color_north, \
	data->north_texture.path))
		return (1);
	if (get_all_colors_texture(data, &data->arrays_for_color->color_south, \
	data->south_texture.path))
		return (1);
	if (get_all_colors_texture(data, &data->arrays_for_color->color_west, \
	data->west_texture.path))
		return (1);
	if (get_all_colors_texture(data, &data->arrays_for_color->color_east, \
	data->east_texture.path))
		return (1);
	mlx_hook(data->mlx_win, 2, 1L << 0, \
	ft_key_handler, data);
	mlx_hook(data->mlx_win, 17, 1L << 17, \
	ft_mlx_close, data);
	mlx_loop_hook(data->mlx, ft_game, data);
	mlx_loop(data->mlx);
	return (0);
}

int	ft_game(t_data *data)
{
	int	x;


	init_start_null(data);
	data->img_buffer.img = mlx_new_image(data->mlx, PIXEL_WIDTH, PIXEL_HEIGHT);
	data->img_buffer.addr = mlx_get_data_addr(data->img_buffer.img, \
	&data->img_buffer.bits_per_pixel, &data->img_buffer.line_length, \
	&data->img_buffer.endian);
	x = 0;
	while (x < PIXEL_WIDTH)
	{
		init_start_param(data, x);
		side_dist(data);
		find_hit(data);
		get_start_end_draw(data);
		get_texture_color(data);
		draw_texture(data, x);
		draw_floor_ceiling(data, x);
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_buffer.img, \
	0, 0);
	mlx_destroy_image(data->mlx, data->img_buffer.img);
	return (0);
}

void init_start_null(t_data *data)
{
	data->all.camera_x = 0;
	data->all.draw_end = 0;
	data->all.draw_start = 0;
	data->all.delta_dist_x = 0;
	data->all.delta_dist_y = 0;
	data->all.raydir_x = 0;
	data->all.raydir_y = 0;
	data->all.wall_x = 0;
	data->all.hit = 0;
	data->all.tex_y = 0;
	data->all.tex_x = 0;
	data->all.tex_pos = 0;
	data->all.step_y = 0;
	data->all.step_x = 0;
	data->all.side_dist_y = 0;
	data->all.side_dist_x = 0;
	data->all.side = 0;
	data->all.step = 0;
	data->all.line_height = 0;
	data->all.perp_wall_dist = 0;
	data->all.map_x = 0;
	data->all.map_y = 0;
}
