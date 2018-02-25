/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 19:11:31 by vlay              #+#    #+#             */
/*   Updated: 2017/11/17 18:09:29 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	size_t			i;
	long	long	nb;
	int				sign;

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
