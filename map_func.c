/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantiloc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:32:00 by aantiloc          #+#    #+#             */
/*   Updated: 2021/11/24 14:32:06 by aantiloc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_allow_char(char **map, int i, int j, t_data *d);
static int	check_pos(char **map, t_data *d, int i, int j);
static int	is_closed(char **map, t_data *d, int i, int j);

int	valid_map(char **map, int i, int j, t_data *d)
{
	d->player = 0;
	while (map[i])
	{
		j = 0;
		if (i != 0)
			d->strlen_up = (int)ft_strlen(d->map[i - 1]);
		if (i < (d->maplines - 1))
			d->strlen_bot = (int)ft_strlen(d->map[i + 1]);
		d->map_str_len = (int)ft_strlen(d->map[i]);
		while (map[i][j] != 0)
		{
			if (check_allow_char(map, i, j, d) == -1)
				return (-1);
			if (check_pos(map, d, i, j) == -1)
				return (-1);
			if (is_closed(map, d, i, j) == -1)
				return (-1);
			j++;
		}
		i++;
	}
	if (d->player != 1)
		return (-1);
	printf ("MAP: OK\n");
	return (1);
}

static int	check_allow_char(char **map, int i, int j, t_data *d)
{
	if (!(map[i][j] == ' ' || map[i][j] == '0' || map[i][j] == '1'
			|| map[i][j] == '2' || map[i][j] == 'W' || map[i][j] == 'E'
				|| map[i][j] == 'S' || map[i][j] == 'N'))
		return (-1);
	if (map[i][j] == 'W' || map[i][j] == 'E' || map[i][j] == 'S'
			|| map[i][j] == 'N')
		d->player += 1;
	return (1);
}

static int	check_pos(char **map, t_data *d, int i, int j)
{
	if (map[i][j] != ' ' && map[i][j] != '1')
	{
		if (i == 0)
			return (-1);
		if (j == 0)
			return (-1);
		if (j == d->map_str_len - 1)
			return (-1);
		if (map[i][j] == '0' && map[i][j - 1] == ' ')
			return (-1);
		if (map[i][j] == '0' && map[i][j + 1] == ' ')
			return (-1);
	}
	return (1);
}

static int	is_closed(char **map, t_data *d, int i, int j)
{
	if (i == 0 && map[i + 1][j] == '0' && map[i][j] != '1')
		return (-1);
	if (map[i][j] == ' ' && map[i + 1][j] == '0')
		return (-1);
	if (i > 0 && map[i][j] == ' ' && map[i - 1][j] == '0')
		return (-1);
	if (map[i][j] == '0' && ft_strlen(map[i - 1]) <= j)
		return (-1);
	if (map[i][j] == '0' && ft_strlen(map[i + 1]) <= j)
		return (-1);
	if (map[i][j] == '0' && map[i][j - 1] == ' ')
		return (-1);
	if (map[d->maplines - 2][j] == '0' && map[d->maplines -1][j] != '1')
		return (-1);
	return (1);
}
