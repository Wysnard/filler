/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 21:38:49 by nfinkel           #+#    #+#             */
/*   Updated: 2018/01/24 18:36:23 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./io.h"

int			ft_vsprintf(char *restrict str, const char *restrict format,
			va_list ap)
{
	GIMME(ft_vsnprintf(str, INT_MAX + 1, format, ap));
}
