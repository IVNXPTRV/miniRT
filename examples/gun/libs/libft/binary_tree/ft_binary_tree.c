/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binary_tree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <nteechar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:11:49 by nteechar          #+#    #+#             */
/*   Updated: 2025/03/25 22:29:39 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_binary_tree.h"

// STILL IN DEVELOPMENT

t_bin_tree	*ft_binary_tree_new(void *content)
{
	t_bin_tree	*node;

	node = malloc(sizeof(t_bin_tree));
	if (node == NULL)
		return (NULL);
	node->content = content;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

// free everything, from given node to leaves
void	ft_binary_tree_clear(t_bin_tree **tree, void (*del)(void *))
{
	if ((*tree)->left)
		ft_binary_tree_clear(&(*tree)->left, del);
	if ((*tree)->right)
		ft_binary_tree_clear(&(*tree)->right, del);
	if (del)
	{
		del((*tree)->content);
	}
	free(*tree);
	*tree = NULL;
}

void	ft_binary_tree_set_left(t_bin_tree *parent, t_bin_tree *child)
{
	parent->left = child;
}

void	ft_binary_tree_set_right(t_bin_tree *parent, t_bin_tree *child)
{
	parent->right = child;
}

/*
int main(void)
{
	char **strings = malloc(sizeof(char *) * 4);
	strings[0] = malloc(100);
	for (int i = 0; i < 3; i++)
		strings[0][i] = 'a';
	strings[0][3] = '\0';

	strings[1] = malloc(100);
	for (int i = 0; i < 3; i++)
		strings[1][i] = 'b';
	strings[1][3] = '\0';

	strings[2] = malloc(100);
	for (int i = 0; i < 3; i++)
		strings[2][i] = 'c';
	strings[2][3] = '\0';

	strings[3] = malloc(100);
	for (int i = 0; i < 3; i++)
		strings[3][i] = 'd';
	strings[3][3] = '\0';

	t_binary_tree	*a = ft_binary_tree_new(strings[0]);
	t_binary_tree	*b = ft_binary_tree_new(strings[1]);
	t_binary_tree	*c = ft_binary_tree_new(strings[2]);
	t_binary_tree	*d = ft_binary_tree_new(strings[3]);

	ft_binary_tree_set_left(a, b);
	ft_binary_tree_set_right(a, c);
	ft_binary_tree_set_left(b, d);

	printf(
		"  a \n"
		" b c\n"
		"d\n"
	);
	printf("a=%s b=%s c=%s d=%s\n",
		(char *) a->content, (char *) a->left->content,
		(char *) a->right->content, (char *) a->left->left->content);

	// ft_binary_tree_delete(&d, NULL);
	ft_binary_tree_clear(&a, free);

	free(strings);

	return (0);
}
*/
