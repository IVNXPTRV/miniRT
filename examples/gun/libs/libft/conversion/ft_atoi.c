/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:20:33 by nteechar          #+#    #+#             */
/*   Updated: 2024/09/04 12:54:36 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspace(int c);
int	ft_isdigit(int c);

int	ft_atoi(const char *nptr)
{
	int		sign;
	long	num;

	while (ft_isspace(*nptr))
		nptr++;
	sign = 1;
	if (*nptr == '-')
	{
		sign = -1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	num = 0;
	while (ft_isdigit(*nptr))
	{
		num *= 10;
		num += *nptr - '0';
		nptr++;
	}
	return ((int)(sign * num));
}
