/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_rev_infix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:20:48 by vlay              #+#    #+#             */
/*   Updated: 2017/11/10 16:20:58 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btree_rev_infix(t_btree *root, void (*applyf)(void *))
{
	if (root == NULL)
		return ;
	if (root->right != NULL)
		ft_btree_rev_infix(root->right, applyf);
	(*applyf)(root->content);
	if (root->left != NULL)
		ft_btree_rev_infix(root->left, applyf);
}
