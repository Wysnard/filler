/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <vlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 20:27:44 by vlay              #+#    #+#             */
/*   Updated: 2017/12/06 19:08:40 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_conversion(char **start, t_file *file, va_list *ap)
{
	static	int	(*prt[NBPRT])(va_list *, t_file *) =
	{&ft_print_char, &ft_print_str, &ft_print_int, &ft_print_int,
	&ft_print_unsigned, &ft_print_exa, &ft_print_hexa, &ft_print_octal,
	&ft_print_pointer, &ft_print_b, &ft_print_n, &ft_print_perc};
	size_t		i;

	if (ft_isupper(**start) && **start != 'X')
		if (**start == 'C' || **start == 'S' || file->convert < l)
			file->convert = l;
	if ((i = ft_strchri("csdiuXxopbn%",
	(**start == 'X') ? **start : ft_tolower(**start))) < NBPRT)
		prt[i](ap, file);
	else
		return ;
	(*start)++;
}

int		ft_process(char **start, t_file *file, va_list *ap)
{
	if (**start == '\0')
		return (0);
	ft_init_flags(file);
	if (!ft_flags(start, file, ap))
		return (0);
	ft_conversion(start, file, ap);
	return (1);
}
