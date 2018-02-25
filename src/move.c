/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olbondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 11:46:52 by olbondar          #+#    #+#             */
/*   Updated: 2018/02/25 11:46:54 by olbondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	move(t_map *map, int key_code)
{
	mlx_clear_window(map->mlx_init, map->window);
	if (key_code == 123)
	{
		if (map->dx < 900)
			map->dx -= 10;
	}
	if (key_code == 124)
	{
		if (map->dx < 900)
			map->dx += 10;
	}
	if (key_code == 125)
	{
		if (map->dy < 900)
			map->dy += 10;
	}
	if (key_code == 126)
	{
		if (map->dy < 900)
			map->dy -= 10;
	}
	drawer(map);
}
