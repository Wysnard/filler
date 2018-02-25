/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 15:42:01 by vlay              #+#    #+#             */
/*   Updated: 2017/12/06 15:42:06 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strchri(char *str, int c)
{
	size_t	i;

	if (!str || !*str)
		return (0);
	if ((char)c == '\0')
		return (ft_strlen(str));
	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			return (i);
		i += 1;
	}
	return (i);
}
