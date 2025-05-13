/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_double.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 09:55:02 by nteechar          #+#    #+#             */
/*   Updated: 2025/03/26 17:03:13 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	put_double(double x)
{
	unsigned int	len_put;

	len_put = 0;
	if (x < 0)
	{
		len_put += put_char('-');
		x *= -1;
	}
	len_put += put_int((int) x);
	\
	len_put += put_char('.');
	\
	x = (x - (int) x) * 100;
	len_put += put_int((int) x);
	return (len_put);
}
