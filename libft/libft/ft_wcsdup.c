/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcsdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <vlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 21:10:20 by vlay              #+#    #+#             */
/*   Updated: 2017/12/04 21:10:57 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t	*ft_wcsdup(wchar_t *wcs)
{
	wchar_t	*dup;
	size_t	len;

	len = ft_wcslen(wcs);
	if (!(dup = ft_wcsnew(len)))
		return (NULL);
	ft_wcsncpy(dup, wcs, len);
	dup[len] = '\0';
	return (dup);
}
