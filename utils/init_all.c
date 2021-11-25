/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdominqu <sdominqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 18:59:41 by sdominqu          #+#    #+#             */
/*   Updated: 2021/10/25 16:54:51 by sdominqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_data	*ft_init(int argc, char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));

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


	data->arrays_for_color = malloc(sizeof(t_arrays));

	check_type(argv[1]);
	if (parser(argc, argv, data) == -1)
	{
		ft_free_mini(data);
		return (NULL);
	}
	init_int_array(data);
	return (data);
}

void	init_int_array(t_data *data)
{
	int	i;
	int	k;

	data->map_array_int = malloc(sizeof(int *) * (data->maplines - 1));
	i = 0;
	while (data->map[i] != 0)
	{
		data->map_array_int[i] = malloc(sizeof(int) * ft_strlen(data->map[i]));
		k = 0;
		if (!data->map_array_int[i])
			break ;
		while (data->map[i][k])
		{
			data->map_array_int[i][k] = ft_atoi_for_char(data->map[i][k]);
			k++;
		}
		i++;
	}
}

void	ft_free_mini(t_data *data)
{
	int	i;

	i = 0;
	if (data->map)
	{
		if (data->map[i])
		{
			while (i < data->maplines - 1)
			{
				free(data->map[i]);
				i++;
			}
		}
		free(data->map);
	}
	if (data->north_texture.path)
		free(data->north_texture.path);
	if (data->south_texture.path)
		free(data->south_texture.path);
	if (data->east_texture.path)
		free(data->east_texture.path);
	if (data->west_texture.path)
		free(data->west_texture.path);
	free(data);
}
