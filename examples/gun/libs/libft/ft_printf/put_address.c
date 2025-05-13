/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_address.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:24:49 by nteechar          #+#    #+#             */
/*   Updated: 2024/08/28 14:24:48 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	put_address(void *ptr)
{
	unsigned int	length_printed;

	length_printed = 0;
	if (ptr == NULL)
	{
		length_printed += put_str("(nil)");
		return (length_printed);
	}
	length_printed += put_str("0x");
	length_printed += put_hex((size_t) ptr, 0);
	return (length_printed);
}
