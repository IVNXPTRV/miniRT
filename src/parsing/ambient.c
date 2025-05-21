/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:14:34 by ipetrov           #+#    #+#             */
/*   Updated: 2025/05/21 09:28:35 by ipetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void parse_ambient(char **element, t_scene *scene, int lineno)
{
	verify_uniqueness(element, &scene->ambient.status, lineno);
	verify_attrs_number(element, 2, lineno);
	\
	scene->ambient.brightness = get_brightness(element, 1, lineno);
	scene->ambient.color = get_color(element, 2, lineno);
}
