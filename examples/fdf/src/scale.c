/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:45:56 by ipetrov           #+#    #+#             */
/*   Updated: 2024/12/08 10:01:16 by ipetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_node	scale(t_node n, t_imginf *img)
{
	n.v.v3d.x *= img->scale;
	n.v.v3d.y *= img->scale;
	n.v.v3d.z *= img->scale;
	return (n);
}

static void	fit(t_imginf *img, t_node arr[3])
{
	double	dx;
	double	dy;

	dx = fabs(fabs(scale(arr[0], img).v.v3d.x) - \
	fabs(scale(arr[1], img).v.v3d.x));
	dy = fabs(fabs(scale(arr[2], img).v.v3d.y) - \
	fabs(scale(arr[3], img).v.v3d.y));
	while (dx < (WIDTH - 40) && dy < (HEIGHT - 40))
	{
		img->scale += 0.1;
		img->offset.x = -(dx / 2) / 2;
		img->offset.y = (dy / 2) / 2;
		dx = fabs(fabs(scale(arr[0], img).v.v3d.x) - \
		fabs(scale(arr[1], img).v.v3d.x));
		dy = fabs(fabs(scale(arr[2], img).v.v3d.y) - \
		fabs(scale(arr[3], img).v.v3d.y));
	}
}

void	get_scale(t_imginf *img)
{
	int		c;
	t_node	n;
	t_node	arr[4];

	c = 1;
	n = rotate(flip(img->map[c / img->width][c % img->width], img), img);
	arr[0] = n;
	arr[1] = n;
	arr[2] = n;
	arr[3] = n;
	while (c < img->height * img->width)
	{
		n = rotate(flip(img->map[c / img->width][c % img->width], img), img);
		if (n.v.v3d.x > arr[0].v.v3d.x)
			arr[0].v.v3d.x = n.v.v3d.x;
		if (n.v.v3d.x < arr[1].v.v3d.x)
			arr[1].v.v3d.x = n.v.v3d.x;
		if (n.v.v3d.y > arr[2].v.v3d.y)
			arr[2].v.v3d.y = n.v.v3d.y;
		if (n.v.v3d.y < arr[3].v.v3d.y)
			arr[3].v.v3d.y = n.v.v3d.y;
		c++;
	}
	fit(img, arr);
}
