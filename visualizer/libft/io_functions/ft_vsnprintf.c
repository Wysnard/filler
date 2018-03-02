/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsnprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 21:07:07 by nfinkel           #+#    #+#             */
/*   Updated: 2018/01/24 15:15:55 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf_private.h"

int			ft_vsnprintf(char *restrict str, size_t size,
			const char *restrict format, va_list ap)
{
	static t_printf		*data = NULL;

	if (!size)
		KTHXBYE;
	ft_strclr(str);
	if (!data)
	{
		FAILZ(data = (t_printf *)malloc(sizeof(t_printf)), -1);
		data->pf_type = E_SPRINTF;
	}
	data->pf_buffer = str;
	data->pf_len = 0;
	ft_memset(data->ansi_colors, '\0', ANSI_STRING_BUFFSIZE);
	data->error = 0;
	data->index = size - 1;
	data->non_printable = 0;
	data->positional = E_UNDEFINED;
	va_copy(data->ap, ap);
	pf_buff_format(data, format);
	data->pf_buffer[data->pf_len] = '\0';
	data->pf_len -= data->non_printable;
	va_end(data->ap);
	if (data->positional == E_NON_POSITIONAL)
		va_end(data->arg);
	GIMME(data->error ? -1 : (int)data->pf_len);
}
