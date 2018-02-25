/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <vlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 19:50:19 by vlay              #+#    #+#             */
/*   Updated: 2017/11/26 19:27:49 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t				i;
	unsigned	char	*sr;
	unsigned	char	*sd;

	i = 0;
	sr = (unsigned char *)s1;
	sd = (unsigned char *)s2;
	while (sr[i] && sd[i] && sr[i] == sd[i])
		i++;
	return (sr[i] - sd[i]);
}
