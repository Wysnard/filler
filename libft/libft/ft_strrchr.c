/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 20:00:58 by vlay              #+#    #+#             */
/*   Updated: 2017/11/06 20:01:06 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const	char	*tmp;

	tmp = s;
	while (*tmp)
		tmp++;
	if ((char)c == '\0')
		return ((char *)tmp);
	while (--tmp >= s)
		if (*tmp == (char)c)
			return ((char *)tmp);
	return (NULL);
}
