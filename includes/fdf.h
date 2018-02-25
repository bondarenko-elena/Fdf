/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olbondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 17:01:41 by olbondar          #+#    #+#             */
/*   Updated: 2018/02/24 17:01:43 by olbondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <math.h>
# include "../libft/libft.h"

# define WIDTH 900
# define HEIGHT 900

typedef struct		s_map
{
	int				fd;
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				z;
	void			*mlx_init;
	void			*window;
	int				**matrix;
	unsigned long	color;
	int				chars;
	int				lines;
	char			*argv;
	int				check_chars;
}					t_map;

void				brezenhem(t_map *map, int x0, int y0, int *xy);
void				put_line(t_map *map, int x, int y);
void				init_map(t_map *map);
void				drawer(t_map *map);
int					handle_key(int key_code, t_map *map);
void				mlx(t_map *map);
int					alloc_lines(t_map *map);
int					parser(t_map *map);
void				init_check_chars(t_map *map);
void				convert_matrix(t_map *map, char **tmp_matrix, int index);
void				table_del(int **matrix, int len);
void				zoom(t_map *map, int key_code);
void				move(t_map *map, int key_code);

#endif
