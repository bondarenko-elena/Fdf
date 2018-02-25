/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_check_chars.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olbondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 17:05:13 by olbondar          #+#    #+#             */
/*   Updated: 2018/02/24 17:05:14 by olbondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

void	init_check_chars(t_map *map)
{
	char	*line;
	int		ret;
	int		i;

	i = 0;
	while (i < 1)
	{
		ret = get_next_line(map->fd, &line);
		map->check_chars = ft_countwords(line, ' ');
		i++;
	}
	free(line);
	close(map->fd);
	map->fd = open(map->argv, O_RDONLY);
}
