/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:14:34 by ipetrov           #+#    #+#             */
/*   Updated: 2025/05/28 19:53:47 by ipetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	add_disks(char **element, t_scene *scene, t_obj cylinder)
{
	scene->obj_num++;
	verify_max_obj_num(element, scene);
	scene->obj[scene->obj_num].position = add_vectors(cylinder.position,
			scale_vector(cylinder.normal, cylinder.height * 0.5));
	scene->obj[scene->obj_num].normal = cylinder.normal;
	scene->obj[scene->obj_num].diameter = cylinder.diameter;
	scene->obj[scene->obj_num].color = cylinder.color;
	scene->obj[scene->obj_num].type = DS;
	scene->obj_num++;
	verify_max_obj_num(element, scene);
	scene->obj[scene->obj_num].position = sub_vectors(cylinder.position,
			scale_vector(cylinder.normal, cylinder.height * 0.5));
	scene->obj[scene->obj_num].normal = flip_vector(cylinder.normal);
	scene->obj[scene->obj_num].diameter = cylinder.diameter;
	scene->obj[scene->obj_num].color = cylinder.color;
	scene->obj[scene->obj_num].type = DS;
}

void	parse_cylinder(char **element, t_scene *scene)
{
	verify_max_obj_num(element, scene);
	verify_attrs_number(element, 5, scene);
	scene->obj[scene->obj_num].position = get_point(element, 1, scene);
	scene->obj[scene->obj_num].normal = get_vector(element, 2, scene);
	scene->obj[scene->obj_num].diameter = get_size(element, 3, scene);
	scene->obj[scene->obj_num].height = get_size(element, 4, scene);
	scene->obj[scene->obj_num].color = get_color(element, 5, scene);
	scene->obj[scene->obj_num].type = CY;
	add_disks(element, scene, scene->obj[scene->obj_num]);
	scene->obj_num++;
}
