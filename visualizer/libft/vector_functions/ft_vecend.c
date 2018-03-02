/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecend.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 15:29:34 by nfinkel           #+#    #+#             */
/*   Updated: 2018/01/24 18:43:38 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./vector.h"

inline void			*ft_vecend(t_vector *vector)
{
	GIMME((char *)vector->buff + (vector->data_size * vector->len));
}
