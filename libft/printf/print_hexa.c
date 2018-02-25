/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <vlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 18:27:10 by vlay              #+#    #+#             */
/*   Updated: 2017/12/04 21:03:01 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static	char	*ft_init_hexa(va_list *ap, t_file *file)
{
	char		*str;
	uintmax_t	nbr;
	size_t		len;

	nbr = ft_get_type_u(ap, file);
	str = ft_utoa(nbr, "0123456789abcdef");
	if (file->precision == 0)
		str[0] = '\0';
	else
		ft_nbprec(&str, file->precision - (len = ft_strlen(str)));
	if (ft_strchr(file->flags, '#') && nbr > 0
	&& (str = ft_strjoinfree(ft_strdup("0x"), str)))
		str[len + 2] = '\0';
	return (str);
}

int				ft_print_hexa(va_list *ap, t_file *file)
{
	char		*str;
	size_t		i;

	str = ft_init_hexa(ap, file);
	i = (file->nb > ft_strlen(str)) ? file->nb - ft_strlen(str) : 0;
	if (ft_strchr(file->flags, '0') && file->precision >= 0)
		ft_putnchar(' ', i - file->nb, 1);
	else if (ft_strchr(file->flags, '0') && !ft_strchr(file->flags, '-'))
		ft_putzero(&str, &i, "0x", file);
	if (i)
		(!ft_strchr(file->flags, '-')) ?
		ft_putspace(&str, &i, 'f') : ft_putspace(&str, &i, 'b');
	ft_putstr_fd(str, 1);
	file->ct += ft_strlen(str) + i;
	free(str);
	return (1);
}

static	char	*ft_init_exa(va_list *ap, t_file *file)
{
	char		*str;
	uintmax_t	nbr;
	size_t		len;

	nbr = ft_get_type_u(ap, file);
	str = ft_utoa(nbr, "0123456789ABCDEF");
	if (file->precision == 0)
		str[0] = '\0';
	else
		ft_nbprec(&str, file->precision - (len = ft_strlen(str)));
	if (ft_strchr(file->flags, '#') && nbr > 0
	&& (str = ft_strjoinfree(ft_strdup("0X"), str)))
		str[len + 2] = '\0';
	return (str);
}

int				ft_print_exa(va_list *ap, t_file *file)
{
	char		*str;
	size_t		i;

	str = ft_init_exa(ap, file);
	i = (file->nb > ft_strlen(str)) ? file->nb - ft_strlen(str) : 0;
	if (ft_strchr(file->flags, '0') && file->precision >= 0)
		ft_putnchar(' ', i - file->nb, 1);
	else if (ft_strchr(file->flags, '0') && !ft_strchr(file->flags, '-'))
		ft_putzero(&str, &i, "0x", file);
	if (i)
		(!ft_strchr(file->flags, '-')) ?
		ft_putspace(&str, &i, 'f') : ft_putspace(&str, &i, 'b');
	ft_putstr_fd(str, 1);
	file->ct += ft_strlen(str) + i;
	free(str);
	return (1);
}

int				ft_print_pointer(va_list *ap, t_file *file)
{
	char		*str;
	size_t		i;

	str = ft_utoa(va_arg(*ap, uintmax_t), "0123456789abcdef");
	if (file->precision == 0)
		str[0] = '\0';
	else
		ft_nbprec(&str, file->precision - ft_strlen(str));
	str = ft_strjoinfree(ft_strdup("0x"), str);
	i = (file->nb > ft_strlen(str)) ? file->nb - ft_strlen(str) : 0;
	if (ft_strchr(file->flags, '0'))
		(file->precision >= 0) ?
		ft_putnchar(' ', i - file->nb, 1) : ft_putzero(&str, &i, "0x", file);
	if (i)
		(!ft_strchr(file->flags, '-')) ?
		ft_putspace(&str, &i, 'f') : ft_putspace(&str, &i, 'b');
	ft_putstr_fd(str, 1);
	file->ct += ft_strlen(str) + i;
	free(str);
	return (1);
}
