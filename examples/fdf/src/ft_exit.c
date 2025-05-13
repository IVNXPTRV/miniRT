/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:40:27 by ipetrov           #+#    #+#             */
/*   Updated: 2024/12/07 12:22:30 by ipetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_exit(t_imginf *img, int code)
{
	int	c;

	mlx_terminate(img->mlx);
	c = 0;
	while (c < img->height)
	{
		free(img->map[c]);
		c++;
	}
	free(img->map);
	free(img);
	exit(code);
}
