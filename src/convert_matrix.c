/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olbondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 16:22:40 by olbondar          #+#    #+#             */
/*   Updated: 2018/02/24 16:22:42 by olbondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

void	convert_matrix(t_map *map, char **tmp_matrix, int index)
{
	int j;

	j = 0;
	while (j < map->chars)
	{
		map->matrix[index][j] = ft_atoi(tmp_matrix[j]);
		free(tmp_matrix[j]);
		j++;
	}
	free(tmp_matrix);
}
