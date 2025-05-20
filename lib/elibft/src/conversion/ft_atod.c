/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:39:21 by ipetrov           #+#    #+#             */
/*   Updated: 2025/05/20 19:03:03 by ipetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "elibft.h"
#include "elibft.h"
#include <float.h>

static int get_decimal(const char *str, double *dest, int *sig_digits)
{
    double result;
    double scale;
    const char *s;

	s = str;
	result = 0.0;
	scale = 1;
    if (*s == '\0')
        return (FAIL);
    while (*s >= '0' && *s <= '9')
    {
        if (++(*sig_digits) > DBL_DIG)
            return (FAIL); // too many significant digits
        scale /= 10.0;
        result = result * 10.0 + (*s - '0');
        s++;
    }
    if (*s != '\0')
        return (FAIL);
    *dest = result * scale;
    return (SUCCESS);
}

void	skip(char **s, int *sign)
{
	*sign = 1;
    while (**s == ' ' || (**s >= '\t' && **s <= '\r'))
        (*s)++;
    if (**s == '-' || **s == '+')
    {
        if (**s == '-')
            *sign = -1;
        (*s)++;
    }
    while (**s == '0')
        (*s)++;
}

int integer_part(double *integer,  int *sig_digits, char **s)
{
	*integer = 0.0;
    *sig_digits = 0;
	while (**s >= '0' && **s <= '9')
    {
        if (++(*sig_digits) > DBL_DIG)
            return (FAIL);
        if (*integer > DBL_MAX / 10.0)
            return (FAIL); // overflow
        *integer = *integer * 10.0 + (**s - '0');
        (*s)++;
    }
    if (**s != '\0' && **s != '.')
        return (FAIL);
	return (SUCCESS);
}

int ft_atod(char *str, double *dest)
{
    int sign;
    double integer;
    double decimal;
    int sig_digits;
    char *s;

	s = str;
    *dest = 0.0;
	decimal = 0.0;
	skip(&s, &sign);
	if (integer_part(&integer, &sig_digits, &s) == FAIL)
		return (FAIL);
    if (*s == '.')
    {
        s++;
        if (get_decimal(s, &decimal, &sig_digits) == FAIL)
            return (FAIL);
    }
    if (integer > DBL_MAX - decimal)
        return (FAIL);
    *dest = (integer + decimal) * sign;
    return (SUCCESS);
}
