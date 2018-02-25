/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbprec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 18:20:54 by vlay              #+#    #+#             */
/*   Updated: 2017/12/04 18:20:55 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_nbprec(char **str, intmax_t i)
{
	char	*zero;
	char	*tmp;
	char	save[3];

	if (i < 1)
		return ;
	if (!(zero = ft_strnew(i)))
		exit(EXIT_FAILURE);
	ft_memset(zero, '0', i);
	zero[i] = '\0';
	tmp = zero;
	if (**str == '-')
	{
		ft_strcpy(save, "-");
		zero = ft_strjoin(save, tmp);
		ft_strcpy(*str, (*str) + 1);
		free(tmp);
	}
	*str = ft_strjoinfree(zero, *str);
}
