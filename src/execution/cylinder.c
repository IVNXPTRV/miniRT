/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 16:06:00 by ipetrov           #+#    #+#             */
/*   Updated: 2025/05/28 19:14:06 by ipetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// check if hit is beyond cylinder height
t_num limit_body(t_num distance0, t_num distance1, t_ray ray, t_obj obj)
{
	t_point	hit_position;
	t_num	height;

	if (distance0 > EPSILON)
	{
		hit_position = add_vectors(ray.position, scale_vector(ray.direction, distance0));
		height = dot(sub_vectors(hit_position, obj.position), obj.normal);
		// if (fabs(height) > (obj.height * 0.5) + EPSILON)
		// 	distance0 = NOINTERSECTION;
		if (fabs(height) <= (obj.height * 0.5) + EPSILON)
			return (distance0);
	}
	else
		distance0 = NOINTERSECTION;
	if (distance1 > EPSILON)
	{
		hit_position = add_vectors(ray.position, scale_vector(ray.direction, distance1));
		height = dot(sub_vectors(hit_position, obj.position), obj.normal);
		// if (fabs(height) > (obj.height * 0.5) + EPSILON)
		// 	distance1 = NOINTERSECTION;
		if (fabs(height) <= (obj.height * 0.5) + EPSILON)
			return (distance1);
	}
	else
		distance1 = NOINTERSECTION;
	// if (distance0 == NOINTERSECTION && distance1 == NOINTERSECTION)
	// 	return (NOINTERSECTION);
	// if (distance0 < distance1)
	// 	return (distance0);
	// else
	// 	return (distance1);

	return (NOINTERSECTION);
}
// TODO
// body
// caps
t_num compute_cylinder_intersection_body(t_ray ray, t_obj obj)
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

    // // Pick the closest positive intersection point
    // // An intersection is valid if t > EPSILON (to avoid self-intersection or intersections behind the ray origin)
    // if (distance0 > EPSILON)
    //     return ();
    // if (distance1 > EPSILON)
    //     return (limit_body(distance1, ray, obj));

    return (limit_body(distance0, distance1, ray, obj));
}

// Helper function to check if a point is within a circle's radius
// This is used to check if a hit on a cap plane is within the disc
bool is_inside_disc(t_point point_on_plane, t_point center_of_disc, t_num radius)
{
    t_vector vec_to_center;

	vec_to_center = sub_vectors(point_on_plane, center_of_disc);
    return (dot(vec_to_center, vec_to_center) <= (radius * radius) + EPSILON);
}

t_num compute_cylinder_intersection_caps(t_ray ray, t_obj obj)
{
	t_point cap_bottom_center;					// center of a bottom cap
    t_point cap_top_center;						// center of a top cap
    t_num distance_cap_top;					// distance to a top cap or NONINTERSEC if no intersection
    t_num distance_cap_bottom;				// distance to a top bottom or NONINTERSEC if no intersection
	t_obj	cap;								// temp obj for cap to calculate intersection
	t_point hit_position;

	cap_top_center = add_vectors(obj.position, scale_vector(obj.normal, obj.height * 0.5));
	cap_bottom_center = sub_vectors(obj.position, scale_vector(obj.normal, obj.height * 0.5));

	cap.position = cap_top_center;
	cap.normal = obj.normal; // Normal points "up"
	distance_cap_top = compute_plane_intersection(ray, cap);
	// Intersect with top cap plane
	if (distance_cap_top != NOINTERSECTION)
	{
		hit_position = add_vectors(ray.position, scale_vector(ray.direction, distance_cap_top));
		if (!is_inside_disc(hit_position, cap_top_center, obj.diameter * 0.5))
			distance_cap_top = NOINTERSECTION;
	}

    // Intersect with bottom cap plane
	cap.position = cap_bottom_center;
	cap.normal = flip_vector(obj.normal); // Normal points "down"
	distance_cap_bottom = compute_plane_intersection(ray, cap);
    if (distance_cap_bottom != NOINTERSECTION)
    {
        hit_position = add_vectors(ray.position, scale_vector(ray.direction, distance_cap_bottom));
        if (!is_inside_disc(hit_position, cap_bottom_center, obj.diameter * 0.5))
            distance_cap_bottom = NOINTERSECTION;
    }
	if (distance_cap_bottom < distance_cap_top)
		return (distance_cap_bottom);
	if (distance_cap_top < distance_cap_bottom)
		return (distance_cap_top);
	// (void)ray;
	// (void)obj;
	// return (distance_cap_top);
	return (NOINTERSECTION);
}

t_num compute_cylinder_intersection(t_ray ray, t_obj obj)
{
	t_num	distance_body;
	t_num	distance_cap;

	// obj.normal = normalize(obj.normal);
	// ray.direction = normalize(ray.direction);
	distance_body = compute_cylinder_intersection_body(ray, obj);
	// distance_body = NOINTERSECTION;
	distance_cap = compute_cylinder_intersection_caps(ray, obj);
	if (distance_cap != NOINTERSECTION)
			printf("distance_cap: %f\n", distance_cap);
	if (distance_body < distance_cap)
	{
		// printf("distance_cap: %f\n", distance_cap);
		// printf("distance_body: %f\n", distance_body);
		// sleep(1);
		return (distance_body);
	}
	if (distance_cap < distance_body)
	{
		printf("distance_cap: %f\n", distance_cap);
		return (distance_cap);
	}
	return (NOINTERSECTION);
	// return (distance_cap);

	// return (distance_body);
}
