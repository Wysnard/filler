/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:05:05 by vlay              #+#    #+#             */
/*   Updated: 2017/11/14 18:02:20 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_bits(unsigned long long int octet, size_t size)
{
	size_t					i;
	unsigned long long int	oct;

	if (size == 0)
		return ;
	i = 1;
	while (size)
	{
		i <<= (size == 1) ? 7 : 8;
		size -= 1;
	}
	oct = octet;
	while (i)
	{
		ft_putchar((oct & i) ? '1' : '0');
		i >>= 1;
	}
}
