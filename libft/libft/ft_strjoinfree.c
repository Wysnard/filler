/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 21:08:09 by vlay              #+#    #+#             */
/*   Updated: 2017/12/04 21:08:14 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinfree(char *s1, char *s2)
{
	char	*result;

	if (!(result = ft_strjoin(s1, s2)))
		return (NULL);
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	return (result);
}
