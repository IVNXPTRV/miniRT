/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 12:42:28 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/10 18:22:01 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "operation.h"

t_ray	get_ray(int x, int y, t_cam *cam)
{
	double	px;
	double	py;
	t_ray	ray;

	px = (2 * (x + 0.5) / (double)WIDTH - 1) * cam->ratio * cam->scale;
	py = (1 - 2 * (y + 0.5) / (double)HEIGHT) * cam->scale;
	ray.origin = cam->position;
	ray.direction = normalize(add_vectors
			(add_vectors(scale_vector(cam->right, px),
					scale_vector(cam->up, py)), cam->forward));
	ray.intersect = NULL;
	return (ray);
}

t_intersect	*get_closest(t_ray *ray)
{
	t_intersect	*closest;
	t_list		*current;
	t_intersect	*current_intersect;

	closest = NULL;
	current = ray->intersect;
	current_intersect = NULL;
	while (current)
	{
		current_intersect = (t_intersect *)current->content;
		if (!closest || current_intersect->distance < closest->distance)
			closest = current_intersect;
		current = current->next;
	}
	return (closest);
}

int	get_color(int x, int y, t_sc *sc)
{
	t_ray	ray;
	t_color	color;
	t_list	*current;

	current = (t_list *)sc->head;
	ray = get_ray(x, y, &(sc)->cam);
	while (current)
	{
		append_intersect(current->content, &ray);
		current = current->next;
	}
	if (ray.intersect)
	{
		color = calculate_lighting(get_closest(&ray), sc, ray);
		ft_lstclear(&(ray).intersect, free);
	}
	else
		return (0x000000FF);
	return (((int)color.x << 24) | ((int)color.y << 16)
		| (int)color.z << 8 | 0x000000FF);
}

void	render(t_rt *rt, t_sc *sc)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			color = get_color(x, y, sc);
			mlx_put_pixel(rt->img, x, y, color);
			x++;
		}
		y++;
	}
	mlx_image_to_window(rt->mlx, rt->img, 0, 0);
}
