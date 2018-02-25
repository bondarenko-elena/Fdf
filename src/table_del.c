/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_del.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olbondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 15:59:25 by olbondar          #+#    #+#             */
/*   Updated: 2018/02/24 15:59:28 by olbondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

void	table_del(int **matrix, int len)
{
	int	i;

	i = 0;
	while (i < len)
		free(matrix[i]);
	free(matrix);
}
