/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 18:10:35 by ipetrov           #+#    #+#             */
/*   Updated: 2025/05/21 19:14:19 by ipetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void get_hit(t_scene *scene, t_ray ray, t_hit *hit)
{
	int		i;
	t_num	t;

	i = 0;
	while(i < scene->obj_num)							// loop to traverse all scene objects
	{
		if (scene->obj[i].type == PL)
			t = compute_plane_intersection();
		else if (scene->obj[i].type == SP)
			t = compute_sphere_intersection();
		else if (scene->obj[i].type == CY)
			t = compute_cylinder_intersection();
	}
}
