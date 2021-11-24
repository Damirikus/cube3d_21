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

int	list_to_map(int argc, t_data *d)
{
	t_list	*head;
	t_list	*next;

	argc = 0;
	head = d->list;
	while (ft_str_empty(head->content))
	{
		free(head->content);
		next = head->next;
		free(head);
		head = next;
	}
	d->maplines = ft_lstsize(head);
	d->map = (char **)malloc(sizeof(char *) * (d->maplines + 1));
	if (!d->map)
		return (-1);
	while (argc < d->maplines)
	{
		d->map[argc++] = head->content;
		next = head->next;
		free(head);
		head = next;
	}
	d->map[d->maplines] = 0;
	return (1);
}
