/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 16:06:00 by ipetrov           #+#    #+#             */
/*   Updated: 2025/05/28 19:44:25 by ipetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_num	limit_body(t_num distance0, t_num distance1, t_ray ray, t_obj obj)
{
	t_point	hit_position;
	t_num	height;

	if (distance0 > EPSILON)
	{
		hit_position = add_vectors(ray.position, scale_vector(ray.direction,
					distance0));
		height = dot(sub_vectors(hit_position, obj.position), obj.normal);
		if (fabs(height) <= (obj.height * 0.5) + EPSILON)
			return (distance0);
	}
	else
		distance0 = NOINTERSECTION;
	if (distance1 > EPSILON)
	{
		hit_position = add_vectors(ray.position, scale_vector(ray.direction,
					distance1));
		height = dot(sub_vectors(hit_position, obj.position), obj.normal);
		if (fabs(height) <= (obj.height * 0.5) + EPSILON)
			return (distance1);
	}
	else
		distance1 = NOINTERSECTION;
	return (NOINTERSECTION);
}

static t_num	calculate_coefficients(t_num *b, t_num *c, t_ray ray, t_obj obj)
{
	t_vector	ray_to_obj_center;
	t_vector	prj_ray_direction;
	t_vector	prj_ray_to_obj_direction;
	t_num		a;

	ray_to_obj_center = sub_vectors(ray.position, obj.position);
	prj_ray_direction = sub_vectors(ray.direction, scale_vector(obj.normal,
				dot(ray.direction, obj.normal)));
	prj_ray_to_obj_direction = sub_vectors(ray_to_obj_center,
			scale_vector(obj.normal, dot(ray_to_obj_center, obj.normal)));
	a = dot(prj_ray_direction, prj_ray_direction);
	*b = 2.0 * dot(prj_ray_direction, prj_ray_to_obj_direction);
	*c = dot(prj_ray_to_obj_direction, prj_ray_to_obj_direction) - (obj.diameter
			* 0.5) * (obj.diameter * 0.5);
	return (a);
}

t_num	compute_cylinder_intersection(t_ray ray, t_obj obj)
{
	t_num	a;
	t_num	b;
	t_num	c;
	t_num	disc;
	t_num	sqrt_disc;

	a = calculate_coefficients(&b, &c, ray, obj);
	if (fabs(a) < EPSILON)
		return (NOINTERSECTION);
	disc = b * b - 4.0 * a * c;
	if (disc < 0.0)
		return (NOINTERSECTION);
	sqrt_disc = sqrt(disc);
	return (limit_body((-b - sqrt_disc) / (2.0 * a), (-b + sqrt_disc) / (2.0
				* a), ray, obj));
}
