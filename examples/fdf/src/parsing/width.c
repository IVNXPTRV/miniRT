/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:52:29 by ipetrov           #+#    #+#             */
/*   Updated: 2024/12/07 12:20:53 by ipetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	split_to_columns(t_lst **map, void *param)
{
	t_lst	**columns;
	t_lst	*row;

	columns = (t_lst **)param;
	if (!ft_split(&row, (*map)->item, ' '))
		return (ERROR);
	if (!lst_insert(columns, &row, -1))
		return ((long)lst_clean(&row, ft_free));
	return (CONTINUE);
}

int	add_map_width(t_lst **map, t_imginf *img)
{
	t_lst	*columns;
	size_t	len;

	columns = NULL;
	if (!lst_iter(map, split_to_columns, &columns))
		return ((size_t)lst_clean(&columns, ft_free));
	if (!columns)
	{
		perror("Map is empty!");
		return (FAIL);
	}
	len = lst_len(&columns);
	if (len % img->height > 0)
	{
		perror("Map is not rectangular!");
		return ((size_t)lst_clean(&columns, ft_free));
	}
	img->width = len / img->height;
	lst_clean(map, ft_free);
	*map = columns;
	return (SUCCESS);
}
