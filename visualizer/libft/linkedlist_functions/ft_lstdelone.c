/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 21:43:36 by nfinkel           #+#    #+#             */
/*   Updated: 2018/02/03 14:24:58 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./linkedlist.h"

inline void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	del((*alst)->data, (*alst)->data_size);
	free(*alst);
	*alst = NULL;
}
