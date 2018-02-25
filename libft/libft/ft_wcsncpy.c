/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcsncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 21:11:20 by vlay              #+#    #+#             */
/*   Updated: 2017/12/04 21:11:27 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t	*ft_wcsncpy(wchar_t *dest, const wchar_t *src, size_t n)
{
	size_t	i;
	wchar_t	*cp;

	i = 0;
	cp = dest;
	while (src[i] && i < n)
	{
		cp[i] = src[i];
		i++;
	}
	while (i < n)
		cp[i++] = '\0';
	return (dest);
}
