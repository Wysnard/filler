/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pileadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <vlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:57:40 by vlay              #+#    #+#             */
/*   Updated: 2017/12/07 04:59:11 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_pileadd(t_pile *pile, void *info, size_t content_size)
{
	t_list	*new;

	new = NULL;
	if (!(new = ft_lstsnew(info, content_size)))
		exit(EXIT_FAILURE);
	ft_lstadd(&pile->first, new);
}
