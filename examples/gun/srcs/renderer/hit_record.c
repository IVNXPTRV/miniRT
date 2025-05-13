/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_record.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <nteechar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 11:24:39 by nteechar          #+#    #+#             */
/*   Updated: 2025/02/22 11:29:42 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/hit_record.h"

void	hit_record_copy(t_hit_record *dest, const t_hit_record *src)
{
	dest->color = src->color;
	dest->normal = v_copy(&src->normal);
	dest->point = v_copy(&src->point);
	dest->t = src->t;
}
