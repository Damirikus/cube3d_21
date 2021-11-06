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
	data->full_array = init_map_array(argv[1], data);
	cut_array(data);
	init_int_array(data);
	data->start_position_int.plane_x = 0;
	data->start_position_int.plane_y = 0.66;
	data->start_position_int.time = 0;
	data->start_position_int.oldTime = 0;
	return (data);
}

void init_int_array(t_data *data)
{
	data->map_array_int = malloc(sizeof(int *) * (data->size_map.height));
	int i;
	int k;
	i = 0;
	while (data->map_array[i])
	{
		data->map_array_int[i] = malloc(sizeof(int) * ft_strlen(data->map_array[i]));
		k = 0;
		while (data->map_array[i][k])
		{
			data->map_array_int[i][k] = ft_atoi_for_char(data->map_array[i][k]);
			k++;
		}
		i++;
	}
}

void cut_array(t_data *data)
{
	int i;
	int k;
	i = 0;
	int max;

	while (data->full_array[i])
		i++;
	i -= 8;
	data->size_map.height = i;
	data->map_array = malloc(sizeof(char *) * i + 1);
	data->map_array[i] = 0;
	i = 8;
	k = 0;
	max = ft_strlen(data->full_array[i]);
	while (data->full_array[i])
	{
		if (ft_strlen(data->full_array[i]) > max)
			max = ft_strlen(data->full_array[i]);
		data->map_array[k] = malloc(ft_strlen(data->full_array[i]) + 1);
		ft_strlcpy(data->map_array[k], data->full_array[i], ft_strlen(data->full_array[i]) + 1);
		i++;
		k++;
	}
	data->size_map.width = max;
}

char	**init_map_array(char *filename, t_data *data)
{
	int		fd;
	int		qw_line;
	char **arr;
	int i;
	int len;
	char *str;
	
	fd = open(filename, O_RDONLY);
	qw_line = ft_qw_line(fd);
	close(fd);
	arr = malloc(sizeof(char *) * (qw_line + 1));
	arr[qw_line] = 0;
	i = 0;
	fd = open(filename, O_RDONLY);
	while (i < qw_line)
	{
		get_next_line(fd, &str);
		arr[i] = malloc(sizeof(char) * ft_strlen(str) + 1);
		ft_strlcpy(arr[i], str, ft_strlen(str) + 1);
		free(str);
		i++;
	}
	close(fd);
	return (arr);
}

int	ft_qw_line(int fd)
{
	int		i;
	char	*str;

	i = 0;
	while (get_next_line(fd, &str))
	{
		free(str);
		i++;
	}
	i++;
	free(str);
	return (i);
}


