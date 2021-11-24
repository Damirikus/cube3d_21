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

int	ft_str_chr(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_mini_join(const char *s1, const char *s2, char *dst)
{
	int	i;
	int	j;
	int	len1;
	int	len2;

	i = 0;
	j = 0;
	len1 = ft_stlen(s1);
	len2 = ft_stlen(s2);
	while (i < len1)
	{
		dst[i] = s1[i];
		i++;
	}
	while (j < len2)
	{
		dst[i] = s2[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_join(char *s1, char *s2)
{
	int		len1;
	int		len2;
	int		size;
	char	*dst;

	if (!s1 && !s2)
		return (0);
	len1 = ft_stlen(s1);
	len2 = ft_stlen(s2);
	size = len1 + len2;
	dst = malloc(sizeof(char) * (size + 1));
	if (!dst)
		return (0);
	dst = ft_mini_join(s1, s2, dst);
	free((char *)s1);
	return (dst);
}

char	*ft_push_to_line(char *temp)
{
	int		i;
	int		j;
	char	*dst;

	if (!temp)
		return (0);
	i = 0;
	while (temp[i] && temp[i] != '\n')
		i++;
	j = 0;
	dst = malloc((i + 1) * sizeof (char));
	if (!dst)
		return (0);
	while (temp[j] != '\n' && temp[j] != '\0')
	{
		dst[j] = temp[j];
		j++;
	}
	dst[j] = '\0';
	return (dst);
}

char	*ft_remove_to_n(char *temp)
{
	int		i;
	int		n;
	char	*dst;

	i = 0;
	n = 0;
	while (temp[n] && temp[n] != '\n')
		n++;
	if (temp[n] == '\0')
	{
		free(temp);
		return (0);
	}
	dst = malloc(((ft_stlen(temp) - n) + 1) * (sizeof (char)));
	if (!dst)
		return (0);
	n++;
	while (temp[n] != '\0')
		dst[i++] = temp[n++];
	dst[i] = '\0';
	free(temp);
	return (dst);
}
