/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 11:15:21 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/08 15:36:33 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	init_rt(t_rt *rt)
{
	rt->mlx = mlx_init(WIDTH, HEIGHT, "new", false);
	if (!rt->mlx)
	{
		perror("Error initiating mlx\n");
		return (-1);
	}
	rt->img = mlx_new_image(rt->mlx, WIDTH, HEIGHT);
	if (!rt->img)
	{
		mlx_terminate(rt->mlx);
		perror("Error creating image\n");
		return (1);
	}
	return (0);
}

void	key_press(mlx_key_data_t keycode, void *param)
{
	t_rt	*rt;

	rt = (t_rt *) param;
	if (keycode.action == MLX_PRESS || keycode.action == MLX_REPEAT)
	{
		if (keycode.key == 256)
			mlx_close_window(rt->mlx);
	}
}
