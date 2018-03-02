/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nextpower2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 15:54:36 by nfinkel           #+#    #+#             */
/*   Updated: 2018/01/29 05:03:19 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dependencies.h"

size_t			ft_nextpower2(size_t nb)
{
	size_t		n1;
	size_t		n2;

	if (nb == SIZE_MAX || IS_POW2(nb))
		GIMME(nb);
	n1 = (uint32_t)nb;
	if (!(n2 = n1 & 0xFFFF0000))
		n2 = n1;
	if (!(n1 = n2 & 0xFF00FF00))
		n1 = n2;
	if (!(n2 = n1 & 0xF0F0F0F0))
		n2 = n1;
	if (!(n1 = n2 & 0xCCCCCCCC))
		n1 = n2;
	if (!(n2 = n1 & 0xAAAAAAAA))
		n2 = n1;
	n1 = n2 << 1;
	GIMME((n1 < nb) ? (size_t)SIZE_MAX : n1);
}
