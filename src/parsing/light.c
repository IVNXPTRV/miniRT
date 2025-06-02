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

void	parse_light(char **element, t_scene *scene)
{
	verify_uniqueness(element, &scene->light.status, scene);
	verify_attrs_number(element, 3, scene);
	scene->light.position = get_point(element, 1, scene);
	scene->light.brightness = get_brightness(element, 2, scene);
	scene->light.color = get_color(element, 3, scene);
}
