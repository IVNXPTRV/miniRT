/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 17:35:12 by ipetrov           #+#    #+#             */
/*   Updated: 2025/05/21 17:42:03 by ipetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	attach_image(t_scene *s)
{
	if (mlx_image_to_window(s->gl.window, s->gl.image, 0, 0) == ERROR)
	{
		mlx_terminate(s->gl.window);
		err(Z,
			(t_m){"minirt: failed to attach image to window in a graph lib"});
		exit(EXIT_FAILURE);
	}
}

void	display_image(t_scene *scene)
{
	attach_image(scene);
	mlx_loop(scene->gl.window);
	mlx_terminate(scene->gl.window);
	exit(EXIT_SUCCESS);
}
