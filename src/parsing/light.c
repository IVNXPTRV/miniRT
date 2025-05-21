/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:14:34 by ipetrov           #+#    #+#             */
/*   Updated: 2025/05/21 12:28:25 by ipetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void parse_light(char **element, t_scene *scene, int lineno)
{
	static bool singleton;

	verify_uniqueness(element, &singleton, lineno);
	verify_attrs_number(element, 3, lineno);
	\
	scene->light.position = get_point(element, 1, lineno);
	scene->light.brightness = get_brightness(element, 2, lineno);
	scene->light.color = get_color(element, 3, lineno);
}
