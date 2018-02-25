/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <vlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 20:32:41 by vlay              #+#    #+#             */
/*   Updated: 2017/12/04 20:40:52 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putzero(char **str, size_t *i, char *prefix, t_file *file)
{
	char	*zero;
	char	*tmp;
	char	save[3];

	if (!(zero = ft_strnew(*i)))
		exit(EXIT_FAILURE);
	ft_memset((tmp = zero), '0', *i);
	zero[*i] = '\0';
	if (ft_strchr(file->flags, '0') && ft_strnequ(*str, prefix, 2))
	{
		(ft_isdigit((*str)[1])) ?
		ft_strcpy(*str, &(*str)[1]) : ft_strcpy(*str, &(*str)[2]);
		zero = ft_strjoin(ft_strcpy(save, prefix), tmp);
		free(tmp);
	}
	else if (!ft_isdigit(**str))
	{
		save[0] = **str;
		save[1] = '\0';
		ft_strcpy(*str, (*str) + 1);
		zero = ft_strjoin(save, tmp);
		free(tmp);
	}
	*str = ft_strjoinfree(zero, *str);
	*i = 0;
}
