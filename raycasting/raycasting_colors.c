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

unsigned int	ft_get_color(t_img_addr *temp, int i, int j)
{
	char			*str;
	unsigned int	c;

	str = temp->addr + (j * temp->line_length + i * (temp->bits_per_pixel / 8));
	c = *(unsigned int *)str;
	return (c);
}

int	get_all_colors_texture(t_data *data, int ***colors, char *path)
{
	t_img_addr	temp;
	int			i;
	int			j;

	i = 0;
	j = 0;
	temp.img = mlx_xpm_file_to_image(data->mlx, path, &j, &i);
	if (!temp.img)
		return (1);
	temp.addr = mlx_get_data_addr(temp.img, &temp.bits_per_pixel, \
	&temp.line_length, &temp.endian);
	(*colors) = malloc(sizeof(int *) * TEX_HEIGHT);
	i = -1;
	while (++i < TEX_HEIGHT)
	{
		(*colors)[i] = malloc(sizeof(int) * TEX_WIDTH);
		j = 0;
		while (j < TEX_WIDTH)
		{
			(*colors)[i][j] = ft_get_color(&temp, i, j);
			j++;
		}
	}
	mlx_destroy_image(data->mlx, temp.img);
	return (0);
}

int	ft_rgb_handler(int r, int g, int b)
{
	int	rgb;

	rgb = r * 65536 + g * 256 + b;
	return (rgb);
}

void	my_mlx_pixel_put(t_img_addr *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
