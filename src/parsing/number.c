/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:27:14 by ipetrov           #+#    #+#             */
/*   Updated: 2025/05/21 09:35:24 by ipetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

inline bool	is_in_range(double num, double min, double max)
{
	return (num >= min && num <= max);
}

double	get_double(char **element, char **numbers, int i, int lineno)
{
	double	result;

	result = 0;
	if (ft_atod(numbers[i], &result) == FAIL)
	{
		err(lineno, (t_m){"incorrect double -> ", numbers[i]});
		ft_parrclean(&element);
		ft_parrclean(&numbers);
		exit(EXIT_SUCCESS);
	}
	return (result);
}

int	get_int(char **element, char **numbers, int i, int lineno)
{
	int	result;

	result = 0;
	if (ft_atoi(numbers[i], &result, sizeof(int), 10) == FAIL)
	{
		err(lineno, (t_m){"incorrect integer -> ", numbers[i]});
		ft_parrclean(&element);
		ft_parrclean(&numbers);
		exit(EXIT_SUCCESS);
	}
	return (result);
}
