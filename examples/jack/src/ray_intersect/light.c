/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:30:57 by ruzhang           #+#    #+#             */
/*   Updated: 2025/05/19 15:08:25 by ipetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// L -- light
// N -- normal
t_point	reflect(t_point L, t_point N)
{
	return (subtract_vectors(scale_vector(N, (dot_product(L, N) * 2)), L));
}

/*
P: intersection point
eye_vector: P -> ray.origin
				V = normalize(Pcamera - Pintersection);
light_vector: P -> light.position
				L = normalize(light - Pintersection);
surface_normal: N = normalize(Pintersection - Pcenter);
reflection_vector: R = 2 * (L * N) * N - L;
*/
t_hit	calculate_hit_vects(t_intersect *intersect, t_sc *sc, t_ray ray)
{
	t_hit	hit;

	// ??? not used
	hit.eye_vector = normalize(subtract_vectors(ray.origin, intersect->point));
	// used
	hit.light_vector = normalize(subtract_vectors(sc->light.position, intersect->point));
	// used
	hit.surface_normal = intersect->normal;
	// ?? not used
	hit.reflection_vector = reflect(hit.light_vector, hit.surface_normal);
	return (hit);
}

// where is specular??????
t_color	calculate_color(t_colors colors)
{
	t_color	final_color;

	final_color.x = colors.ambient.x + colors.diffuse.x;
	final_color.y = colors.ambient.y + colors.diffuse.y;
	final_color.z = colors.ambient.z + colors.diffuse.z;
	// cap at 1 from 0 to 1
	if (final_color.x > 1)
		final_color.x = 1;
	if (final_color.y > 1)
		final_color.y = 1;
	if (final_color.z > 1)
		final_color.z = 1;
	// convert double to int rgb
	final_color.x *= 255;
	final_color.y *= 255;
	final_color.z *= 255;
	return (final_color);
}

t_color	calculate_lighting(t_intersect *intersect, t_sc *sc, t_ray ray)
{
	t_hit		hit;
	t_objs		*obj;
	t_colors	colors;
	t_color		final_color;

	colors.shadow = is_shadowed(sc, intersect); // get list of hit points if NULL means no shadow
	hit = calculate_hit_vects(intersect, sc, ray);
	obj = (t_objs *)intersect->solid;
	colors.ambient = calculate_ambient_color(&(sc)->amb, obj);
	if (colors.shadow == 0)
		colors.diffuse = calculate_diffuse_color(&sc->light, obj, hit);
	else
		colors.diffuse = (t_color){0, 0, 0};
	final_color = calculate_color(colors);
	return (final_color);
}
