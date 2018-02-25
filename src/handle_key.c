/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olbondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 17:04:31 by olbondar          #+#    #+#             */
/*   Updated: 2018/02/24 17:04:33 by olbondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	handle_key(int key_code, t_map *map)
{
	if (key_code == 88)
	{
		mlx_clear_window(map->mlx_init, map->window);
		map->z--;
		drawer(map);
	}
	if (key_code == 92)
	{
		mlx_clear_window(map->mlx_init, map->window);
		map->z++;
		drawer(map);
	}
	if (key_code == 8)
	{
		mlx_clear_window(map->mlx_init, map->window);
		map->color = map->color >> 1;
		drawer(map);
	}
	if (key_code == 69 || key_code == 78)
		zoom(map, key_code);
	if (key_code >= 123 && key_code <= 126)
		move(map, key_code);
	if (key_code == 53)
		exit(0);
	return (0);
}
