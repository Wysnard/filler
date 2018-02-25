/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pileinit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <vlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:59:27 by vlay              #+#    #+#             */
/*   Updated: 2017/12/07 06:27:08 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_pile	*ft_pileinit(void)
{
	t_pile *pile;

	pile = malloc(sizeof(*pile));
	pile->info_size = 0;
	pile->first = NULL;
	pile->info = NULL;
	return (pile);
}
