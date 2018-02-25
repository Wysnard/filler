/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 20:02:15 by vlay              #+#    #+#             */
/*   Updated: 2017/11/10 15:42:37 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	if (!(dest = ft_strnew(len)))
		return (NULL);
	while (s[start] != '\0' && len--)
		dest[i++] = s[start++];
	dest[i] = '\0';
	return (dest);
}
