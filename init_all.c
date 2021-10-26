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
	data->hero_position = malloc(sizeof(t_position_hero));
	data->map_array = init_map_array(argv[1], data);
	
	return (data);
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
