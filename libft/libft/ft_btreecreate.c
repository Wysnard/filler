/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btreecreate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <vlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:21:05 by vlay              #+#    #+#             */
/*   Updated: 2017/12/14 17:51:49 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_btree	*ft_btreecreate(void *item, size_t content_size)
{
	t_btree	*tmp;

	tmp = NULL;
	tmp = malloc(sizeof(*tmp));
	if (tmp)
	{
		tmp->content = item;
		tmp->content_size = content_size;
		tmp->left = NULL;
		tmp->right = NULL;
	}
	return (tmp);
}
