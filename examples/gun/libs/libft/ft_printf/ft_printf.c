/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <nteechar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:15:16 by nteechar          #+#    #+#             */
/*   Updated: 2025/03/26 09:54:25 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	put_variable(char spec, va_list *arg_ptr_address)
{
	if (spec == 'c')
		return (put_char(va_arg(*arg_ptr_address, int)));
	else if (spec == 's')
		return (put_str(va_arg(*arg_ptr_address, char *)));
	else if (spec == 'p')
		return (put_address(va_arg(*arg_ptr_address, void *)));
	else if (spec == 'd' || spec == 'i')
		return (put_int(va_arg(*arg_ptr_address, int)));
	else if (spec == 'u')
		return (put_unsigned_int(va_arg(*arg_ptr_address, unsigned int)));
	else if (spec == 'x')
		return (put_hex(va_arg(*arg_ptr_address, unsigned int), 0));
	else if (spec == 'X')
		return (put_hex(va_arg(*arg_ptr_address, unsigned int), 1));
	else if (spec == '%')
		return (put_char('%'));
	else if (spec == 'f')
		return (put_double(va_arg(*arg_ptr_address, double)));
	return (0);
}

unsigned int	ft_printf(const char *format, ...)
{
	va_list			arg_ptr;
	unsigned int	length_printed;

	va_start(arg_ptr, format);
	length_printed = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				break ;
			length_printed += put_variable(*format, &arg_ptr);
		}
		else
			length_printed += put_char(*format);
		format++;
	}
	va_end(arg_ptr);
	return (length_printed);
}
