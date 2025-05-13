/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykai-yua <ykai-yua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:14:48 by nteechar          #+#    #+#             */
/*   Updated: 2025/03/12 16:35:05 by ykai-yua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSION_H
# define CONVERSION_H

int		ft_atoi(const char *nptr);
char	*ft_itoa(int n);
int		ft_toupper(int c);
int		ft_tolower(int c);
double	ft_atof(const char *nptr);
double	ft_strtod(const char *str, char **endptr);
long	ft_strtol(const char *str, char **endptr);

#endif
