/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   height.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:51:47 by ipetrov           #+#    #+#             */
/*   Updated: 2024/12/07 12:19:51 by ipetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	validate_height(t_lst **map, t_imginf *img)
{
	if (*map)
	{
		img->height = lst_len(map);
		return (SUCCESS);
	}
	perror("Map is empty!");
	return (FAIL);
}

int	add_map_height(int fd, t_lst **map, t_imginf *img)
{
	char	*line;
	int		status;

	while (1)
	{
		status = get_next_line(fd, &line);
		if (status == STOP)
			break ;
		if (status == ERROR)
			return ((size_t)lst_clean(map, ft_free));
		if (ft_strlen(line) == 1 && line[0] == '\n')
		{
			perror("Map is empty!");
			free(line);
			return ((size_t)lst_clean(map, ft_free));
		}
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		if (!lst_add(map, line, -1))
		{
			free(line);
			return ((size_t)lst_clean(map, ft_free));
		}
	}
	return (validate_height(map, img));
}
