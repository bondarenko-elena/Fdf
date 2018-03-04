/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olbondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 17:08:44 by olbondar          #+#    #+#             */
/*   Updated: 2018/02/24 17:08:45 by olbondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

int	parser(t_map *map)
{
	char	*line;
	char	**tmp_matrix;
	int		ret;
	int		i;
	int		j;

	i = 0;
	init_check_chars(map);
	if ((map->lines = alloc_lines(map)) == -1)
		return (-1);
	while ((ret = get_next_line(map->fd, &line)) > 0)
	{
		tmp_matrix = ft_strsplit(line, ' ');
		if ((map->chars = ft_countwords(line, ' ')) != map->check_chars)
			return (-1);
		free(line);
		if (!(map->matrix[i] = (int*)malloc(sizeof(int) * (map->chars))))
			return (-1);
		j = 0;
		convert_matrix(map, tmp_matrix, i);
		i++;
	}
	if (ret == -1)
		return (-1);
	return (0);
}
