/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   offset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:45:40 by ipetrov           #+#    #+#             */
/*   Updated: 2024/12/08 09:53:52 by ipetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_node	offset(t_node n, t_imginf *img)
{
	n.v.v3d.x += img->offset.x;
	n.v.v3d.y += img->offset.y;
	n.v.v3d.x += WIDTH / 2;
	n.v.v3d.y += HEIGHT / 2;
	return (n);
}
