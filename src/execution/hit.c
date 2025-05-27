/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 18:10:35 by ipetrov           #+#    #+#             */
/*   Updated: 2025/05/27 09:55:12 by ipetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void register_closest_obj(t_num distance, t_num min_distance, t_obj **obj, int i)
{
	if (distance > 0 && distance < min_distance)
	{
		min_distance = distance;
		*obj = &obj[i];
	}
}

static t_hit init_hit(t_num distance, t_ray ray, t_obj *obj)
{
	t_hit	hit;

	hit.position = (t_point){0};
	hit.normal = (t_vector){0};
	hit.obj = obj;
	if (hit.obj == NULL)																		// means no object hit
		return (hit);
	hit.position = add_vector(add_vector(ray.position, scale_vector(ray.direction, distance)));	// check if IT IS CORRECT?																	// get for light calculation later, or calculater later in a shadow??
	return (hit);
}

t_hit get_hit(t_scene *scene, t_ray ray)
{
	int		i;											// counter
	t_num	min_distance;								// distance along ray to object surface
	t_num	distance;
	t_hit	hit;
	t_obj	*obj;

	i = -1;
	min_distance = DBL_MAX; 							// change to -1 ????
	obj = NULL;											// no obj hit so far
	while(++i < scene->obj_num)							// loop to traverse all scene objects
	{
		if (scene->obj[i].type == PL)
			distance = compute_plane_intersection(ray, scene->obj[i]);
		else if (scene->obj[i].type == SP)
			distance = compute_sphere_intersection(ray, scene->obj[i]);
		else if (scene->obj[i].type == CY)
			distance = compute_cylinder_intersection(ray, scene->obj[i]);
		register_closest_obj(distance, min_distance, &obj, i);
	}
	hit = init_hit(min_distance, ray, obj);
	return (hit);
}
