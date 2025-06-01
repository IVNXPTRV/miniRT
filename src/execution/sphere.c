/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 15:51:38 by ipetrov           #+#    #+#             */
/*   Updated: 2025/05/28 16:33:23 by ipetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static t_num	calculate_disc(t_num *b, t_ray ray, t_obj obj)
{
	t_vector	ray_to_obj_center;
	t_num		disc;
	t_num		c;

	ray_to_obj_center = sub_vectors(ray.position, obj.position);
	*b = 2.0 * dot(ray.direction, ray_to_obj_center);
	c = dot(ray_to_obj_center, ray_to_obj_center) - (obj.diameter * 0.5)
		* (obj.diameter * 0.5);
	disc = *b * *b - 4.0 * c;
	return (disc);
}

t_num	compute_sphere_intersection(t_ray ray, t_obj obj)
{
	t_num		disc;
	t_num		sqrt_disc;
	t_num		distance0;
	t_num		distance1;
	t_num		b;

	disc = calculate_disc(&b, ray, obj);
	if (disc < 0.0)
		return (NOINTERSECTION);
	sqrt_disc = sqrt(disc);
	distance0 = (-b - sqrt_disc) * 0.5;
	distance1 = (-b + sqrt_disc) * 0.5;
	if (distance0 > EPSILON)
		return (distance0);
	if (distance1 > EPSILON)
		return (distance1);
	return (NOINTERSECTION);
}
