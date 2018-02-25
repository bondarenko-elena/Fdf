/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olbondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 17:02:33 by olbondar          #+#    #+#             */
/*   Updated: 2018/02/24 17:02:59 by olbondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

int	alloc_lines(t_map *map)
{
	char	*line;
	int		ret;

	line = NULL;
	while ((ret = get_next_line(map->fd, &line)) > 0)
	{
		map->lines++;
		free(line);
	}
	if (!(map->matrix = (int**)malloc(sizeof(int*) * map->lines)))
	{
		table_del(map->matrix, map->lines);
		return (-1);
	}
	close(map->fd);
	map->fd = open(map->argv, O_RDONLY);
	return (map->lines);
}
