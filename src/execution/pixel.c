/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 19:06:13 by ipetrov           #+#    #+#             */
/*   Updated: 2025/05/21 19:07:37 by ipetrov          ###   ########.fr       */
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

	get_ray(scene->camera, x, y, &ray);
	get_hit(scene, ray, &hit);
	get_shadow(scene, hit, &shadow);
	get_light(scene, hit, shadow, &light);
	apply_light(hit, light, &pixel);
	return (pixel);
}
