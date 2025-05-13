/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykai-yua <ykai-yua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:33:47 by ykai-yua          #+#    #+#             */
/*   Updated: 2025/02/25 17:45:05 by ykai-yua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	parse_integer(const char *str, int *i, double *result)
{
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		*result = *result * 10.0 + (str[*i] - '0');
		(*i)++;
	}
	return (0);
}

static int	parse_fraction(const char *str, int *i, double *result)
{
	double	fraction;

	fraction = 1.0;
	if (str[*i] == '.')
	{
		(*i)++;
		while (str[*i] >= '0' && str[*i] <= '9')
		{
			fraction *= 0.1;
			*result += (str[*i] - '0') * fraction;
			(*i)++;
		}
	}
	return (0);
}

double	ft_strtod(const char *str, char **endptr)
{
	double	sign;
	double	result;
	int		i;

	sign = 1.0;
	result = 0.0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1.0;
		i++;
	}
	parse_integer(str, &i, &result);
	parse_fraction(str, &i, &result);
	if (endptr)
		*endptr = (char *)&str[i];
	return (result * sign);
}
