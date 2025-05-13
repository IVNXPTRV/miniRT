/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:42:55 by nteechar          #+#    #+#             */
/*   Updated: 2024/08/28 14:25:04 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	put_str(const char *s)
{
	unsigned int	length_printed;

	length_printed = 0;
	if (s == NULL)
	{
		length_printed += put_str("(null)");
		return (length_printed);
	}
	while (*s != '\0')
	{
		length_printed += put_char(*s);
		s++;
	}
	return (length_printed);
}
