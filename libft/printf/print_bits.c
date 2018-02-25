/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <vlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 18:21:12 by vlay              #+#    #+#             */
/*   Updated: 2017/12/09 18:46:31 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static	size_t	ft_get_binaire(size_t len, t_file *file)
{
	int	i;

	if (file->convert == hh)
		i = 8 - len;
	else if (file->convert == h)
		i = 16 - len;
	else if (file->convert == l)
		i = 32 - len;
	else if (file->convert == ll)
		i = 64 - len;
	else if (file->convert == j)
		i = 64 - len;
	else if (file->convert == z)
		i = 32 - len;
	else
		i = 8 - len;
	if (i < 0)
		return (0);
	return (i);
}

char			*ft_init_b(va_list *ap, t_file *file)
{
	char		*str;
	uintmax_t	nbr;
	size_t		len;
	size_t		i;

	nbr = ft_get_type_u(ap, file);
	str = ft_utoa(nbr, "01");
	len = ft_strlen(str);
	i = ft_get_binaire(len, file);
	ft_putzero(&str, &i, "0b", file);
	if (file->precision == 0)
		str[0] = '\0';
	else
		ft_nbprec(&str, file->precision - len);
	if (ft_strchr(file->flags, '#') && nbr > 0
	&& (str = ft_strjoinfree(ft_strdup("0b"), str)))
		str[len + 2] = '\0';
	return (str);
}

int				ft_print_b(va_list *ap, t_file *file)
{
	char		*str;
	size_t		i;

	str = ft_init_b(ap, file);
	i = (file->nb > ft_strlen(str)) ? file->nb - ft_strlen(str) : 0;
	if (ft_strchr(file->flags, '0') && file->precision >= 0)
		ft_putnchar(' ', i - file->nb, 1);
	else if (ft_strchr(file->flags, '0') && !ft_strchr(file->flags, '-'))
		ft_putzero(&str, &i, "0b", file);
	if (i)
		(!ft_strchr(file->flags, '-')) ?
		ft_putspace(&str, &i, 'f') : ft_putspace(&str, &i, 'b');
	ft_putstr_fd(str, 1);
	file->ct += ft_strlen(str) + i;
	free(str);
	return (1);
}
