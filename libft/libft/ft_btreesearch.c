/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btreesearch.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:23:13 by vlay              #+#    #+#             */
/*   Updated: 2017/11/10 16:24:31 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_btreesearch(t_btree *root,
		void *data_ref, int (*cmpf)(void *, void *))
{
	if (root == NULL)
		return (NULL);
	if (root->left != NULL)
		ft_btreesearch(root->left, data_ref, cmpf);
	if ((*cmpf)(root->content, data_ref) == 0)
		return (root->content);
	if (root->right != NULL)
		ft_btreesearch(root->right, data_ref, cmpf);
	return (NULL);
}
