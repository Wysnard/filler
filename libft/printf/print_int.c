/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <vlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 20:19:29 by vlay              #+#    #+#             */
/*   Updated: 2017/12/06 19:07:55 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <limits.h>

intmax_t			ft_get_type_int(va_list *ap, t_file *file)
{
	intmax_t	nbr;

	nbr = va_arg(*ap, intmax_t);
	if (file->convert == hh)
		nbr = (char)nbr;
	else if (file->convert == h)
		nbr = (short int)nbr;
	else if (file->convert == l)
		nbr = (long)nbr;
	else if (file->convert == ll)
		nbr = (long long)nbr;
	else if (file->convert == j)
		nbr = (intmax_t)nbr;
	else if (file->convert == z)
		nbr = (size_t)nbr;
	else
		nbr = (int)nbr;
	return (nbr);
}

static	char		*ft_init_int(va_list *ap, t_file *file)
{
	char		*str;
	intmax_t	nbr;

	nbr = ft_get_type_int(ap, file);
	str = ((unsigned long long)nbr == -9223372036854775808ull) ?
	ft_strdup("-9223372036854775808") : ft_imtoa_base(nbr, "0123456789");
	if (file->precision == 0 && nbr == 0)
		str[0] = '\0';
	else
		ft_nbprec(&str, ((nbr < 0) ?
		file->precision + 1 : file->precision) - ft_strlen(str));
	if (ft_strchr(file->flags, '+') && nbr >= 0)
		str = ft_strjoinfree(ft_strdup("+"), str);
	else if (ft_strchr(file->flags, ' ') && nbr >= 0)
		str = ft_strjoinfree(ft_strdup(" "), str);
	return (str);
}

int					ft_print_int(va_list *ap, t_file *file)
{
	char		*str;
	size_t		i;

	i = 0;
	str = ft_init_int(ap, file);
	i = (file->nb > ft_strlen(str)) ? file->nb - ft_strlen(str) : 0;
	if (ft_strchr(file->flags, '0') && file->precision >= 0)
		ft_putnchar(' ', i - file->nb, 1);
	else if (ft_strchr(file->flags, '0') && !ft_strchr(file->flags, '-'))
		ft_putzero(&str, &i, "", file);
	if (i)
		(!ft_strchr(file->flags, '-')) ?
		ft_putspace(&str, &i, 'f') : ft_putspace(&str, &i, 'b');
	ft_putstr_fd(str, 1);
	file->ct += ft_strlen(str) + i;
	free(str);
	return (1);
}
