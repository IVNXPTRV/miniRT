/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:12:52 by ipetrov           #+#    #+#             */
/*   Updated: 2025/05/21 17:43:58 by ipetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	execute(t_scene *scene)
{
	init_graphic_library(scene);
	compute_image(scene);
	display_image(scene);
}
