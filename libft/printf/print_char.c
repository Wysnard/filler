/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <vlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 18:26:18 by vlay              #+#    #+#             */
/*   Updated: 2017/12/05 19:35:17 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

size_t	ft_wcharlen(wchar_t wc)
{
	size_t	i;

	i = 0;
	if (wc <= 0x7F)
		i++;
	else if (wc <= 0x7FF)
		i += 2;
	else if (wc <= 0xFFFF)
		i += 3;
	else if (wc <= 0x10FFFFF)
		i += 4;
	return (i);
}

int		ft_print_char(va_list *ap, t_file *file)
{
	size_t		i;
	wchar_t		wc;

	i = 0;
	if (!ft_strchr(file->flags, '-') && file->nb)
		(ft_strchr(file->flags, '0')) ?
		ft_putnchar('0', (i = file->nb - 1), 1)
		: ft_putnchar(' ', (i = file->nb - 1), 1);
	(file->convert == l) ?
	ft_putwchar_fd(wc = va_arg(*ap, wchar_t), 1) :
	ft_putchar_fd(va_arg(*ap, int), 1);
	if (ft_strchr(file->flags, '-') && file->nb)
		ft_putnchar(' ', (i = file->nb - 1), 1);
	file->ct += (file->convert == l) ? i + ft_wcharlen(wc) : i + 1;
	return (file->ct);
}

int		ft_print_perc(va_list *ap, t_file *file)
{
	size_t		i;

	i = 0;
	(void)ap;
	if (!ft_strchr(file->flags, '-') && file->nb)
		(ft_strchr(file->flags, '0')) ?
		ft_putnchar('0', (i = file->nb - 1), 1)
		: ft_putnchar(' ', (i = file->nb - 1), 1);
	ft_putchar_fd('%', 1);
	if (ft_strchr(file->flags, '-') && file->nb)
		ft_putnchar(' ', (i = file->nb - 1), 1);
	file->ct += i + 1;
	return (file->ct);
}
