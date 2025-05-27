/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 19:06:13 by ipetrov           #+#    #+#             */
/*   Updated: 2025/05/27 10:21:16 by ipetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

inline bool is_miss(t_hit hit)
{
	return (hit.obj == NULL); // means no hit
}

t_color get_pixel_color(t_scene *scene, int x, int y)
{
	t_ray	ray;
	t_hit	hit;
	t_color	pixel;

	ray = get_ray(scene->camera, x, y);
	hit = get_hit(scene, ray);
	if (is_miss(hit))
		return (BLACK);			// BLACK
	pixel = add_light(scene, hit);
	return (pixel);
}
