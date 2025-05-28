/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 16:06:00 by ipetrov           #+#    #+#             */
/*   Updated: 2025/05/28 16:55:13 by ipetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// TODO
t_num compute_cylinder_intersection(t_ray ray, t_obj obj)
{
    t_vector    ray_to_obj_center;
    t_vector    prj_ray_direction;
    t_vector    prj_ray_to_obj_direction;
    t_num       a;
    t_num       b;
    t_num       c;
    t_num       disc;
    t_num       sqrt_disc;
    t_num       distance0; // Renamed to t0 and t1 for clarity
    t_num       distance1;

    // Vector from ray origin to cylinder center
    ray_to_obj_center = sub_vectors(ray.position, obj.position);

    // Project ray direction onto plane perpendicular to cylinder axis
    // This removes the component of ray.direction along the cylinder axis
    prj_ray_direction = sub_vectors(ray.direction, scale_vector(obj.normal, dot(ray.direction, obj.normal)));

    // Project vector from ray origin to cylinder center onto plane perpendicular to cylinder axis
    prj_ray_to_obj_direction = sub_vectors(ray_to_obj_center, scale_vector(obj.normal, dot(ray_to_obj_center, obj.normal)));

    // Coefficients for the quadratic equation At^2 + Bt + C = 0
    a = dot(prj_ray_direction, prj_ray_direction);
    b = 2.0 * dot(prj_ray_direction, prj_ray_to_obj_direction);
    c = dot(prj_ray_to_obj_direction, prj_ray_to_obj_direction) - (obj.diameter * 0.5) * (obj.diameter * 0.5);

    // Handle case where ray is parallel or nearly parallel to cylinder axis
    // If 'a' is very small, the ray is nearly parallel to the cylinder axis.
    // In this case, if the ray is also outside the cylinder, there's no intersection.
    // If it's inside, it's either always inside (which is not a distinct intersection point)
    // or it just grazes it. For simplicity, we often return NOINTERSECTION if 'a' is too small
    // as it indicates a degenerate case for this quadratic solution.
    if (fabs(a) < EPSILON) // Use fabs for robustness with float comparisons
    {
        // If 'a' is near zero, and 'c' is also near zero, it means the ray starts
        // very close to the cylinder surface and is parallel. This is complex.
        // For general ray tracing, often treated as no intersection or a graze.
        // If |c| is small, the ray is very close to the surface.
        // A more robust parallel ray test would be needed for edge cases.
        // For now, return NOINTERSECTION.
        return (NOINTERSECTION);
    }

    disc = b * b - 4.0 * a * c;

    if (disc < 0.0) // No real roots, ray misses the infinite cylinder
        return (NOINTERSECTION);

    sqrt_disc = sqrt(disc);

    // Calculate the two possible intersection distances
    distance0 = (-b - sqrt_disc) / (2.0 * a);
    distance1 = (-b + sqrt_disc) / (2.0 * a);

    // Pick the closest positive intersection point
    // An intersection is valid if t > EPSILON (to avoid self-intersection or intersections behind the ray origin)
    if (distance0 > EPSILON)
        return (distance0);
    if (distance1 > EPSILON)
        return (distance1);

    return (NOINTERSECTION);
}
