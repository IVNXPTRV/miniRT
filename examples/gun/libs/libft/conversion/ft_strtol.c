/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykai-yua <ykai-yua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:54:21 by ykai-yua          #+#    #+#             */
/*   Updated: 2025/03/12 18:14:40 by ykai-yua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>

static int	parse_sign(const char **str)
{
	int	sign;

	sign = 1;
	if (**str == '-')
	{
		sign = -1;
		(*str)++;
	}
	else if (**str == '+')
		(*str)++;
	return (sign);
}

static int	convert_digit(char c)
{
	if (c == ',')
		return (-10);
	if (c >= '0' && c <= '9')
		return (c - '0');
	return (-1);
}

static long	convert_to_long(const char *str, int *i)
{
	long	result;
	int		digit;

	result = 0;
	while (str[*i] != '\0')
	{
		digit = convert_digit(str[*i]);
		if (digit == -10)
			break ;
		if (digit == -1)
		{
			result = -1;
			break ;
		}
		if (result > (LONG_MAX - digit) / 10)
		{
			result = LONG_MAX;
			break ;
		}
		result = result * 10 + digit;
		(*i)++;
	}
	return (result);
}

long	ft_strtol(const char *str, char **endptr)
{
	long	result;
	int		sign;
	int		i;

	sign = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	sign = parse_sign(&str + i);
	result = convert_to_long(str, &i);
	if (result == -1)
		sign = 1;
	if (endptr)
		*endptr = (char *)&str[i];
	return (result * sign);
}
