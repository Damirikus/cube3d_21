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

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 1

typedef struct s_list1
{
	int				fd;
	char			*prev_str;
	struct s_list1	*next;
}					t_list1;

int		get_next_line(const int fd, char **line);
size_t	ft_strlen1(const char *str);
size_t	ft_strlcpy1(char *dst, const char *src, size_t size);
char	*ft_strjoin1(char *s1, char *s2, size_t n);
char	*ft_strdup1(char *str);

#endif