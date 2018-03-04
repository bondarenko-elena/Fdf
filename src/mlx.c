/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olbondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 17:07:54 by olbondar          #+#    #+#             */
/*   Updated: 2018/02/24 17:08:05 by olbondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	mlx(t_map *map)
{
	map->mlx_init = mlx_init();
	map->window = mlx_new_window(map->mlx_init, WIDTH, HEIGHT, "olbondar");
	init_map(map);
	drawer(map);
	mlx_key_hook(map->window, handle_key, map);
	mlx_loop(map->mlx_init);
}
