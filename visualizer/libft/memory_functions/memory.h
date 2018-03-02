/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 18:39:00 by nfinkel           #+#    #+#             */
/*   Updated: 2018/01/24 18:39:01 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY_H
# define MEMORY_H

# include "../includes/dependencies.h"

extern void			ft_bzero(void *s, size_t n);
extern void			ft_cleanup(const char *args, ...);
extern void			*ft_memalloc(size_t size);
extern void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
extern void			*ft_memchr(const void *s, int c, size_t n);
extern int			ft_memcmp(const void *s1, const void *s2, size_t n);
extern void			*ft_memcpy(void *dst, const void *src, size_t n);
extern void			ft_memdel(void **ap);
extern void			*ft_memmove(void *dst, const void *src, size_t len);
extern size_t		ft_memnccpy(void *dst, const void *src, int c, size_t n);
extern void			*ft_memset(void *b, int c, size_t len);
extern void			*ft_realloc(void *ptr, size_t size);

#endif
