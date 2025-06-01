/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 18:56:04 by ipetrov           #+#    #+#             */
/*   Updated: 2025/05/28 19:56:52 by ipetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_color	get_ambient(t_scene *scene, t_hit hit)
{
	t_color	ambient;

	ambient.r = scene->ambient.brightness * scene->ambient.color.r
		* hit.obj->color.r;
	ambient.g = scene->ambient.brightness * scene->ambient.color.g
		* hit.obj->color.g;
	ambient.b = scene->ambient.brightness * scene->ambient.color.b
		* hit.obj->color.b;
	return (ambient);
}
