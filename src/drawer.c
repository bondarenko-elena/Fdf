/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olbondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 17:03:54 by olbondar          #+#    #+#             */
/*   Updated: 2018/02/24 17:04:16 by olbondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	drawer(t_map *map)
{
	int x;
	int y;

	x = 0;
	y = 0;
	if (map->sx == 0 || map->sy == 0)
	{
		map->sx++;
		map->sy++;
	}
	while (x / map->sx < map->chars || y / map->sy < map->lines - 1)
	{
		if (x / map->sx == map->chars)
		{
			x = 0;
			y += map->sy;
		}
		put_line(map, x, y);
		x += map->sx;
	}
}
