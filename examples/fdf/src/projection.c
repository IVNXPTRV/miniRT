/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 12:24:33 by ipetrov           #+#    #+#             */
/*   Updated: 2024/12/07 20:46:42 by ipetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_node	project(t_node n)
{
	double	x;
	double	y;
	double	z;

	x = n.v.v3d.x;
	y = n.v.v3d.y;
	z = n.v.v3d.z;
	n.v.v2d.x = (int)x;
	n.v.v2d.y = (int)y;
	(void)z;
	return (n);
}
