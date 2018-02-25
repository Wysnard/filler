/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btreelvlct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:22:56 by vlay              #+#    #+#             */
/*   Updated: 2017/11/10 16:23:07 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_btreelvlct(t_btree *root)
{
	if (root == NULL)
		return (0);
	return (((ft_btreelvlct(root->left) > ft_btreelvlct(root->right)) ?
	ft_btreelvlct(root->left) : ft_btreelvlct(root->right)) + 1);
}
