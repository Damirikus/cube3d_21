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

#include "../cub3d.h"

int	confirm_pars(t_data *d)
{
	if (d->color_flag == 2 && d->flag == 4)
		return (1);
	else
		return (-1);
}

int	parser(int argc, char **argv, t_data *d)
{
	int		fd;
	int		res;
	char	*line;

	d->flag = 0;
	d->color_flag = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (map_error(-1));
	while (argc > 0)
	{
		argc = get_next_line(fd, &line);
		res = parsing_gnl_line(d, line);
		if (res == -1)
			return (map_error(-3));
	}
	close(fd);
	if (confirm_pars(d) == -1 || argc == -1)
		return (map_error(-3));
	if (list_to_map(argc, d) == -1)
		return (map_error(-4));
	if (valid_map(d->map, 0, 0, d) == -1)
		return (map_error(-5));
	return (1);
}

int	parsing_path(t_data *d, char *line)
{
	if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
		return (check_path(ft_strtrim(line + 2, " "), &d->south_texture, d));
	else if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
		return (check_path(ft_strtrim(line + 2, " "), &d->north_texture, d));
	else if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
		return (check_path(ft_strtrim(line + 2, " "), &d->east_texture, d));
	else if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
		return (check_path(ft_strtrim(line + 2, " "), &d->west_texture, d));
	if (line[0] == 'F' && line[1] == ' ' )
		return (check_color(ft_strtrim(line + 1, " "), &d->floor, d));
	else if (line[0] == 'C' && line[1] == ' ')
		return (check_color(ft_strtrim(line + 1, " "), &d->ceiling, d));
	if (d->color_flag == 1 || (d->flag >= 1 && d->flag <= 4) || !d->flag)
		return (-1);
	return (0);
}

int	check_path(char *path, t_xpm *x, t_data *d)
{
	int	i;

	i = 0;
	if (x->path == NULL)
	{
		if (path[i] == ' ')
		{
			while (path[i] == ' ')
				i++;
		}
		d->flag += 1;
		x->path = ft_strdup(&path[i]);
		free(path);
		return (1);
	}
	return (-1);
}
