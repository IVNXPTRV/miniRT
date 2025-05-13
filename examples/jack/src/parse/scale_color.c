/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:14:47 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/08 14:15:20 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	scale_color(t_sc *sc)
{
	t_list	*current;
	t_objs	*obj;

	sc->amb.color.x /= 255.0;
	sc->amb.color.y /= 255.0;
	sc->amb.color.z /= 255.0;
	sc->light.color.x /= 255.0;
	sc->light.color.y /= 255.0;
	sc->light.color.z /= 255.0;
	current = (t_list *)sc->head;
	while (current)
	{
		obj = (t_objs *)current->content;
		obj->color.x /= 255.0;
		obj->color.y /= 255.0;
		obj->color.z /= 255.0;
		current = current->next;
	}
}
