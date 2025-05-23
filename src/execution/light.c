/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 18:56:04 by ipetrov           #+#    #+#             */
/*   Updated: 2025/05/23 19:38:20 by ipetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_vector get_plane_normal(t_hit hit, t_ray ray)
{
	t_vector normal;

	if (dot(ray.direction, hit.obj->normal) > 0)
		normal = hit.obj->normal;
	else
		normal == flip(hit.obj->normal);
	return (hit.obj->normal);
}

t_vector get_normal(t_hit hit, t_ray ray)
{
	if (hit.obj->type == PL)
		return (get_plane_normal(hit, ray));
	else if (hit.obj->type == SP)
		return (get_sphere_normal(hit, ray));
	else if (hit.obj->type == CY)
		return (get_cylinder_normal(hit, ray));
}

void init_shadow_ray(t_light light, t_ray *ray, t_hit hit)
{
	ray->position = hit.position;
	ray->direction = normalaize(sub_vectors(light.position, hit.position));
	ray->position = add_vectors(ray->position, scale_vector(ray->direction, OFFSET));
}

t_num get_intensity(t_vector direction, t_vector normal)
{
	return (fabs(dot(direction, normal)));
}
t_num	get_diffuse(t_scene *scene, t_hit hit)
{
	t_num intensity;
	t_ray ray;

	init_shadow_ray(scene->light, &ray, hit);
	if (is_shadowed(scene, hit))
		return (0);
	hit.normal = get_normal(hit, ray);		// get for light calculation later, or calculater later in a shadow??
	intensity = get_intensity(ray.direction, hit.normal);
	return (intensity * scene->light.brightness);
}

// returns some cooeficient
t_num get_light(t_scene *scene, t_hit hit)
{
	t_num diffuse;
	t_num ambient;

	diffuse = get_diffuse(scene, hit);
	ambient = get_ambient(scene);
	return (diffuse + ambient);
}
