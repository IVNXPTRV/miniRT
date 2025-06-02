/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:25:36 by ipetrov           #+#    #+#             */
/*   Updated: 2025/05/21 09:39:08 by ipetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	verify_color(char **element, int i, t_scene *s, t_color color)
{
	if (!is_in_range(color.r, 0, 1) || !is_in_range(color.g, 0, 1)
		|| !is_in_range(color.b, 0, 1))
	{
		err(s->lineno, (t_m){"color is beyond 0 to 255 range -> ", element[i]});
		ft_parrclean(&element);
		er_close(s->file);
		exit(EXIT_FAILURE);
	}
}

t_color	get_color(char **element, int i, t_scene *scene)
{
	char	**numbers;
	t_color	color;

	numbers = get_numbers(element, i, scene, 3);
	color.r = get_int(element, numbers, 0, scene) / 255.0;
	color.g = get_int(element, numbers, 1, scene) / 255.0;
	color.b = get_int(element, numbers, 2, scene) / 255.0;
	ft_parrclean(&numbers);
	verify_color(element, i, scene, color);
	return (color);
}
