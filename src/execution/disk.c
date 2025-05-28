/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 19:39:48 by ipetrov           #+#    #+#             */
/*   Updated: 2025/05/28 19:40:35 by ipetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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