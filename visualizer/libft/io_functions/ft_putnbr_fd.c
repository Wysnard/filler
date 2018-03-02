/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 10:26:26 by nfinkel           #+#    #+#             */
/*   Updated: 2018/01/24 18:35:40 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../string_functions/string.h"

void			ft_putnbr_fd(int n, int fd)
{
	char				buff[12];
	int					k;
	unsigned int		nb;

	nb = (n < 0 ? -n : n);
	k = -1;
	if (n == 0)
		buff[++k] = '0';
	while (nb > 0)
	{
		buff[++k] = nb % 10 + '0';
		nb /= 10;
	}
	if (n < 0)
		buff[++k] = '-';
	buff[++k] = '\0';
	write(fd, ft_strrev(buff), ft_strlen(buff));
}
