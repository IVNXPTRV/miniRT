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

t_num	get_size(char **element, int i, int lineno)
{
	char		**numbers;
	t_num		diameter;

	numbers = get_numbers(element, i, lineno, 1);
	diameter = get_double(element, numbers, 0, lineno);
	ft_parrclean(&numbers);
	return (diameter);
}

