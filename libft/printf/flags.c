/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <vlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 18:14:43 by vlay              #+#    #+#             */
/*   Updated: 2017/12/06 19:07:28 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

static	void	ft_convert(char *start, t_file *file)
{
	if (*start == 'z')
		file->convert = z;
	else if (*start == 'j')
		file->convert = j;
	else if (start[0] == 'l' && (start)[1] == 'l')
		file->convert = ll;
	else if (*start == 'l')
		file->convert = l;
	else if (*start == 'h' && start[1] == 'h')
		file->convert = hh;
	else if (*start == 'h')
		file->convert = h;
}

int				ft_flags(char **start, t_file *file, va_list *ap)
{
	char	f[2];

	f[1] = '\0';
	while (*start && **start && ft_strchr("#0-+ ", **start))
		if (!ft_strchr(file->flags, (f[0] = *ft_strchr("#0-+ ", *(*start)++))))
			ft_strcat(file->flags, f);
	file->nb = (*(*start)++ == '*') ?
	va_arg(*ap, uintmax_t) : (uintmax_t)ft_atoim(--(*start));
	while (ft_isdigit(**start))
		(*start)++;
	if (**start == '.')
	{
		file->precision = (*(*start + 1) == '*' && ((*start) += 2)) ?
		va_arg(*ap, uintmax_t) : (uintmax_t)ft_atoim(++(*start));
		while (ft_isdigit(**start))
			(*start)++;
	}
	ft_convert(*start, file);
	while (**start && *(*start) + 1 && ft_strchr("hljz", **start))
		(*start)++;
	return ((*start && **start) ? 1 : 0);
}
