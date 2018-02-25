/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pilepushadd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <vlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:59:41 by vlay              #+#    #+#             */
/*   Updated: 2017/12/06 22:25:13 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_pilepushadd(t_pile *pile, void *info, size_t content_size)
{
	t_list	*new;

	new = NULL;
	if (!pile)
		return ;
	if (!(new = ft_lstnew(info, content_size)))
		exit(EXIT_FAILURE);
	ft_lstpushadd(&pile->first, new);
}
