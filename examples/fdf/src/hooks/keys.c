/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:16:32 by ipetrov           #+#    #+#             */
/*   Updated: 2024/12/08 10:32:31 by ipetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	projection_and_rotaton(mlx_key_data_t k, t_imginf *img)
{
	if (k.key == MLX_KEY_P && k.action == MLX_PRESS)
	{
		img->rotation.x = 90;
		img->rotation.y = 0;
		img->rotation.z = 0;
	}
	if (k.key == MLX_KEY_I && k.action == MLX_PRESS)
	{
		img->rotation.x = 90 + 35.264 - 6;
		img->rotation.y = 0;
		img->rotation.z = 45;
	}
	if (k.key == MLX_KEY_LEFT && k.action == MLX_REPEAT)
		img->rotation.z += 1;
	if (k.key == MLX_KEY_RIGHT && k.action == MLX_REPEAT)
		img->rotation.z -= 1;
	if (k.key == MLX_KEY_UP && k.action == MLX_REPEAT)
		img->rotation.x += 1;
	if (k.key == MLX_KEY_DOWN && k.action == MLX_REPEAT)
		img->rotation.x -= 1;
	if (k.key == MLX_KEY_E && k.action == MLX_REPEAT)
		img->rotation.y += 1;
	if (k.key == MLX_KEY_Q && k.action == MLX_REPEAT)
		img->rotation.y -= 1;
}

static void	translation_and_scaling(mlx_key_data_t k, t_imginf *img)
{
	if (k.key == MLX_KEY_W && (k.action == MLX_REPEAT || k.action == MLX_PRESS))
		img->offset.y -= 10;
	if (k.key == MLX_KEY_S && (k.action == MLX_REPEAT || k.action == MLX_PRESS))
		img->offset.y += 10;
	if (k.key == MLX_KEY_D && (k.action == MLX_REPEAT || k.action == MLX_PRESS))
		img->offset.x += 10;
	if (k.key == MLX_KEY_A && (k.action == MLX_REPEAT || k.action == MLX_PRESS))
		img->offset.x -= 10;
	if (k.key == MLX_KEY_MINUS && (k.action == MLX_REPEAT || \
	k.action == MLX_PRESS))
		img->scale -= 0.2;
	if (k.key == MLX_KEY_EQUAL && (k.action == MLX_REPEAT || \
	k.action == MLX_PRESS))
		img->scale += 0.2;
}

static void	color(mlx_key_data_t k, t_imginf *img)
{
	int	c;
	int	total;

	total = ((t_imginf *)img)->height * ((t_imginf *)img)->width;
	if (k.key == MLX_KEY_R && (k.action == MLX_REPEAT || k.action == MLX_PRESS))
	{
		c = -1;
		while (++c < total)
			img->map[c / img->width][c % img->width].color.r += 5;
	}
	if (k.key == MLX_KEY_G && (k.action == MLX_REPEAT || k.action == MLX_PRESS))
	{
		c = -1;
		while (++c < total)
			img->map[c / img->width][c % img->width].color.g += 5;
	}
	if (k.key == MLX_KEY_B && (k.action == MLX_REPEAT || k.action == MLX_PRESS))
	{
		c = -1;
		while (++c < total)
			img->map[c / img->width][c % img->width].color.b += 5;
	}
}

void	keys(mlx_key_data_t k, void *param)
{
	t_imginf	*img;

	img = (t_imginf *)param;
	translation_and_scaling(k, img);
	projection_and_rotaton(k, img);
	color(k, img);
	update_image(img);
	if (k.key == MLX_KEY_ESCAPE && k.action == MLX_PRESS)
	{
		mlx_close_window(img->mlx);
		return ;
	}
}
