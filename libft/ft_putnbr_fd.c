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

void	ft_putnbr_fd(int n, int fd)
{
	long	lnum;
	char	res;

	lnum = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		lnum = lnum * -1;
	}
	if (lnum / 10 != 0)
		ft_putnbr_fd(lnum / 10, fd);
	res = (lnum % 10) + 48;
	ft_putchar_fd(res, fd);
}
