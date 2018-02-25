/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:07:17 by vlay              #+#    #+#             */
/*   Updated: 2017/11/10 16:07:50 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	char *str;

	if (!(str = ft_strnew(n)))
		return (NULL);
	ft_strncpy(str, s, n);
	str[n] = '\0';
	return (str);
}
