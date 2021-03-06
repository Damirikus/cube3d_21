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

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t num)
{
	size_t			i;
	unsigned char	*edst;
	unsigned char	*esrc;

	i = 0;
	esrc = (unsigned char *)src;
	edst = (unsigned char *)dst;
	while (i < num)
	{
		edst[i] = esrc[i];
		if (edst[i] == (unsigned char)c)
			return (edst + i + 1);
		i++;
	}
	return (NULL);
}
