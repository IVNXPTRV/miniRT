/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 18:56:04 by ipetrov           #+#    #+#             */
/*   Updated: 2025/05/28 19:56:52 by ipetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static t_color	cap_color(t_color pixel)
{
	if (pixel.r > 1)
		pixel.r = 1;
	if (pixel.g > 1)
		pixel.g = 1;
	if (pixel.b > 1)
		pixel.b = 1;
	return (pixel);
}

static t_color	sum_light(t_color ambient, t_color diffuse)
{
	t_color	pixel;

	pixel.r = ambient.r + diffuse.r;
	pixel.g = ambient.g + diffuse.g;
	pixel.b = ambient.b + diffuse.b;
	pixel = cap_color(pixel);
	return (pixel);
}

t_color	add_light(t_scene *scene, t_hit hit)
{
	t_color	pixel;
	t_color	ambient;
	t_color	diffuse;

	ambient = get_ambient(scene, hit);
	diffuse = get_diffuse(scene, hit);
	pixel = sum_light(ambient, diffuse);
	return (pixel);
}
