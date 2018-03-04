/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olbondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 17:11:29 by olbondar          #+#    #+#             */
/*   Updated: 2018/02/24 17:11:31 by olbondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_line(t_map *map, int x, int y)
{
	int x0;
	int y0;
	int xy[2];

	x0 = map->dx + (x - y);
	y0 = map->dy + map->matrix[y / map->sy][x / map->sx] * map->z + x + y;
	if (x / map->sx < map->chars - 1 && y / map->sy < map->lines)
	{
		xy[0] = map->dx + ((x + map->sx) - y);
		xy[1] = map->dy + map->matrix[y / map->sy][x / map->sx + 1]
						* map->z + (x + map->sx) + y;
		brezenhem(map, x0, y0, xy);
	}
	if (y / map->sy < map->lines - 1 && x / map->sx < map->chars)
	{
		xy[0] = map->dx + (x - (y + map->sy));
		xy[1] = map->dy + map->matrix[y / map->sy + 1][x / map->sx]
						* map->z + x + (y + map->sy);
		brezenhem(map, x0, y0, xy);
	}
}
