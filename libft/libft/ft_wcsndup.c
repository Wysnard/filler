/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcsndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 21:11:50 by vlay              #+#    #+#             */
/*   Updated: 2017/12/04 21:12:41 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t	*ft_wcsndup(wchar_t *wcs, size_t n)
{
	wchar_t	*dup;

	if (!(dup = ft_wcsnew(n)))
		return (NULL);
	ft_wcsncpy(dup, wcs, n);
	dup[n] = '\0';
	return (dup);
}
