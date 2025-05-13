/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykai-yua <ykai-yua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:42:27 by nteechar          #+#    #+#             */
/*   Updated: 2025/03/12 19:14:57 by ykai-yua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c);

static short	get_sign(const char **nptr)
{
	short	sign;

	sign = 1;
	if (**nptr == '-')
		sign = -1;
	if (**nptr == '+' || **nptr == '-')
		(*nptr)++;
	return (sign);
}

static double	get_integer(const char **nptr)
{
	double	val;

	val = 0;
	while (ft_isdigit(**nptr))
	{
		val = val * 10.0 + (**nptr - '0');
		(*nptr)++;
	}
	return (val);
}

static double	get_fraction(const char **nptr, double *divisor)
{
	double	val;

	val = 0;
	*divisor = 1.0;
	while (ft_isdigit(**nptr))
	{
		val = val * 10.0 + (**nptr - '0');
		*divisor *= 10.0;
		(*nptr)++;
	}
	return (val);
}

double	ft_atof(const char *nptr)
{
	short	sign;
	double	value;
	double	fraction;
	double	divisor;

	sign = get_sign(&nptr);
	value = get_integer(&nptr);
	if (*nptr != '.')
		return (sign * value);
	nptr++;
	fraction = get_fraction(&nptr, &divisor);
	value += fraction / divisor;
	return (sign * value);
}
