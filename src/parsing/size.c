/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:25:59 by ipetrov           #+#    #+#             */
/*   Updated: 2025/05/21 14:44:17 by ipetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_num	get_size(char **element, int i, t_scene *scene)
{
	char	**numbers;
	t_num	diameter;

	numbers = get_numbers(element, i, scene, 1);
	diameter = get_double(element, numbers, 0, scene);
	ft_parrclean(&numbers);
	return (diameter);
}
