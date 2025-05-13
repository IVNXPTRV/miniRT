/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_record.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <nteechar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 12:50:13 by nteechar          #+#    #+#             */
/*   Updated: 2025/02/22 12:50:21 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HIT_RECORD_H
# define HIT_RECORD_H

# include "vector3.h"

typedef struct s_hit_record
{
	t_vector3	point;
	t_vector3	normal;
	double		t;
	int			color;
}	t_hit_record;

void	hit_record_copy(t_hit_record *dest, const t_hit_record *src);

#endif
