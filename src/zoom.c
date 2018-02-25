/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_plus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olbondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 18:48:43 by olbondar          #+#    #+#             */
/*   Updated: 2018/02/24 18:48:45 by olbondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom(t_map *map, int key_code)
{
	if (key_code == 69)
	{
		mlx_clear_window(map->mlx_init, map->window);
		if (map->sx < 600)
			map->sx *= 2;
		if (map->sy < 600)
			map->sy *= 2;
		drawer(map);
	}
	if (key_code == 78)
	{
		mlx_clear_window(map->mlx_init, map->window);
		if (map->sx < 600)
			map->sx *= 0.5;
		if (map->sy < 600)
			map->sy *= 0.5;
		drawer(map);
	}
}
