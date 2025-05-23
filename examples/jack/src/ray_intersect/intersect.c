/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:41:35 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/04 18:10:15 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	fill_intersect(t_objs *obj, t_ray *ray, double t, t_intersect *new)
{
	t_point	p0l0; // ray_to_obj_center

	// calculate hit_point coordinates
	new->point = add_vectors(ray->origin, scale_vector(ray->direction, t));
	// asign hit_point normal
	if (obj->type == PL)
		new->normal = obj->norm;
	else if (obj->type == SP)
		new->normal = normalize(subtract_vectors(new->point, obj->position));
	else if (obj->type == CY)
	{
		p0l0 = subtract_vectors(new->point, obj->position);
		p0l0.z = 0;
		new->normal = normalize(p0l0);
	}
	new->distance = t;
	// object
	new->solid = (void *) obj;
}

//
void	create_and_add_intersection(t_objs *obj, t_ray *ray,
									t_point local_hit, float t)
{
	t_intersect	*intersect;
	t_point		local_norm;
	t_point		world_norm;
	t_matrix	inverse;

	/* ----- MOVE RAY BACK TO WORLD COORD ---------- */
	//  used to rotate back from local cylinder space to world space.
	inverse = transpose_matrix(generate_rotation_to_z(obj->norm));
	local_norm = normalize((t_point){local_hit.x, local_hit.y, 0});
	world_norm = normalize(apply_rotation(inverse, local_norm));
	/* ----------------------------------------------- */

	intersect = malloc(sizeof(t_intersect));
	if (!intersect)
		return ;
	fill_intersect(obj, ray, t, intersect);
	intersect->normal = world_norm;
	ft_lstadd_back(&(ray->intersect), ft_lstnew((void *)intersect));
}

void	check_cy_intersect(t_quadratic q, t_ray transformed_ray,
							t_objs *obj, t_ray *ray)
{
	t_point		local_hit;

	if (q.t1 > EPSILON)
	{
		// we have same in fill_intersection
		local_hit = add_vectors(transformed_ray.origin,
				scale_vector(transformed_ray.direction, q.t1));

		if (fabs(local_hit.z) <= obj->height / 2)
			create_and_add_intersection(obj, ray, local_hit, q.t1);
	}
	if (q.t2 > EPSILON && !equal(q.t1, q.t2))
	{
		local_hit = add_vectors(transformed_ray.origin,
				scale_vector(transformed_ray.direction, q.t2));
		if (fabs(local_hit.z) <= obj->height / 2)
			create_and_add_intersection(obj, ray, local_hit, q.t2);
	}
}

/*
We transform the ray into the object’s local space, where the cylinder is aligned along the Z-axis, so:
The math becomes MUCH simpler.
You can use a standard intersection formula assuming the cylinder is centered at the origin and points "up" (along Z-axis).
*/
void	append_cylinder(t_objs *obj, t_ray *ray)
{
	t_ray		transformed_ray;
	t_matrix	rotation;
	t_point		translated_origin; // ray_to_obj_center
	t_quadratic	q;

	/* ---- TRANSFORM RAY TO LOCAL COORD ----------*/
	// move cylinder to ray origin
	translated_origin = subtract_vectors(ray->origin, obj->position);
	// rotate ray for simpler math
	rotation = generate_rotation_to_z(obj->norm);
	transformed_ray.origin = apply_rotation(rotation, translated_origin);
	transformed_ray.direction = apply_rotation(rotation, ray->direction);
	/* ----------------------------- */

	// calculate_quadratic to get t -- distance
	calculate_cylinder(obj, transformed_ray, &q);
	if (q.discriminant >= 0)
		check_cy_intersect(q, transformed_ray, obj, ray);

	// check if ray interect caps of cylinder
	add_disk(transformed_ray, obj, ray);
}

void	append_intersect(t_objs *obj, t_ray *ray)
{
	if (obj->type == SP)
		append_sphere(obj, ray);
	if (obj->type == PL)
		append_plane(obj, ray);
	if (obj->type == CY)
		append_cylinder(obj, ray);
}
