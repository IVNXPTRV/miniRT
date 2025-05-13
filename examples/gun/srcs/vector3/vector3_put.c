/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3_put.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <nteechar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 00:35:00 by nteechar          #+#    #+#             */
/*   Updated: 2025/03/26 09:50:10 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../libs/libft/libft.h"
#include "../../includes/vector3.h"

void	v_put(const t_vector3 *v)
{
	ft_printf("%f,%f,%f", v->x, v->y, v->z);
}
