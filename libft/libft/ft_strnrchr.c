/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnrchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 21:08:29 by vlay              #+#    #+#             */
/*   Updated: 2017/12/04 21:08:34 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnrchr(const char *s, int c, size_t n)
{
	const	char	*tmp;

	tmp = s;
	while (*tmp && n)
	{
		tmp++;
		n--;
	}
	if ((char)c == '\0')
		return ((char *)tmp);
	while (--tmp >= s)
		if (*tmp == (char)c)
			return ((char *)tmp);
	return (NULL);
}
