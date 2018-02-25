/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <vlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 20:24:48 by vlay              #+#    #+#             */
/*   Updated: 2017/12/04 20:31:48 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

size_t	ft_wstrlen(wchar_t *wstr)
{
	size_t	i;

	i = 0;
	while (*wstr)
		i += ft_wcharlen(*wstr++);
	return (i);
}

int		ft_print_wstr(va_list *ap, t_file *file)
{
	wchar_t		*wstr;
	wchar_t		*printed;
	size_t		i;

	i = 0;
	if ((wstr = va_arg(*ap, wchar_t *)))
		printed = (file->precision >= 0) ?
		ft_wcsndup(wstr, file->precision) : ft_wcsdup(wstr);
	else
		printed = (file->precision >= 0) ?
		ft_wcsndup(L"(null)", file->precision) : ft_wcsdup(L"(null)");
	i = (file->nb > ft_wcslen(printed)) ? file->nb - ft_wcslen(printed) : 0;
	if (!ft_strchr(file->flags, '-') && i)
		ft_putnchar(' ', i, 1);
	else if (i)
		ft_putwspace(&printed, &i);
	ft_putwstr_fd(printed, 1);
	file->ct += ft_wstrlen(printed) + i;
	free(printed);
	return (1);
}

int		ft_print_str(va_list *ap, t_file *file)
{
	const	char	*str;
	char			*printed;
	size_t			i;

	i = 0;
	if (file->convert == l)
		return (ft_print_wstr(ap, file));
	if ((str = va_arg(*ap, const char *)))
		printed = (file->precision >= 0) ?
		ft_strndup(str, file->precision) : ft_strdup(str);
	else
		printed = (file->precision >= 0) ?
		ft_strndup("(null)", file->precision) : ft_strdup("(null)");
	i = (file->nb > ft_strlen(printed)) ? file->nb - ft_strlen(printed) : 0;
	if (i)
		(!ft_strchr(file->flags, '-')) ?
		ft_putspace(&printed, &i, 'f') : ft_putspace(&printed, &i, 'b');
	ft_putstr_fd(printed, 1);
	file->ct += ft_strlen(printed) + i;
	free(printed);
	return (1);
}
