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

// attach image to window
static void attach_image(t_scene *s)
{
	if (mlx_image_to_window(s->gl.window, s->gl.image, 0, 0) == ERROR)
	{
		mlx_terminate(s->gl.window);
		err(Z, (t_m){"minirt: failed to attach image to window in a graphic library"});
		exit(EXIT_FAILURE);
	}
}

void display_image(t_scene *scene)
{
	attach_image(scene);
	mlx_loop(scene->gl.window);						// display OS window woth image inside
	mlx_terminate(scene->gl.window);				// clean connection of gl
	exit(EXIT_SUCCESS);								// intended final exit from a program
}
