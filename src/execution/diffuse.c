/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diffuse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 18:56:04 by ipetrov           #+#    #+#             */
/*   Updated: 2025/05/28 19:56:52 by ipetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	init_shadow_ray(t_light light, t_ray *ray, t_hit hit)
{
	ray->position = hit.position;
	ray->direction = normalize(sub_vectors(light.position, hit.position));
}

static t_num	get_intensity(t_vector direction, t_vector normal)
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
