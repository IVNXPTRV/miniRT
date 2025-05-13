/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:54:03 by ipetrov           #+#    #+#             */
/*   Updated: 2024/12/08 10:40:00 by ipetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	node_clean(void *node_to_clean)
{
	t_lst	*node;

	node = (t_lst *)node_to_clean;
	lst_clean(&node, ft_free);
	return (SUCCESS);
}

static t_color	set_color(uint32_t hex, bool lock)
{
	t_color	color;

	color.r = (hex >> 16);
	color.g = (hex >> 8);
	color.b = (hex);
	color.a = 0xFF;
	color.lock = lock;
	return (color);
}

static int	init_node(t_lst **node, void *param)
{
	t_imginf	*img;
	int			number;
	size_t		i;
	size_t		j;
	t_lst		*halves;

	img = (t_imginf *)param;
	i = (*node)->i / img->width;
	j = (*node)->i % img->width;
	img->map[i][j].v.v3d.x = (double)j;
	img->map[i][j].v.v3d.y = (double)i;
	if (!ft_split(&halves, (*node)->item, ','))
		return (FAIL);
	if (!ft_atoi(lst_get(&halves, 0)->item, &number, sizeof(int), 10))
		return ((long)lst_clean(&halves, ft_free) - 1);
	img->map[i][j].v.v3d.z = (double)number;
	img->map[i][j].color = set_color(0xFF0000, false);
	if (lst_len(&halves) != 2)
		return ((long)lst_clean(&halves, ft_free) + 1);
	if (!ft_atoi(lst_get(&halves, 1)->item, &number, sizeof(int), 16))
		return ((long)lst_clean(&halves, ft_free) - 1);
	img->map[i][j].color = set_color((unsigned int)number, true);
	lst_clean(&halves, ft_free);
	return (SUCCESS);
}

static int	init_img_map(t_lst **map, t_imginf *img)
{
	size_t	spans[2];

	spans[0] = img->height;
	spans[1] = img->width;
	if (!ft_alloc(&(img->map), sizeof(t_node), 2, spans))
		return (FAIL);
	if (!lst_iter(map, init_node, img))
		return ((int)ft_parrclean(FAIL, free, img->map, NULL));
	img->offset.x = 0;
	img->offset.y = 0;
	img->offset.z = 0;
	img->rotation.x = 90 + 35.264 - 6;
	img->rotation.y = 0;
	img->rotation.z = 45;
	img->scale = 1;
	get_scale(img);
	img->scale /= 2;
	return (SUCCESS);
}

//parsing and init imginf and map;
t_imginf	*get_img(char **argv)
{
	t_imginf	img;
	t_lst		*map;
	t_imginf	*result;
	int			fd;

	map = NULL;
	if (!is_valid_file(argv[1], &fd))
		return (NULL);
	if (!add_map_height(fd, &map, &img))
	{
		close (fd);
		return (NULL);
	}
	close(fd);
	if (!add_map_width(&map, &img))
		return (lst_clean(&map, ft_free));
	if (!init_img_map(&map, &img))
		return (lst_clean(&map, ft_free));
	lst_clean(&map, ft_free);
	result = malloc(sizeof(t_imginf));
	if (!result)
		return ((void *)ft_parrclean(FAIL, free, img.map, NULL));
	*result = img;
	return (result);
}
