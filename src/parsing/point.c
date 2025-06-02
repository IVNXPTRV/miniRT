/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:24:29 by ipetrov           #+#    #+#             */
/*   Updated: 2025/05/21 14:44:38 by ipetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_point	get_point(char **element, int i, t_scene *scene)
{
	char	**numbers;
	t_point	point;

	numbers = get_numbers(element, i, scene, 3);
	point.x = get_double(element, numbers, 0, scene);
	point.y = get_double(element, numbers, 1, scene);
	point.z = get_double(element, numbers, 2, scene);
	ft_parrclean(&numbers);
	return (point);
}
