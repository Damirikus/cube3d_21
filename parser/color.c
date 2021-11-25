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

static int	color_cycle(char **colors)
{
	int	i;
	int	j;

	i = 0;
	while (colors[i])
	{
		j = 0;
		while (colors[i][j])
		{
			if (colors[i][j] < 48 || colors[i][j] > 57)
				return (-1);
			j++;
		}
		i++;
	}
	return (i);
}

static int	counter(char *line)
{
	int	i;
	int	c;

	c = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == ',')
			c++;
		i++;
	}
	return (c);
}
static char **set_colors(char *line)
{
	char **colors;

	colors = ft_split(line, ',');
	colors[0] = ft_strtrim(colors[0], " ");
	colors[1] = ft_strtrim(colors[1], " ");
	colors[2] = ft_strtrim(colors[2], " ");
	if (!colors[0] || !colors[1] || !colors[2])
		return (NULL);
	if (colors[0][0] == '\0'|| colors[1][0] == '\0' || colors[2][0] == '\0')
		return (NULL);
	return (colors);
}

int	check_color(char *line, t_color *c, t_data *d)
{
	char	**colors;

	colors = NULL;
	if (c->r != 0 || c->g != 0 || c->b != 0)
		return (map_error(-22));
	if (counter(line) != 2)
		return (map_error(-22));
	colors = set_colors(line);
	if (!colors)
		return (map_error(-22));
	if (color_cycle(colors) == -1)
		return (-1);
	c->r = ft_atoi(colors[0]);
	c->g = ft_atoi(colors[1]);
	c->b = ft_atoi(colors[2]);
	if (c->r < 0 || c->g < 0 || c->b < 0
		|| c->r > 255 || c->g > 255 || c->b > 255)
		return (map_error(-22));
	free(colors[0]);
	free(colors[1]);
	free(colors[2]);
	free(colors);
	d->color_flag += 1;
	free(line);
	return (1);
}
