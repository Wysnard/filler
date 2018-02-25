/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intgetmin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 20:52:30 by vlay              #+#    #+#             */
/*   Updated: 2018/02/25 20:52:38 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

intmax_t	ft_intgetmin(unsigned nb, ...)
{
	intmax_t	keep;
	va_list		ap;
	intmax_t	min;

	va_start(ap, nb);
	min = INT_MAX;
	while (nb--)
		if ((keep = va_arg(ap, intmax_t)) < min)
			min = keep;
	return (min);
}
