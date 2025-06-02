/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:23:07 by ipetrov           #+#    #+#             */
/*   Updated: 2025/05/28 13:47:29 by ipetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/* else if (mag != 1.0) */
/* { */
/* 	*vector = normalize(*vector); */
/* 	err(lineno, (t_m){"vector is not normalized, magnitude should be 1 -> ", */
/* 		element[i], */
/* 		"\nthis vector is automatically normalized for convinience"}); */
/* } */
static void	verify_vector(char **element, int i, t_scene *s, t_vector *vector)
{
	t_num	mag;

	mag = magnitude(*vector);
	if (mag == 0)
	{
		err(s->lineno, (t_m){"invalid vector -> ", element[i]});
		ft_parrclean(&element);
		er_close(s->file);
		exit(EXIT_FAILURE);
	}
	else if (mag != 1.0)
		*vector = normalize(*vector);
}

t_vector	get_vector(char **element, int i, t_scene *scene)
{
	char		**numbers;
	t_vector	vector;

	numbers = get_numbers(element, i, scene, 3);
	vector.x = get_double(element, numbers, 0, scene);
	vector.y = get_double(element, numbers, 1, scene);
	vector.z = get_double(element, numbers, 2, scene);
	ft_parrclean(&numbers);
	verify_vector(element, i, scene, &vector);
	return (vector);
}
