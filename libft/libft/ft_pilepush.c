/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pilepush.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 21:16:18 by vlay              #+#    #+#             */
/*   Updated: 2017/12/18 21:16:21 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_pilepush(t_pile *pile, void *info, size_t content_size)
{
	t_list	*new;

	new = NULL;
	if (!pile)
		return ;
	if (!(new = ft_lstsnew(info, content_size)))
		exit(EXIT_FAILURE);
	ft_lstpush(&pile->first, new);
}
