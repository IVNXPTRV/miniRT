/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:14:34 by ipetrov           #+#    #+#             */
/*   Updated: 2025/05/21 09:28:21 by ipetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	parse_light(char **element, t_scene *scene, int lineno)
{
	verify_uniqueness(element, &scene->light.status, lineno);
	verify_attrs_number(element, 3, lineno);
	scene->light.position = get_point(element, 1, lineno);
	scene->light.brightness = get_brightness(element, 2, lineno);
	scene->light.color = get_color(element, 3, lineno);
}
