/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olbondar <olbondar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 14:53:59 by olbondar          #+#    #+#             */
/*   Updated: 2018/02/25 12:33:18 by olbondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_data(int const fd, char **data)
{
	static char	buff[BUFF_SIZE + 1] = {"\n"};
	int			ret;
	char		*str;

	str = NULL;
	ret = read(fd, buff, BUFF_SIZE);
	if (ret > 0)
	{
		buff[ret] = '\0';
		if (!(str = ft_strjoin(*data, buff)))
			return (-1);
		free(*data);
		*data = str;
	}
	return (ret);
}

int	c(int fd, char **line)
{
	if (fd < 0 || line == NULL || BUFF_SIZE < 1)
		return (-1);
	return (0);
}

int	get_next_line(const int fd, char **line)
{
	static char	*data = NULL;
	char		*endline;
	int			ret;

	if ((c(fd, line) != 0) || (!data && !(data = (char*)malloc(sizeof(char)))))
		return (-1);
	endline = ft_strchr(data, '\n');
	while (endline == NULL)
	{
		if ((ret = get_data(fd, &data)) == 0)
		{
			if ((endline = ft_strchr(data, '\0')) == data)
				return (0);
		}
		else if (ret < 0)
			return (-1);
		else
			endline = ft_strchr(data, '\n');
	}
	if (!(*line = ft_strsub(data, 0, endline - data)))
		return (-1);
	endline = ft_strdup(endline + 1);
	free(data);
	data = endline;
	return (1);
}
