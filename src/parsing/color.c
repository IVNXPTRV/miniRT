/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:25:36 by ipetrov           #+#    #+#             */
/*   Updated: 2025/05/21 12:30:23 by ipetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void verify_color(char **element, int i, int lineno, t_color color)
{
	if (!is_in_range(color.r, 0, 1) || \
		!is_in_range(color.g, 0, 1) || \
		!is_in_range(color.b, 0, 1))
	{
		err(lineno, (t_m){element[i], "is beyond 0 to 255 range"});
		ft_parrclean(element);
		exit(EXIT_FAILURE);
	}
}

t_color	get_color(char **element, int i, int lineno)
{
	char		**numbers;
	t_color		color;

	numbers = get_numbers(element, i, lineno, 3);
	color.r = get_int(element, numbers, 0, lineno) / 255.0;				// converted to 0.0 to 1.0 representation
	color.g = get_int(element, numbers, 1, lineno) / 255.0;
	color.b = get_int(element, numbers, 2, lineno) / 255.0;
	ft_parrclean(numbers);
	verify_color(element, i, lineno, color);
}
