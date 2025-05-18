/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 19:55:54 by ipetrov           #+#    #+#             */
/*   Updated: 2025/05/18 13:10:39 by ipetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#define WIDTH 800
#define HEIGHT 600

int	main(int argc, char **argv)
{
	mlx_t *mlx;
	mlx_image_t *img;
	(void)argc;
	(void)argv;

	// init connection to window management of OS
	mlx = mlx_init(800, 600, "playground", true);
	// create image/buffer for pixels
	img = mlx_new_image(mlx, 800, 600);
	// attach image to window
	mlx_image_to_window(mlx, img, 0, 0);

	int	total;
	int	c;

	c = 0;
	total = WIDTH * HEIGHT;
	while (c < total)
	{
		mlx_put_pixel(img, c % WIDTH, c / WIDTH, 0xFFFFFFFF); // piexl RGBA, A == 0xFF maximum of intransparancy
		c++;
	}
	// make it run
	mlx_loop(mlx);
}
