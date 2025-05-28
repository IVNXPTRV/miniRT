/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 11:24:14 by ipetrov           #+#    #+#             */
/*   Updated: 2025/05/28 11:47:23 by ipetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void dbg_print_color(t_color	color)
{
	printf("r: %f / g: %f / b: %f\n", color.r, color.g, color.b);
}

void dbg_print_vector(t_3d	vector)
{
	printf("x: %f / y: %f / z: %f\n", vector.x, vector.y, vector.z);
}

void dbg_print_num(t_num	num)
{
	printf("%f\n", num);
}

void dbg_print_camera(t_camera	camera)
{
	printf("\n----- camera -----\n");
	printf("position:  "), dbg_print_vector(camera.position);
	printf("forward:   "), dbg_print_vector(camera.forward);
	printf("up:        "), dbg_print_vector(camera.up);
	printf("right:     "), dbg_print_vector(camera.right);
	printf("scale:     "), dbg_print_num(camera.scale);
	printf("ratio:     "), dbg_print_num(camera.ratio);
	sleep(2);
}

void dbg_print_ray(t_ray	ray)
{
	printf("\n----- ray -----\n");
	printf("position:  "), dbg_print_vector(ray.position);
	printf("direction: "), dbg_print_vector(ray.direction);
	sleep(2);
}

char *dbg_get_obj_type(t_obj *obj)
{
	if (obj->type == PL)
		return ("plane");
	if (obj->type == SP)
		return ("sphere");
	if (obj->type == CY)
		return ("cylinder");
	return ("");
}

void dbg_print_hit(t_hit	hit)
{
	printf("\n----- hit -----\n");
	if (hit.obj == NULL)
	{
		printf("obj: miss\n");
		return ;
	}
	else
	{
		printf("obj: %s\n", dbg_get_obj_type(hit.obj));
	}
	printf("position:  "), dbg_print_vector(hit.position);
	printf("normal: "), dbg_print_vector(hit.normal);
	sleep(2);
}
