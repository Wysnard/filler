/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 19:59:55 by vlay              #+#    #+#             */
/*   Updated: 2017/11/06 20:00:37 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *meule_de_foin, const char *aiguille, size_t len)
{
	size_t	j;
	size_t	i;
	size_t	tmp;

	j = 0;
	if (*aiguille == '\0')
		return ((char *)meule_de_foin);
	while (meule_de_foin[j])
	{
		i = 0;
		tmp = j;
		while (meule_de_foin[j] == aiguille[i] && j < len)
		{
			j++;
			i++;
			if (!aiguille[i])
				return ((char *)&meule_de_foin[tmp]);
		}
		j = tmp;
		j++;
	}
	return (NULL);
}
