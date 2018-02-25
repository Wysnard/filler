/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 21:07:27 by vlay              #+#    #+#             */
/*   Updated: 2017/12/04 21:07:29 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnchar(char c, int n, int fd)
{
	char	*str;

	if (fd < 0 || n <= 0 || !(str = ft_strnew(n)))
		return ;
	ft_memset(str, c, n);
	write(fd, str, n);
	free(str);
}
