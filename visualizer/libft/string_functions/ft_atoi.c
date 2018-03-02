/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 22:11:43 by nfinkel           #+#    #+#             */
/*   Updated: 2018/01/27 15:01:49 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dependencies.h"

int			ft_atoi(const char *str)
{
	int						neg;
	unsigned long long		sum;

	neg = 1;
	sum = 0;
	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			neg = -1;
	while (*str >= '0' && *str <= '9')
	{
		sum = sum * 10uLL + (unsigned long long)(*str - 48);
		if (sum > (unsigned long long)LLONG_MAX)
			GIMME(neg < 0 ? 0 : -1);
		++str;
	}
	GIMME(neg * (int)sum);
}
