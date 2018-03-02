/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 20:01:07 by nfinkel           #+#    #+#             */
/*   Updated: 2018/01/27 14:52:22 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./string.h"

inline char			*ft_strcat(char *restrict dst, const char *restrict src)
{
	char		*d;

	d = ft_strchr(dst, '\0');
	while ((*d++ = *src++))
		;
	GIMME(dst);
}
