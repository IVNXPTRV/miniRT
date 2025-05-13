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

void	calculate_quadratic(t_objs *obj, t_ray ray, t_quadratic *q)
{
	t_point	sphere_to_ray;

	sphere_to_ray = subtract_vectors(ray.origin, obj->position);
	q->a = dot_product(ray.direction, ray.direction);
	q->b = 2 * dot_product(ray.direction, sphere_to_ray);
	q->c = dot_product(sphere_to_ray, sphere_to_ray)
		- pow(obj->diameter / 2, 2);
	q->discriminant = pow(q->b, 2) - 4 * q->a * q->c;
	if (q->discriminant >= 0)
	{
		q->t1 = (-q->b - sqrt(q->discriminant)) / (2 * q->a);
		q->t2 = (-q->b + sqrt(q->discriminant)) / (2 * q->a);
	}
}

void	append_sphere(t_objs *obj, t_ray *ray)
{
	t_intersect	*intersect;
	t_intersect	*intersect2;
	t_quadratic	q;

	calculate_quadratic(obj, *ray, &q);
	if (q.discriminant < 0)
		return ;
	if (q.t1 > EPSILON)
	{
		intersect = malloc(sizeof(t_intersect));
		if (!intersect)
			return ;
		fill_intersect(obj, ray, q.t1, intersect);
		ft_lstadd_back(&(ray)->intersect, ft_lstnew((void *)intersect));
	}
	if (q.t2 > EPSILON && !equal(q.t2, q.t1))
	{
		intersect2 = malloc(sizeof(t_intersect));
		if (!intersect2)
			return ;
		fill_intersect(obj, ray, q.t2, intersect2);
		ft_lstadd_back(&(ray)->intersect, ft_lstnew((void *)intersect2));
	}
}
