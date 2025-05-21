/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:24:29 by ipetrov           #+#    #+#             */
/*   Updated: 2025/05/21 12:39:05 by ipetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// get coordinates of position x, y, z
// element -- whole line
// i -- index of certain attribute of the element
t_point get_point(char **element, int i, int lineno)
{
	char	**numbers;
	t_point	point;

	numbers = get_numbers(element, i, lineno, 3);
	point.x = get_double(element, numbers, 0, lineno);
	point.y = get_double(element, numbers, 1, lineno);
	point.z = get_double(element, numbers, 2, lineno);
	ft_parrclean(numbers);
	return (point);
}
