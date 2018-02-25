/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_n.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 19:08:09 by vlay              #+#    #+#             */
/*   Updated: 2017/12/06 19:08:20 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static	intmax_t	ft_convert_n(intmax_t ct, t_file *file)
{
	if (file->convert == hh)
		ct = (char)ct;
	else if (file->convert == h)
		ct = (short int)ct;
	else if (file->convert == l)
		ct = (long)ct;
	else if (file->convert == ll)
		ct = (long long)ct;
	else if (file->convert == j)
		ct = (intmax_t)ct;
	else if (file->convert == z)
		ct = (size_t)ct;
	else
		ct = (int)ct;
	return (ct);
}

int					ft_print_n(va_list *ap, t_file *file)
{
	int	*i;

	i = va_arg(*ap, int *);
	*i = ft_convert_n(file->ct, file);
	return (1);
}
