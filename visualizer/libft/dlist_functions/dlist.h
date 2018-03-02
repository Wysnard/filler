/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 13:55:51 by nfinkel           #+#    #+#             */
/*   Updated: 2018/02/03 14:31:57 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DLIST_H
# define DLIST_H

# include "../includes/dependencies.h"

typedef struct		s_dlist
{
	size_t			data_size;
	void			*data;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}					t_dlist;

extern void			ft_dlstadd(t_dlist **adlst, t_dlist *newlink);
extern void			ft_dlstappend(t_dlist *dlist, t_dlist *newlink);
extern t_dlist		*ft_dlstnew(const void *content, size_t content_size);

#endif
