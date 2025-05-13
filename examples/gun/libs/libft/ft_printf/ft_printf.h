/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <nteechar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:40:19 by nteechar          #+#    #+#             */
/*   Updated: 2025/03/26 09:54:58 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

unsigned int	ft_printf(const char *format, ...);

unsigned int	put_char(unsigned char c);
unsigned int	put_str(const char *s);
unsigned int	put_address(void *ptr);
unsigned int	put_int(int n);
unsigned int	put_unsigned_int(unsigned int n);
unsigned int	put_hex(size_t n, int put_uppercase);
unsigned int	put_double(double x);

#endif
