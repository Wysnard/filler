/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmultijoin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <vlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 11:23:03 by vlay              #+#    #+#             */
/*   Updated: 2018/01/06 11:28:49 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strmulticat(char *dest, size_t nbarg, ...)
{
	va_list	ap;
	size_t	i;

	i = 0;
	va_start(ap, nbarg);
	while (i < nbarg)
	{
		ft_strcat(dest, va_arg(ap, char *));
		i++;
	}
	va_end(ap);
	return (dest);
}

static	void	ft_catcat(size_t nbarg, char *str, va_list aq)
{
	size_t	i;

	i = 0;
	while (i < nbarg)
	{
		ft_strcat(str, va_arg(aq, char *));
		i++;
	}
}

char			*ft_strmultijoin(size_t nbarg, ...)
{
	size_t	i;
	size_t	len;
	va_list	ap;
	va_list	aq;
	char	*str;

	i = 0;
	len = 0;
	if (nbarg == 0)
		return (NULL);
	va_copy(aq, ap);
	va_start(ap, nbarg);
	while (i < nbarg)
	{
		len += ft_strlen(va_arg(ap, char *));
		i++;
	}
	va_end(ap);
	str = ft_strnew(len);
	va_start(aq, nbarg);
	ft_catcat(nbarg, str, aq);
	va_end(aq);
	return (str);
}
