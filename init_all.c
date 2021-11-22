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

#include "cub3d.h"


t_data *ft_init(int argc, char **argv)
{

	t_data *data;
	data = malloc(sizeof(t_data));
	data->arrays_for_color = malloc(sizeof(t_arrays));
	data->start_position_int.plane_x = 0;
	data->start_position_int.plane_y = 0.66;
	data->start_position_int.time = 0;
	data->start_position_int.oldTime = 0;
	check_type(argv[1]);
	parser(argc, argv, data);
	init_int_array(data);

	return (data);
}

void init_int_array(t_data *data)
{
	data->map_array_int = malloc(sizeof(int *) * (data->maplines - 1));
	int i;
	int k;
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


