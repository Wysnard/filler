/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 16:02:38 by nfinkel           #+#    #+#             */
/*   Updated: 2018/01/24 15:17:26 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf_private.h"

int			ft_vdprintf(int fd, const char *restrict format, va_list ap)
{
	char				buff[PRINTF_BUFFSIZE + 1];
	static t_printf		*data = NULL;

	if (!data)
	{
		FAILZ(data = (t_printf *)malloc(sizeof(t_printf)), -1);
		data->pf_type = E_PRINTF;
	}
	data->pf_buffer = buff;
	data->pf_len = 0;
	data->fd = fd;
	ft_memset(data->ansi_colors, '\0', ANSI_STRING_BUFFSIZE);
	data->error = 0;
	data->index = 0;
	data->non_printable = 0;
	data->positional = E_UNDEFINED;
	va_copy(data->ap, ap);
	pf_buff_format(data, format);
	write(fd, data->pf_buffer, data->index);
	data->pf_len -= data->non_printable;
	va_end(data->ap);
	if (data->positional == E_NON_POSITIONAL)
		va_end(data->arg);
	GIMME(data->error ? -1 : (int)data->pf_len);
}
