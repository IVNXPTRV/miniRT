/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <nteechar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 18:49:15 by nteechar          #+#    #+#             */
/*   Updated: 2025/03/26 09:31:47 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR3_H
# define VECTOR3_H

# include <stdlib.h>
# include <math.h>

typedef struct s_vector3
{
	double	x;
	double	y;
	double	z;
}	t_vector3;

t_vector3	v_create(double x, double y, double z);
t_vector3	*v_set_ip(t_vector3 *dest, double x, double y, double z);

t_vector3	v_copy(const t_vector3 *other);
t_vector3	*v_copy_ip(t_vector3 *dest, const t_vector3 *other);

t_vector3	v_add(const t_vector3 *a, const t_vector3 *b);
t_vector3	*v_add_ip(t_vector3 *dest, const t_vector3 *src);

t_vector3	v_sub(const t_vector3 *a, const t_vector3 *b);
t_vector3	*v_sub_ip(t_vector3 *dest, const t_vector3 *src);

t_vector3	v_scalar_mul(const t_vector3 *v, double scalar);
t_vector3	*v_scalar_mul_ip(t_vector3 *dest, double scalar);

double		v_dot(const t_vector3 *a, const t_vector3 *b);

double		v_norm2(const t_vector3 *v);
double		v_norm(const t_vector3 *v);

double		v_dist2(const t_vector3 *a, const t_vector3 *b);
double		v_dist(const t_vector3 *a, const t_vector3 *b);

t_vector3	v_normalize(const t_vector3 *v);
t_vector3	*v_normalize_ip(t_vector3 *dest);

t_vector3	v_cross(const t_vector3 *a, const t_vector3 *b);

t_vector3	v_proj(const t_vector3 *vec, const t_vector3 *onto);
t_vector3	v_rej(const t_vector3 *vec, const t_vector3 *onto);

void		v_put(const t_vector3 *v);

t_vector3	v_rotate(const t_vector3 *v, const t_vector3 *axis, double theta);

#endif
