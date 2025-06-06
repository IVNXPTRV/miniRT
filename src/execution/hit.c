/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 18:10:35 by ipetrov           #+#    #+#             */
/*   Updated: 2025/05/28 19:57:34 by ipetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	register_closest_obj(t_num distance, t_num *min_distance,
		t_obj *obj, t_obj **dst)
{
	if (distance < *min_distance)
	{
		*min_distance = distance;
		*dst = obj;
	}
}

static t_hit	init_hit(t_num distance, t_ray ray, t_obj *obj)
{
	t_hit	hit;

	hit.position = (t_point){0};
	hit.normal = (t_vector){0};
	hit.obj = obj;
	if (hit.obj == NULL)
		return (hit);
	hit.position = add_vectors(ray.position, scale_vector(ray.direction,
				distance));
	return (hit);
}

t_hit	get_hit(t_scene *scene, t_ray ray)
{
	int		i;
	t_num	min_distance;
	t_num	distance;
	t_hit	hit;
	t_obj	*obj;

	i = -1;
	min_distance = DBL_MAX;
	obj = NULL;
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
		register_closest_obj(distance, &min_distance, &scene->obj[i], &obj);
	}
	hit = init_hit(min_distance, ray, obj);
	return (hit);
}
