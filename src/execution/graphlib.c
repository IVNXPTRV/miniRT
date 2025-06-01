/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphlib.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 17:21:54 by ipetrov           #+#    #+#             */
/*   Updated: 2025/05/21 19:08:00 by ipetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	key_press(mlx_key_data_t keycode, void *param)
{
	t_scene	*scene;

	scene = (t_scene *)param;
	if (keycode.action == MLX_PRESS || keycode.action == MLX_REPEAT)
	{
		if (keycode.key == 256)
			mlx_close_window(scene->gl.window);
	}
}

static void	init_window(t_scene *scene)
{
	scene->gl.window = mlx_init(WIDTH, HEIGHT, "miniRT", false);
	if (scene->gl.window == NULL)
	{
		err(Z, (t_m){"minirt: failed to connect to a graphic library"});
		exit(EXIT_FAILURE);
	}
}

static void	init_image(t_scene *scene)
{
	scene->gl.image = mlx_new_image(scene->gl.window, WIDTH, HEIGHT);
	if (scene->gl.image == NULL)
	{
		mlx_terminate(scene->gl.window);
		err(Z, (t_m){"minirt: failed to created image in a a graphic library"});
		exit(EXIT_FAILURE);
	}
}

static void	register_hooks(t_scene *scene)
{
	mlx_key_hook(scene->gl.window, &key_press, scene);
}

void	init_graphic_library(t_scene *scene)
{
	init_window(scene);
	init_image(scene);
	register_hooks(scene);
}
