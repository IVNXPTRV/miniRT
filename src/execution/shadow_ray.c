/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 20:23:24 by ipetrov           #+#    #+#             */
/*   Updated: 2025/05/28 16:03:25 by ipetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

bool	is_shadowed(t_scene *scene, t_ray ray)
{
	int		i;
	t_num	distance;
	t_num	distance_to_light;

	distance_to_light = magnitude(sub_vectors(scene->light.position,
				ray.position));
	i = -1;
	while (++i < scene->obj_num)
	{
		if (scene->obj[i].type == PL)
			distance = compute_plane_intersection(ray, scene->obj[i]);
		else if (scene->obj[i].type == SP)
			distance = compute_sphere_intersection(ray, scene->obj[i]);
		else if (scene->obj[i].type == CY)
			distance = compute_cylinder_intersection(ray, scene->obj[i]);
		else if (scene->obj[i].type == DS)
			distance = compute_disk_intersection(ray, scene->obj[i]);
		if (distance != NOINTERSECTION && distance < distance_to_light)
			return (true);
	}
	return (false);
}
