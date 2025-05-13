/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:08:59 by nteechar          #+#    #+#             */
/*   Updated: 2025/02/10 16:08:59 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vector3.h"

double	v_norm2(const t_vector3 *v)
{
	return (v_dot(v, v));
}

double	v_norm(const t_vector3 *v)
{
	return (sqrt(v_norm2(v)));
}
