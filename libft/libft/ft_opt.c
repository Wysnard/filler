/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <vlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 15:47:19 by vlay              #+#    #+#             */
/*   Updated: 2017/12/19 20:38:21 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_opt(int argc, char **arg, char *opt)
{
	int		i;
	int		j;
	char	*res;
	char	save[2];

	i = 0;
	save[1] = '\0';
	if (!opt || !arg || !(res = ft_strnew(ft_strlen(opt))))
		return (NULL);
	while (i < argc)
	{
		j = 1;
		if (*arg[i] == '-')
			while (arg[i][j])
			{
				if (ft_strchr(opt, arg[i][j]))
					if (!ft_strchr(res, (save[0] = arg[i][j])))
						ft_strcat(res, save);
				j++;
			}
		i++;
	}
	return (res);
}
