/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 19:44:00 by ipetrov           #+#    #+#             */
/*   Updated: 2025/05/23 15:51:22 by ipetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_num compute_plane_intersection(t_ray ray, t_obj obj)
{
	t_num		denom;
	t_num		numerator;
	t_num		distance;
	t_vector	ray_to_obj_center;

	ray_to_obj_center = sub_vectors(obj.position, ray.position);
	denom = dot(obj.normal, ray.direction);
	if (fabs(denom) < EPSILON)						// ray is near parallel to a plane
    	return (NOINTERSECTION);
	numerator = dot(ray_to_obj_center, obj.normal);
	distance = numerator / denom;
	if (distance > EPSILON)							// check if not negative and not to close to 0
		return (distance);
	return (NOINTERSECTION);
}
