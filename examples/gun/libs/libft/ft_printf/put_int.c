/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:49:09 by nteechar          #+#    #+#             */
/*   Updated: 2024/08/28 14:25:02 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

#define INT_MIN_STRING "-2147483648"

unsigned int	put_int(int n)
{
	unsigned int	length_printed;

	length_printed = 0;
	if (n == INT_MIN)
	{
		length_printed += put_str(INT_MIN_STRING);
		return (length_printed);
	}
	if (n < 0)
	{
		length_printed += put_char('-');
		n *= -1;
	}
	if (n >= 10)
		length_printed += put_int(n / 10);
	length_printed += put_char(n % 10 + '0');
	return (length_printed);
}
