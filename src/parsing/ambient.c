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

void	parse_ambient(char **element, t_scene *scene)
{
	verify_uniqueness(element, &scene->ambient.status, scene);
	verify_attrs_number(element, 2, scene);
	scene->ambient.brightness = get_brightness(element, 1, scene);
	scene->ambient.color = get_color(element, 2, scene);
}
