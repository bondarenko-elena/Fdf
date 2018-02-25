/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olbondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 17:06:37 by olbondar          #+#    #+#             */
/*   Updated: 2018/02/24 17:06:39 by olbondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <fcntl.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_map map;

	if (argc == 2)
	{
		map.argv = argv[1];
		map.fd = open(map.argv, O_RDONLY);
		if (map.fd < 0)
		{
			ft_putendl("Error");
			exit(1);
		}
		else
		{
			if (parser(&map) != -1)
				mlx(&map);
			else
				ft_putendl("Error");
		}
	}
	else
		ft_putendl("usage: ./fdf file");
	return (0);
}
