/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 21:07:47 by vlay              #+#    #+#             */
/*   Updated: 2017/12/04 21:07:51 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putwstr_fd(wchar_t *wstr, int fd)
{
	size_t	i;

	i = 0;
	while (wstr[i])
		ft_putwchar_fd(wstr[i++], fd);
}

void	ft_putwstr(wchar_t *wstr)
{
	ft_putwstr_fd(wstr, 1);
}
