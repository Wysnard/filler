/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <vlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 20:27:02 by vlay              #+#    #+#             */
/*   Updated: 2017/12/05 21:58:28 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

static	int	ft_condition(char *pct, va_list *ap, char **start, t_file *file)
{
	if ((pct = ft_strchr(*start, '%')))
	{
		write(1, *start, pct - (*start));
		file->ct += pct - (*start);
		*start = pct + 1;
		ft_process(start, file, ap);
	}
	else
	{
		ft_putstr_fd(*start, 1);
		file->ct += ft_strlen(*start);
		return (0);
	}
	return (1);
}

int			ft_printf(const char *arg1, ...)
{
	char		*pct;
	va_list		ap;
	char		*start;
	t_file		file;

	file.ct = 0;
	pct = NULL;
	va_start(ap, arg1);
	if (!(start = (char *)arg1))
		return (-1);
	while (*start)
		if (!ft_condition(pct, &ap, &start, &file))
			break ;
	va_end(ap);
	return (file.ct);
}
