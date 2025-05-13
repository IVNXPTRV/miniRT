/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_check.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:24:37 by nteechar          #+#    #+#             */
/*   Updated: 2024/10/25 14:57:46 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_CHECK_H
# define TYPE_CHECK_H

int	ft_isalpha(int c);
int	ft_isdigit(int c);
int	ft_isalnum(int c);
int	ft_isascii(int c);
int	ft_isinset(int c, char *set, int n);
int	ft_isprint(int c);
int	ft_islower(int c);
int	ft_isupper(int c);
int	ft_isspace(int c);

#endif
