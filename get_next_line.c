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

#include "get_next_line.h"

int	ft_stlen(const char *s)
{
	int	len;

	len = 0;
	if (!s)
		return (0);
	while (s[len])
		len++;
	return (len);
}

int	get_next_line(int fd, char **line)
{
	static char	*temp;
	char		buf[BUFFER_SIZE + 1];
	int			res;

	res = 1;
	if (!line || fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (-1);
	while (!ft_str_chr(temp) && res)
	{
		res = read(fd, buf, BUFFER_SIZE);
		buf[res] = '\0';
		temp = ft_join(temp, buf);
		if (!temp)
			return (-1);
	}
	*line = ft_push_to_line(temp);
	temp = ft_remove_to_n(temp);
	if (res == 0)
		return (0);
	return (1);
}
