/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:21:05 by nteechar          #+#    #+#             */
/*   Updated: 2025/03/01 15:38:51 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/color.h"

static void	clip(int *x)
{
	if (*x > 255)
		*x = 255;
}

int	add_color(int color_a, int color_b)
{
	int	r;
	int	g;
	int	b;

	r = get_r(color_a) + get_r(color_b);
	g = get_g(color_a) + get_g(color_b);
	b = get_b(color_a) + get_b(color_b);
	clip(&r);
	clip(&g);
	clip(&b);
	return (get_rgba(r, g, b, 255));
}

int	multiply_color(int color_a, int color_b)
{
	int	r;
	int	g;
	int	b;

	r = (get_r(color_a) * get_r(color_b)) / 255;
	g = (get_g(color_a) * get_g(color_b)) / 255;
	b = (get_b(color_a) * get_b(color_b)) / 255;
	clip(&r);
	clip(&g);
	clip(&b);
	return (get_rgba(r, g, b, 255));
}

// scalar should be in range [0, 1]
int	scale_color(int color, double scalar)
{
	int	r;
	int	g;
	int	b;

	r = get_r(color) * scalar;
	g = get_g(color) * scalar;
	b = get_b(color) * scalar;
	clip(&r);
	clip(&g);
	clip(&b);
	return (get_rgba(r, g, b, 255));
}
