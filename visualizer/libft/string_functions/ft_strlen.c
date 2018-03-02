/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 20:01:48 by nfinkel           #+#    #+#             */
/*   Updated: 2018/01/27 15:02:20 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/dependencies.h"

size_t			ft_strlen(const char *s)
{
	size_t		len;

	len = 0;
	while (*s)
	{
		++s;
		++len;
	}
	GIMME(len);
}
