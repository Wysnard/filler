/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btreeinsert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <vlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:21:59 by vlay              #+#    #+#             */
/*   Updated: 2017/12/14 17:59:09 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btreeinsert(t_btree **root, void *item,
	size_t content_size, int (*cmpf)(void *, void *))
{
	int	ret;

	if (*root == NULL)
		*root = ft_btreecreate(item, content_size);
	if ((ret = (*cmpf)((*root)->content, item)) >= 0 && (*root)->left != NULL)
		ft_btreeinsert(&(*root)->left, item, content_size, cmpf);
	else if (ret < 0 && (*root)->right != NULL)
		ft_btreeinsert(&(*root)->right, item, content_size, cmpf);
	else if (ret >= 0 && (*root)->left == NULL)
		(*root)->left = ft_btreecreate(item, content_size);
	else if (ret < 0 && (*root)->right == NULL)
		(*root)->right = ft_btreecreate(item, content_size);
}
