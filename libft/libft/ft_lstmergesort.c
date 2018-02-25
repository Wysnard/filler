/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmergesort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 11:29:55 by vlay              #+#    #+#             */
/*   Updated: 2018/01/06 11:30:33 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_lstmerge(t_list *a, t_list *b, int (*cmpf)(void *, void *))
{
	t_list	*result;

	result = NULL;
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if (cmpf(a->content, b->content) >= 0)
	{
		result = a;
		result->next = ft_lstmerge(a->next, b, cmpf);
	}
	else
	{
		result = b;
		result->next = ft_lstmerge(a, b->next, cmpf);
	}
	return (result);
}

void			ft_lstmergesort(t_list **list, int (*cmpf)(void *, void *))
{
	t_list	*head;
	t_list	*a;
	t_list	*b;

	head = *list;
	if (!head || !head->next)
		return ;
	ft_lstfrontbacksplit(head, &a, &b);
	ft_lstmergesort(&a, cmpf);
	ft_lstmergesort(&b, cmpf);
	*list = ft_lstmerge(a, b, cmpf);
}
