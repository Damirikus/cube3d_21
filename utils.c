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

int	map_error(int code)
{
	if (code == -1)
		printf("Error\nCan`t open map file\n");
	else if (code == -2)
		printf("Error\ncan`t read map from file\n");
	else if (code == -3)
		printf("Error\ninvalid xpm path or colors\n");
	else if (code == -4)
		printf("Error\nlist to array\n");
	else if (code == -5)
		printf("Error\nInvalid map\n");
	else
		printf("Error\nAnother fail\n");
	return (-1);
}

int	ft_empt(const char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (c);
	else
		return (0);
}

int	ft_str_empty(const char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (ft_empt(line[i++]))
			continue ;
		else
			return (0);
	}
	return (1);
}

int	ft_atoi_for_char(char c)
{
	int	nb;

	nb = 0;
	if (c >= 48 && c <= 57)
		nb = 10 * nb + (c - 48);
	else if (c == 'N' || c == 'W' || c == 'E' || c == 'S')
		nb = 0;
	else
		nb = 5;
	return (nb);
}
