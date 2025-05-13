/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:39:23 by ipetrov           #+#    #+#             */
/*   Updated: 2024/12/07 10:26:32 by ipetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	boot(t_imginf	*img)
{
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	img->mlx = mlx_init(WIDTH, HEIGHT, "fdf", true);
	if (!img->mlx)
		return (FAIL);
	img->img = mlx_new_image(img->mlx, WIDTH, HEIGHT);
	if (!img->img)
		return (FAIL);
	mlx_image_to_window(img->mlx, img->img, 0, 0);
	update_image(img);
	mlx_key_hook(img->mlx, &keys, img);
	mlx_close_hook(img->mlx, &cross, img);
	mlx_loop(img->mlx);
	ft_exit(img, EXIT_SUCCESS);
	return (SUCCESS);
}
