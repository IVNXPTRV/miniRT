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

void execute(t_scene *scene)
{
	init_graphic_library(scene);	// connect to gl and prepare an image and register hooks
	compute_image(scene);			// fill all final pixels color
	display_image(scene);			// render an image in an OS window
}
