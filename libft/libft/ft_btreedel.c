/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btreedel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:21:30 by vlay              #+#    #+#             */
/*   Updated: 2017/11/10 16:21:53 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btreedel(t_btree *tr)
{
	if (tr == NULL)
		return ;
	ft_btreedel(tr->left);
	ft_btreedel(tr->right);
	if (tr->content)
		free(tr->content);
	free(tr);
}
