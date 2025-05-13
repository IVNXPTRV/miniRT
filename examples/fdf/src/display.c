/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:42:20 by ipetrov           #+#    #+#             */
/*   Updated: 2024/12/07 20:47:53 by ipetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_node	modify(t_node n, t_imginf *img)
{
	n = flip(n, img);
	n = rotate(n, img);
	n = scale(n, img);
	n = offset(n, img);
	n = project(n);
	return (n);
}

static void	plot_lines(t_node *nodes[3], t_imginf *img)
{
	t_node	root;

	root = modify(*nodes[0], img);
	if (nodes[1])
		put_line(root, modify(*nodes[1], img), img);
	if (nodes[2])
		put_line(root, modify(*nodes[2], img), img);
}

static void	get_nodes(t_node *(*node)[3], t_imginf *img, int i, int j)
{
	(*node)[0] = &img->map[i][j];
	if (j + 1 < img->width)
		(*node)[1] = &img->map[i][j + 1];
	else
		(*node)[1] = NULL;
	if (i + 1 < img->height)
		(*node)[2] = &img->map[i + 1][j];
	else
		(*node)[2] = NULL;
}

static void	fill_background(t_imginf *img)
{
	int	total;
	int	c;

	c = 0;
	total = WIDTH * HEIGHT;
	while (c < total)
	{
		mlx_put_pixel(img->img, c % WIDTH, c / WIDTH, 0x000000FF);
		c++;
	}
}

void	update_image(void *img)
{
	t_node	*nodes[3];
	int		c;
	int		i;
	int		j;
	int		total;

	c = 0;
	total = ((t_imginf *)img)->height * ((t_imginf *)img)->width;
	fill_background(img);
	while (c < total)
	{
		i = c / ((t_imginf *)img)->width;
		j = c % ((t_imginf *)img)->width;
		get_nodes(&nodes, ((t_imginf *)img), i, j);
		plot_lines(nodes, ((t_imginf *)img));
		c++;
	}
}
