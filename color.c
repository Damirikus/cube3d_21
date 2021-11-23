#include "cub3d.h"
int check_color(char *line, t_color *c, t_data *d)
{
	char **colors;

	colors = NULL;
	if (c->r != 0 || c->g != 0 || c->b != 0)
	{
		printf("Error\nColor already exist\n");
		return (-99);
	}

	colors = ft_split(line, ',');
	c->r = ft_atoi(colors[0]);
	c->g = ft_atoi(colors[1]);
	c->b = ft_atoi(colors[2]);
	if (c->r < 0 || c->g < 0 || c->b < 0 || c->r > 255 || c->g > 255 || c->b > 255)
	{
		printf("Error\nIvalid color\n");
		return (-100);
	}
	d->color_flag += 1;
	return (1);
}