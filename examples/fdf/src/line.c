/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:47:50 by ipetrov           #+#    #+#             */
/*   Updated: 2024/12/07 12:23:32 by ipetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static double	get_gradient_weight(t_node start, t_node end, t_node curr)
{
	double	past;
	double	full;

	past = sqrt(\
	pow((double)curr.v.v2d.x - (double)start.v.v2d.x, 2) + \
	pow((double)curr.v.v2d.y - (double)start.v.v2d.y, 2));
	full = sqrt(\
	pow((double)end.v.v2d.x - (double)start.v.v2d.x, 2) + \
	pow((double)end.v.v2d.y - (double)start.v.v2d.y, 2));
	return (past / full);
}

static uint32_t	get_color(t_node start, t_node end, t_node c)
{
	double	weight;

	weight = get_gradient_weight(start, end, c);
	c.color.r = round(start.color.r * (1 - weight) + end.color.r * weight);
	c.color.g = round(start.color.g * (1 - weight) + end.color.g * weight);
	c.color.b = round(start.color.b * (1 - weight) + end.color.b * weight);
	c.color.a = round(start.color.a * (1 - weight) + end.color.a * weight);
	return (c.color.r << 24 | c.color.g << 16 | c.color.b << 8 | c.color.a);
}

static t_plot	set_plot_vars(t_node n0, t_node n1)
{
	t_plot	p;

	p.n0 = n0;
	p.dx = abs(n1.v.v2d.x - n0.v.v2d.x);
	p.dy = abs(n1.v.v2d.y - n0.v.v2d.y);
	if (n0.v.v2d.x < n1.v.v2d.x)
		p.sx = 1;
	else
		p.sx = -1;
	if (n0.v.v2d.y < n1.v.v2d.y)
		p.sy = 1;
	else
		p.sy = -1;
	p.err = p.dx - p.dy;
	return (p);
}

void	put_line(t_node n0, t_node n1, t_imginf *img)
{
	t_plot	p;

	p = set_plot_vars(n0, n1);
	while (1)
	{
		if (n0.v.v2d.x < WIDTH && n0.v.v2d.y < HEIGHT \
		&& n0.v.v2d.x > 0 && n0.v.v2d.y > 0)
			mlx_put_pixel(img->img, n0.v.v2d.x, n0.v.v2d.y, \
			get_color(p.n0, n1, n0));
		if (n0.v.v2d.x == n1.v.v2d.x && n0.v.v2d.y == n1.v.v2d.y)
			break ;
		p.e2 = 2 * p.err;
		if (p.e2 > -p.dy)
		{
			p.err -= p.dy;
			n0.v.v2d.x += p.sx;
		}
		if (p.e2 < p.dx)
		{
			p.err += p.dx;
			n0.v.v2d.y += p.sy;
		}
	}
}
