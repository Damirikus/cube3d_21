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

int	ft_mlx_close(t_data *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	exit(0);
}

void	ft_free_all(t_data *data)
{
	int	i;

	i = 0;
	while (i < TEX_WIDTH)
	{
		free(data->arrays_for_color->color_north[i]);
		free(data->arrays_for_color->color_south[i]);
		free(data->arrays_for_color->color_east[i]);
		free(data->arrays_for_color->color_west[i]);
		i++;
	}
	free(data->arrays_for_color->color_north);
	free(data->arrays_for_color->color_south);
	free(data->arrays_for_color->color_east);
	free(data->arrays_for_color->color_west);
	free(data->arrays_for_color);
	free(data->mlx);
	free(data->mlx_win);
	ft_free_all_part(data);
}

void	ft_free_all_part(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->maplines - 1)
	{
		free(data->map_array_int[i]);
		free(data->map[i]);
		i++;
	}
	free(data->map_array_int);
	free(data->map);
	free(data->north_texture.path);
	free(data->south_texture.path);
	free(data->east_texture.path);
	free(data->west_texture.path);
	free(data);
}
