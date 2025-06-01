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

static void	verify_brightness(char **element, int i, int lineno,
		t_num brightness)
{
	if (!is_in_range(brightness, 0, 1))
	{
	}
}

t_num	get_brightness(t_scene *scene, char **element, int i, int lineno)
{
	char	**numbers;
	t_num	brightness;

	numbers = get_numbers(scene, element, i, lineno, 1);
//	brightness = get_double(element, numbers, 0, lineno);
	ft_parrclean(&numbers);
	if (verify_brightness(element, i, lineno, brightness) == FAIL)
	{
		err(lineno, (t_m){"brightness is beyond 0 to 1 range ->", element[i]});
		ft_parrclean(&element);
		er_close(scene->file);
		exit(EXIT_FAILURE);
	}
	return (brightness);
}
