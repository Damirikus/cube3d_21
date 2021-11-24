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

void	check_type(char *argv)
{
	char	*tmp;

	tmp = NULL;
	if (!argv)
	{
		printf("Error: Put map into program arguments! \n");
		printf("Example: ./cub3d ""\"de_dust2.cub""\" \n");
		exit(1);
	}
	else
	{
		tmp = ft_substr(argv, (ft_strlen(argv) - 4), ft_strlen(argv));
		if (tmp[0] != '.' || tmp[1] != 'c' || tmp[2] != 'u' || tmp[3] != 'b')
		{
			printf("Error: Only ""\".cub""\" map extension allowed \n");
			free(tmp);
			exit(1);
		}
		free(tmp);
	}
}
