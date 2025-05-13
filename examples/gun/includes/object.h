/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <nteechar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 12:50:37 by nteechar          #+#    #+#             */
/*   Updated: 2025/03/26 00:53:51 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "ray.h"
# include "hit_record.h"
# include "constants.h"

typedef enum e_object_type
{
	SPHERE,
	PLANE,
	CYLINDER,
}	t_object_type;

typedef struct s_object
{
	t_object_type	type;
	t_vector3		point;
	int				color;
	t_vector3		normal;
	double			radius;
	double			height;
}	t_object;

int	hit_sphere(t_object *sphere, const t_ray *ray, t_hit_record *rec);
int	hit_plane(t_object *plane, const t_ray *ray, t_hit_record *rec);
int	hit_cylinder(t_object *cylinder, const t_ray *ray, t_hit_record *rec);

#endif
