#include "libft.h"

static	int	ft_isspace(int c)
{
	if (c == '\n' || c == '\t' || c == '\f' || c == '\r'
		|| c == '\v' || c == ' ')
		return (1);
	return (0);
}

static	double	get_decimal(const char *str)
{
	double	result;
	double		i;

	result = 0;
	i = 1;
	str++;
	while (*str >= '0' && *str <= '9')
	{
		i /= 10;
		result *= 10;
		result += *str - '0';
		str++;
	}
	return (i * result);
}

double	ft_atod(const char *str)
{
	int sign;
	double	result;
	double	decimal;

	result = 0;
	sign = 1;
	decimal = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result *= 10;
		result += *str - '0';
		str++;
	}
	if (*str == '.')
		decimal = get_decimal(str);
	result += decimal;
	return (result * sign);
}
