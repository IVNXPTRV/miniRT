/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchompoo <jchompoo@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:37:20 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/10 17:05:05 by jchompoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	calculate_angle(t_point axis)
{
	t_point	z_axis;
	double	dot;
	double	magnitude_axis;
	double	magnitude_z_axis;

	z_axis = (t_point){0, 0, 1};
	dot = dot_product(axis, z_axis);
	magnitude_axis = magnitude(axis);
	magnitude_z_axis = magnitude(z_axis);
	return (acos(dot / (magnitude_axis * magnitude_z_axis)));
}

void	get_rotation(t_point norm, t_rotation *rotation)
{
	rotation->target = (t_point){0, 0, 1};
	rotation->axis = cross_product(norm, rotation->target);
	rotation->angle = acos(dot_product(normalize(norm), rotation->target));
	rotation->sin = sin(rotation->angle);
	rotation->cos = cos(rotation->angle);
	rotation->one_minus_c = 1 - rotation->cos;
}

void	calculate_cylinder(t_objs *obj, t_ray ray, t_quadratic *q)
{
	q->a = pow(ray.direction.x, 2) + pow(ray.direction.y, 2);
	q->b = 2 * (ray.direction.x
			* ray.origin.x + ray.direction.y * ray.origin.y);
	q->c = pow(ray.origin.x, 2)
		+ pow(ray.origin.y, 2) - pow(obj->diameter / 2, 2);
	q->discriminant = pow(q->b, 2) - 4 * q->a * q->c;
	if (q->discriminant >= 0)
	{
		q->t1 = (-q->b - sqrt(q->discriminant)) / (2 * q->a);
		q->t2 = (-q->b + sqrt(q->discriminant)) / (2 * q->a);
	}
}

int	intersect_disk(t_ray *ray, t_cap *cap, double radius)
{
	double	denom;
	double	t;
	t_point	p;

	denom = dot_product(ray->direction, cap->cap_normal);
	if (fabs(denom) < EPSILON)
		return (0);
	t = dot_product(subtract_vectors(cap->cap_center, ray->origin),
			cap->cap_normal) / denom;
	if (t < EPSILON)
		return (0);
	p = add_vectors(ray->origin, scale_vector(ray->direction, t));
	if (magnitude(subtract_vectors(p, cap->cap_center)) <= radius)
	{
		cap->cap = t;
		return (1);
	}
	return (0);
}

void	add_disk(t_ray transformed_ray, t_objs *obj, t_ray *ray)
{
	t_cap		cap;
	t_intersect	*intersect;

	cap.cap_center = (t_point){0, 0, -obj->height / 2};
	cap.cap_normal = (t_point){0, 0, -1};
	if (intersect_disk(&transformed_ray, &cap, obj->diameter / 2))
	{
		intersect = malloc(sizeof(t_intersect));
		if (!intersect)
			return ;
		fill_intersect(obj, ray, cap.cap, intersect);
		ft_lstadd_back(&(ray->intersect), ft_lstnew((void *)intersect));
	}
	cap.cap_center = (t_point){0, 0, obj->height / 2};
	cap.cap_normal = (t_point){0, 0, 1};
	if (intersect_disk(&transformed_ray, &cap, obj->diameter / 2))
	{
		intersect = malloc(sizeof(t_intersect));
		if (!intersect)
			return ;
		fill_intersect(obj, ray, cap.cap, intersect);
		ft_lstadd_back(&(ray->intersect), ft_lstnew((void *)intersect));
	}
}
