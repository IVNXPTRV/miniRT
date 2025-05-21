/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 19:06:13 by ipetrov           #+#    #+#             */
/*   Updated: 2025/05/21 20:23:19 by ipetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_color get_pixel_color(t_scene *scene, int x, int y)
{
	t_ray	ray;
	t_hit	hit;
	t_color	pixel;
	bool	shadow;
	int		light; 				// some coefficent

	ray = get_ray(scene->camera, x, y);
	hit = get_hit(scene, ray);
	shadow = get_shadow(scene, hit);
	light = get_light(scene, hit, shadow, &light);
	pixel = apply_light(hit, light);
	return (pixel);
}
