/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 19:43:02 by vlay              #+#    #+#             */
/*   Updated: 2017/11/18 10:31:19 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;
	size_t	i;

	d = (char *)dest;
	s = (char *)src;
	i = -1;
	if (s < d)
		while ((int)--n >= 0)
			*(d + n) = *(s + n);
	else if (d < s)
		while (++i < n)
			*(d + i) = *(s + i);
	return (dest);
}
