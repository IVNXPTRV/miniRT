/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_in_range.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <nteechar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 22:38:47 by nteechar          #+#    #+#             */
/*   Updated: 2025/03/25 22:38:56 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/parser.h"

int	is_in_range(int min, int max, int x)
{
	return (min <= x && x <= max);
}

int	is_in_rangef(double min, double max, double x)
{
	return (min <= x && x <= max);
}
