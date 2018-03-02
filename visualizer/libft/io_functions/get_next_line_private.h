/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_private.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/27 17:23:30 by nfinkel           #+#    #+#             */
/*   Updated: 2018/01/28 18:24:06 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_PRIVATE_H
# define GET_NEXT_LINE_PRIVATE_H

# include "../includes/dependencies.h"
# include "../linkedlist_functions/linkedlist.h"
# include "../memory_functions/memory.h"
# include "../string_functions/string.h"

# define LIST_CONTENT ((t_data *)(list->content))

# define BUFF_SIZE 4096

typedef struct		s_data
{
	char			*begin;
	char			*str;
	int				fd;
}					t_data;

#endif
