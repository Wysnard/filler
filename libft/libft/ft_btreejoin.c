/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btreejoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:22:39 by vlay              #+#    #+#             */
/*   Updated: 2017/11/10 16:22:50 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_btree	*ft_btreejoin(t_btree *gauche, t_btree *droite, void *item)
{
	t_btree	*tr;

	if (!(tr = malloc(sizeof(*tr))))
		return (NULL);
	tr->content = item;
	tr->left = gauche;
	tr->right = droite;
	return (tr);
}
