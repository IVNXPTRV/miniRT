/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brightness.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:26:49 by ipetrov           #+#    #+#             */
/*   Updated: 2025/05/21 14:44:11 by ipetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	verify_brightness(char **element, int i, t_scene *s,
		t_num brightness)
{
	if (!is_in_range(brightness, 0, 1))
	{
		err(s->lineno, (t_m){"value is beyond 0 to 1 range -> ", element[i]});
		ft_parrclean(&element);
		er_close(s->file);
		exit(EXIT_FAILURE);
	}
}

t_num	get_brightness(char **element, int i, t_scene *scene)
{
	char	**numbers;
	t_num	brightness;

	numbers = get_numbers(element, i, scene, 1);
	brightness = get_double(element, numbers, 0, scene);
	ft_parrclean(&numbers);
	verify_brightness(element, i, scene, brightness);
	return (brightness);
}
