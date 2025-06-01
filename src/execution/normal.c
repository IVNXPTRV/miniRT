/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 18:56:04 by ipetrov           #+#    #+#             */
/*   Updated: 2025/05/28 19:56:52 by ipetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_vector	get_plane_normal(t_hit hit, t_ray ray)
{
	t_vector	normal;

	if (dot(ray.direction, hit.obj->normal) > 0)
		normal = hit.obj->normal;
	else
		normal = flip_vector(hit.obj->normal);
	return (normal);
}

t_vector	get_disk_normal(t_hit hit, t_ray ray)
{
	t_vector	normal;

	if (dot(ray.direction, hit.obj->normal) > 0)
		normal = hit.obj->normal;
	else
		normal = flip_vector(hit.obj->normal);
	return (normal);
}

t_vector	get_sphere_normal(t_hit hit, t_ray ray)
{
	t_vector	normal;
	t_vector	vec_from_obj_center_to_hit;

	vec_from_obj_center_to_hit = sub_vectors(hit.position, hit.obj->position);
	vec_from_obj_center_to_hit = normalize(vec_from_obj_center_to_hit);
	if (dot(ray.direction, vec_from_obj_center_to_hit) > 0)
		normal = vec_from_obj_center_to_hit;
	else
		normal = flip_vector(vec_from_obj_center_to_hit);
	return (normal);
}

t_vector	get_cylinder_normal(t_hit hit, t_ray ray)
{
	t_vector	normal;
	t_vector	vec_from_obj_center_to_hit;
	t_vector	proj_on_axis;
	t_num		dot_product_axial;

	vec_from_obj_center_to_hit = sub_vectors(hit.position, hit.obj->position);
	dot_product_axial = dot(vec_from_obj_center_to_hit, hit.obj->normal);
	proj_on_axis = scale_vector(hit.obj->normal, dot_product_axial);
	normal = sub_vectors(vec_from_obj_center_to_hit, proj_on_axis);
	normal = normalize(normal);
	if (dot(ray.direction, normal) > 0)
		normal = flip_vector(normal);
	return (flip_vector(normal));
}

t_vector	get_normal(t_hit hit, t_ray ray)
{
	if (hit.obj->type == PL)
		return (get_plane_normal(hit, ray));
	else if (hit.obj->type == SP)
		return (get_sphere_normal(hit, ray));
	else if (hit.obj->type == CY)
		return (get_cylinder_normal(hit, ray));
	else if (hit.obj->type == DS)
		return (get_disk_normal(hit, ray));
	return ((t_vector){0});
}
