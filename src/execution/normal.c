/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
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

void	init_shadow_ray(t_light light, t_ray *ray, t_hit hit)
{
	ray->position = hit.position;
	ray->direction = normalize(sub_vectors(light.position, hit.position));
}

t_num	get_intensity(t_vector direction, t_vector normal)
{
	return (fabs(dot(direction, normal)));
}

t_color	get_diffuse(t_scene *scene, t_hit hit)
{
	t_num	intensity;
	t_ray	ray;
	t_color	diffuse;

	init_shadow_ray(scene->light, &ray, hit);
	hit.normal = get_normal(hit, ray);
	ray.position = add_vectors(ray.position, scale_vector(hit.normal, OFFSET));
	if (is_shadowed(scene, ray))
		return ((t_color){0});
	intensity = get_intensity(ray.direction, hit.normal);
	diffuse.r = scene->light.brightness * intensity * hit.obj->color.r;
	diffuse.g = scene->light.brightness * intensity * hit.obj->color.g;
	diffuse.b = scene->light.brightness * intensity * hit.obj->color.b;
	return (diffuse);
}

t_color	get_ambient(t_scene *scene, t_hit hit)
{
	t_color	ambient;

	ambient.r = scene->ambient.brightness * scene->ambient.color.r
		* hit.obj->color.r;
	ambient.g = scene->ambient.brightness * scene->ambient.color.g
		* hit.obj->color.g;
	ambient.b = scene->ambient.brightness * scene->ambient.color.b
		* hit.obj->color.b;
	return (ambient);
}

t_color	cap_color(t_color pixel)
{
	if (pixel.r > 1)
		pixel.r = 1;
	if (pixel.g > 1)
		pixel.g = 1;
	if (pixel.b > 1)
		pixel.b = 1;
	return (pixel);
}
t_color	sum_light(t_color ambient, t_color diffuse)
{
	t_color	pixel;

	pixel.r = ambient.r + diffuse.r;
	pixel.g = ambient.g + diffuse.g;
	pixel.b = ambient.b + diffuse.b;
	pixel = cap_color(pixel);
	return (pixel);
}

t_color	add_light(t_scene *scene, t_hit hit)
{
	t_color	pixel;
	t_color	ambient;
	t_color	diffuse;

	ambient = get_ambient(scene, hit);
	diffuse = get_diffuse(scene, hit);
	pixel = sum_light(ambient, diffuse);
	return (pixel);
}
