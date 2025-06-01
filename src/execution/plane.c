/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 19:44:00 by ipetrov           #+#    #+#             */
/*   Updated: 2025/05/28 12:05:03 by ipetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_num	compute_plane_intersection(t_ray ray, t_obj obj)
{
	t_num		denom;
	t_num		numerator;
	t_num		distance;
	t_vector	ray_to_obj_center;

	ray_to_obj_center = sub_vectors(obj.position, ray.position);
	denom = dot(obj.normal, ray.direction);
	if (fabs(denom) < EPSILON)
		return (NOINTERSECTION);
	numerator = dot(ray_to_obj_center, obj.normal);
	distance = numerator / denom;
	if (distance > EPSILON)
	{
		return (distance);
	}
	return (NOINTERSECTION);
}
