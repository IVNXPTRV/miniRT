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

void	append_plane(t_objs *obj, t_ray *ray)
{
	// denom tells us if the ray is aligned with the plane normal (and if it’s not parallel).
	// denom is the cosine of the angle between the ray and the plane normal, up to a scale factor
	double		denom;
	t_point		p0l0; // ray_to_obj_center
	double		t; // how far go from ray origin
	t_intersect	*intersect;

	denom = dot_product(normalize(obj->norm), ray->direction);
	if (fabs(denom) < EPSILON)
		return ;
	p0l0 = subtract_vectors(obj->position, ray->origin);
	t = dot_product(p0l0, obj->norm) / denom;
	if (t > EPSILON)
	{
		intersect = malloc(sizeof(t_intersect));
		if (!intersect)
			return ;
		fill_intersect(obj, ray, t, intersect);
		ft_lstadd_back(&(ray)->intersect, ft_lstnew((void *)intersect));
	}
}
