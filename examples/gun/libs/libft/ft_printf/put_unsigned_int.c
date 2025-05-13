/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_unsigned_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:03:39 by nteechar          #+#    #+#             */
/*   Updated: 2024/08/28 14:25:07 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	put_unsigned_int(unsigned int n)
{
	unsigned int	length_printed;

	length_printed = 0;
	if (n >= 10)
		length_printed += put_unsigned_int(n / 10);
	length_printed += put_char(n % 10 + '0');
	return (length_printed);
}
