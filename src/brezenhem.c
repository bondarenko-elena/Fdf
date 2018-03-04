/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brezenhem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olbondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 17:03:12 by olbondar          #+#    #+#             */
/*   Updated: 2018/02/24 17:03:42 by olbondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	brezenhem(t_map *map, int x0, int y0, int *xy)
{
	int arr_x[2];
	int arr_y[2];
	int e[2];

	arr_x[0] = abs(xy[0] - x0);
	arr_y[0] = abs(xy[1] - y0);
	arr_x[1] = x0 < xy[0] ? 1 : -1;
	arr_y[1] = y0 < xy[1] ? 1 : -1;
	e[0] = (arr_x[0] > arr_y[0] ? arr_x[0] : -arr_y[0]) / 2;
	while (x0 != xy[0] || y0 != xy[1])
	{
		mlx_pixel_put(map->mlx_init, map->window, x0, y0, map->color);
		e[1] = e[0];
		if (e[1] > (arr_x[0] * -1))
		{
			e[0] -= arr_y[0];
			x0 += arr_x[1];
		}
		if (e[1] < arr_y[0])
		{
			e[0] += arr_x[0];
			y0 += arr_y[1];
		}
	}
}
