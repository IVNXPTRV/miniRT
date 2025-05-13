/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:31:06 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/11 18:46:21 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	get_intersects(t_sc *sc, t_ray *ray, double t)
{
	t_list		*current;

	current = (t_list *)sc->head;
	while (current)
	{
		append_intersect(current->content, ray);
		current = current->next;
	}
	if (ray->intersect != NULL)
	{
		if (get_closest(ray)->distance < t)
		{
			ft_lstclear(&(ray)->intersect, free);
			return (1);
		}
		ft_lstclear(&(ray)->intersect, free);
	}
	return (0);
}

int	is_shadowed(t_sc *sc, t_intersect *hit)
{
	t_ray		ray;
	double		t;
	t_light		light;

	light = sc->light;
	ray.origin = hit->point;
	ray.direction = normalize(subtract_vectors(light.position, hit->point));
	ray.origin = add_vectors(ray.origin,
			scale_vector(normalize(ray.direction), 0.01));
	ray.intersect = NULL;
	t = magnitude(subtract_vectors(light.position, hit->point));
	return (get_intersects(sc, &ray, t));
}
