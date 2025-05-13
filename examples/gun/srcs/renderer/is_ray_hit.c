/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_ray_hit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <nteechar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:49:37 by nteechar          #+#    #+#             */
/*   Updated: 2025/03/26 01:34:59 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/world.h"

static int	is_hit_object(t_object *object, t_ray *ray, t_hit_record *temp_rec)
{
	if (object->type == SPHERE)
		return (hit_sphere(object, ray, temp_rec));
	else if (object->type == PLANE)
		return (hit_plane(object, ray, temp_rec));
	else
		return (hit_cylinder(object, ray, temp_rec));
}

int	is_ray_hit(t_world *world, t_ray *ray, t_hit_record *rec)
{
	t_hit_record	temp_rec;
	double			closest_so_far;
	int				i;

	closest_so_far = INF;
	i = 0;
	while (i < world->nb_objects)
	{
		if (is_hit_object(world->objects[i], ray, &temp_rec))
		{
			if (temp_rec.t < closest_so_far)
			{
				closest_so_far = temp_rec.t;
				hit_record_copy(rec, &temp_rec);
			}
		}
		i++;
	}
	return (closest_so_far < INF);
}
