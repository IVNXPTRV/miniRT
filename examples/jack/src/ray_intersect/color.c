/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:31:06 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/11 18:39:58 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	calculate_ambient_color(t_amb *light, t_objs *obj)
{
	t_point	amb_color;

	amb_color.x = light->ratio * light->color.x * obj->color.x;
	amb_color.y = light->ratio * light->color.y * obj->color.y;
	amb_color.z = light->ratio * light->color.z * obj->color.z;
	return (amb_color);
}

t_color	calculate_diffuse_color(t_light *light, t_objs *obj, t_hit hit)
{
	t_point	diffuse_color;
	double	diffuse_intensity;

	if (obj->type == PL)
		diffuse_intensity = fabs(dot_product
				(hit.light_vector, hit.surface_normal));
	else
		diffuse_intensity = fmax(0.0, dot_product
				(hit.light_vector, hit.surface_normal));
	diffuse_color.x = light->ratio * light->color.x
		* obj->color.x * diffuse_intensity;
	diffuse_color.y = light->ratio * light->color.y
		* obj->color.y * diffuse_intensity;
	diffuse_color.z = light->ratio * light->color.z
		* obj->color.z * diffuse_intensity;
	return (diffuse_color);
}

// t_color	calculate_specular(t_light *light, t_objs *obj, t_hit hit)
// {
// 	t_color	specular_color;
// 	double	specular_intensity;
// 	t_color	specular;

// 	specular = (t_point){1, 1, 1};
// 	specular_intensity = pow(fmax(0.0, dot_product(hit.reflection_vector,
// 					hit.eye_vector)), shininess);
// 	specular_color = scale_vector(specular, light->ratio * specular_intensity);
// }
