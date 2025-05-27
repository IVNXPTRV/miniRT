/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 20:23:24 by ipetrov           #+#    #+#             */
/*   Updated: 2025/05/27 09:35:34 by ipetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// calculate intersection to any obj
// hit_point - ray->origin = ray->direction * t
// t =  (hit_point - ray->origin) / ray->direction
// get shadow and calculate normal at hit point if no shadow
bool is_shadowed(t_scene *scene, t_hit hit, t_ray ray)
{
	int		i;
	t_num	distance;
	t_num	distance_to_light;

	distance_to_light = magnitude(sub_vectors(scene->light.position, ray.position));
	i = -1;
	while(++i < scene->obj_num)							// loop to traverse all scene objects
	{
		if (scene->obj[i].type == PL)
			distance = compute_plane_intersection(ray, scene->obj[i]);
		else if (scene->obj[i].type == SP)
			distance = compute_sphere_intersection(ray, scene->obj[i]);
		else if (scene->obj[i].type == CY)
			distance = compute_cylinder_intersection(ray, scene->obj[i]);
		if (distance != NOINTERSECTION && distance < distance_to_light)
			return (true);
	}
	return (false);
}
