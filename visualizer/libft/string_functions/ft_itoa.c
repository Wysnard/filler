/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 10:28:58 by nfinkel           #+#    #+#             */
/*   Updated: 2018/01/27 14:52:18 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./string.h"

inline char			*ft_itoa(int n)
{
	char				tmp[13];
	char				*string;
	int					k;
	unsigned int		nb;

	k = -1;
	if (!n)
		tmp[++k] = '0';
	nb = (n < 0 ? -n : n);
	while (nb > 0)
	{
		tmp[++k] = nb % 10 + 48;
		nb /= 10;
	}
	if (n < 0)
		tmp[++k] = '-';
	tmp[++k] = '\0';
	FAILZ(string = ft_strrevcpy(tmp), NULL);
	GIMME(string);
}
