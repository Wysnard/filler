/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfilter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 11:31:37 by vlay              #+#    #+#             */
/*   Updated: 2018/01/06 11:32:17 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstfilter(t_list *list, int (*f)(t_list *elem),
		void (*del)(void *, size_t))
{
	t_list	*result;
	t_list	*next;

	result = NULL;
	while (list)
	{
		next = list->next;
		if (f(list))
		{
			list->next = NULL;
			ft_lstpushadd(&result, list);
		}
		else
		{
			del(list->content, list->content_size);
			free(list);
		}
		list = next;
	}
	return (result);
}
