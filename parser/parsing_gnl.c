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

int	parsing_gnl_line(t_data *d, char *line)
{
	int		ret;
	t_list	*list;

	if (d->color_flag < 2 || d->flag < 4)
	{
		if (ft_str_empty(line) != 0)
		{
			free(line);
			return (1);
		}
		ret = parsing_path(d, line);
		free(line);
		return (ret);
	}
	else
	{
		list = ft_lstnew(line);
		if (list == NULL)
			return (-1);
		ft_lstadd_back(&(d->list), list);
	}
	return (1);
}
