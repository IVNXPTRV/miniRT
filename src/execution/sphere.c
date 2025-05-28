/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 15:51:38 by ipetrov           #+#    #+#             */
/*   Updated: 2025/05/28 12:17:21 by ipetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_num compute_sphere_intersection(t_ray ray, t_obj obj)
{
	t_vector	ray_to_obj_center;
	t_num		b;
	t_num		c;
	t_num		disc;						    // discriminant
	t_num		sqrt_disc;
	t_num		distance0;
	t_num		distance1;

	// compute L = O - C / points from the sphere’s center back to the ray’s origin
    ray_to_obj_center = sub_vectors(ray.position, obj.position);
    // disc coefficients
    b = 2.0 * dot(ray.direction, ray_to_obj_center);
    c = dot(ray_to_obj_center, ray_to_obj_center) - (obj.diameter / 2) * (obj.diameter / 2);
    disc = b * b - 4.0 * c;  // (a = 1 so 4ac = 4c)
    if (disc < 0.0)
        return (NOINTERSECTION);
    // two roots
    sqrt_disc = sqrt(disc);
    distance0 = (-b - sqrt_disc) * 0.5;
    distance1 = (-b + sqrt_disc) * 0.5;
	printf("distance0: %f\n", distance0);
	printf("distance1: %f\n", distance1);
    // pick the closest positive because t1 <= t0 by math
    if (distance0 > EPSILON)
        return (distance0);
    if (distance1 > EPSILON)
        return (distance1);
    return (NOINTERSECTION);
}
