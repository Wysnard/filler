/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pilecadd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 21:16:00 by vlay              #+#    #+#             */
/*   Updated: 2017/12/18 21:16:02 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_pilecadd(t_pile *pile, void *info, size_t content_size)
{
	t_list	*new;

	new = NULL;
	if (!(new = ft_lstsnew(info, content_size)))
		exit(EXIT_FAILURE);
	ft_clstadd(&pile->first, new);
}
