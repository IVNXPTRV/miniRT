/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 19:39:48 by ipetrov           #+#    #+#             */
/*   Updated: 2025/05/28 19:58:14 by ipetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

bool	is_inside_disc(t_point point_on_plane, t_point center_of_disc,
		t_num radius)
{
	t_vector	vec_to_center;

	vec_to_center = sub_vectors(point_on_plane, center_of_disc);
	return (dot(vec_to_center, vec_to_center) <= (radius * radius) + EPSILON);
}

t_num	compute_disk_intersection(t_ray ray, t_obj obj)
{
	t_num	distance;
	t_point	hit_position;

	distance = compute_plane_intersection(ray, obj);
	if (distance != NOINTERSECTION)
	{
		hit_position = add_vectors(ray.position, scale_vector(ray.direction,
					distance));
		if (!is_inside_disc(hit_position, obj.position, obj.diameter * 0.5))
			distance = NOINTERSECTION;
	}
	return (distance);
}
