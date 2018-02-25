/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoim.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <vlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:49:41 by vlay              #+#    #+#             */
/*   Updated: 2017/12/04 21:07:04 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

intmax_t	ft_atoim(const char *nptr)
{
	size_t		i;
	intmax_t	nb;
	intmax_t	sign;

	nb = 0;
	i = 0;
	sign = 1;
	while (*nptr == '\n' || *nptr == '\t' || *nptr == '\r' ||
					*nptr == '\v' || *nptr == '\f' || *nptr == ' ')
		nptr++;
	if (*nptr == '-')
		sign = -1;
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	while (ft_isdigit(nptr[i]))
	{
		nb = nb * 10 + (nptr[i] - '0');
		i++;
		if (i > 19 || nb > 9223372036854775807)
			return ((sign == 1) ? -1 : 0);
	}
	return (nb * sign);
}
