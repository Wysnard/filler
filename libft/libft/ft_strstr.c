/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 20:01:48 by vlay              #+#    #+#             */
/*   Updated: 2017/11/10 18:52:17 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *meule_de_foin, const char *aiguille)
{
	int		len;
	int		j;

	j = 0;
	if (*aiguille == '\0')
		return ((char *)meule_de_foin);
	len = ft_strlen(aiguille);
	while (meule_de_foin[j])
	{
		if (ft_strnequ(&meule_de_foin[j], aiguille, len))
			return ((char *)&meule_de_foin[j]);
		j++;
	}
	return (NULL);
}
