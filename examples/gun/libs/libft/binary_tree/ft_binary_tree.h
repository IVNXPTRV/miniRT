/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binary_tree.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:12:32 by nteechar          #+#    #+#             */
/*   Updated: 2025/02/10 18:14:21 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BINARY_TREE_H
# define FT_BINARY_TREE_H

typedef struct s_binary_tree
{
	void					*content;
	struct s_binary_tree	*left;
	struct s_binary_tree	*right;
}	t_bin_tree;

t_bin_tree	*ft_binary_tree_new(void *content);
void		ft_binary_tree_clear(t_bin_tree **tree, void (*del)(void *));

void		ft_binary_tree_set_left(t_bin_tree *parent, t_bin_tree *child);
void		ft_binary_tree_set_right(t_bin_tree *parent, t_bin_tree *child);

#endif
