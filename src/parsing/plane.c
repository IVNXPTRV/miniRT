/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:14:34 by ipetrov           #+#    #+#             */
/*   Updated: 2025/05/21 12:22:19 by ipetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	parse_plane(char **element, t_scene *scene, int lineno)
{
	verify_max_obj_num(element, scene, lineno);
	verify_attrs_number(element, 3, lineno);
	\
	scene->obj[scene->obj_num].position = get_point(element, 1, lineno);
	scene->obj[scene->obj_num].normal = get_vector(element, 2, lineno);
	scene->obj[scene->obj_num].color = get_color(element, 3, lineno);
	scene->obj[scene->obj_num].type = PL;
	scene->obj_num++;
}
