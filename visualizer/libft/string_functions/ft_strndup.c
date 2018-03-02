/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 14:50:07 by nfinkel           #+#    #+#             */
/*   Updated: 2018/01/27 14:53:42 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./string.h"

inline char			*ft_strndup(const char *s, size_t n)
{
	char		*str;

	FAILZ(str = ft_strnew(n), NULL);
	str = ft_strncpy(str, (char *)s, n);
	str[n] = '\0';
	GIMME(str);
}
