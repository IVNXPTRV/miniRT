/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <nteechar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 00:35:00 by nteechar          #+#    #+#             */
/*   Updated: 2025/03/26 09:34:00 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vector3.h"

// Rodrigues's Formula, Courtesy of ChatGPT
// v_rot = v·cosθ + (k × v)·sinθ + k·(k · v)(1 − cosθ)
t_vector3	v_rotate(const t_vector3 *v, const t_vector3 *axis, double theta)
{
	t_vector3	k;
	double		cos_theta;
	double		sin_theta;
	t_vector3	v_rot;
	t_vector3	temp;

	k = v_normalize(axis);
	cos_theta = cos(theta);
	sin_theta = sin(theta);
	\
	v_rot = v_scalar_mul(v, cos_theta);
	\
	temp = v_cross(&k, v);
	v_scalar_mul_ip(&temp, sin_theta);
	v_add_ip(&v_rot, &temp);
	\
	temp = v_copy(&k);
	v_scalar_mul_ip(&temp, v_dot(&k, v) * (1.0 - cos_theta));
	v_add_ip(&v_rot, &temp);
	\
	return (v_rot);
}
