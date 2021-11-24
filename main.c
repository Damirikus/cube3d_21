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
	ft_start_game(data);
	return (0);
}

void	ft_start_game(t_data *data)
{
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, PIXEL_WIDTH, \
	PIXEL_HEIGHT, "Cube 3D");
	ft_draw_map(data);
	get_all_colors_texture(data, &data->arrays_for_color->color_north, \
	data->north_texture.path);
	get_all_colors_texture(data, &data->arrays_for_color->color_south, \
	data->south_texture.path);
	get_all_colors_texture(data, &data->arrays_for_color->color_west, \
	data->west_texture.path);
	get_all_colors_texture(data, &data->arrays_for_color->color_east, \
	data->east_texture.path);
	mlx_hook(data->mlx_win, 2, 1L << 0, \
	ft_key_handler, data);
	mlx_hook(data->mlx_win, 17, 1L << 17, \
	ft_mlx_close, data);
	mlx_loop_hook(data->mlx, ft_game, data);
	mlx_loop(data->mlx);
}

int	ft_game(t_data *data)
{
	int	x;

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
