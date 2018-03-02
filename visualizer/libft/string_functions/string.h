/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 18:43:13 by nfinkel           #+#    #+#             */
/*   Updated: 2018/01/27 14:56:02 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_H
# define STRING_H

# include "../includes/dependencies.h"

extern int		ft_atoi(const char *str);
extern char		*ft_itoa(int n);
extern size_t	ft_intlen(intmax_t n);
extern char		*ft_strcat(char *s1, const char *s2);
extern char		*ft_strchr(const char *s, int c);
extern void		ft_strclr(char *s);
extern int		ft_strcmp(const char *s1, const char *s2);
extern char		*ft_strcpy(char *dst, const char *src);
extern void		ft_strdel(char **as);
extern char		*ft_strdup(const char *s1);
extern int		ft_strequ(const char *s1, const char *s2);
extern void		ft_striter(char *s, void (*f)(char *));
extern void		ft_striteri(char *s, void (*f)(unsigned int, char *));
extern char		*ft_strjoin(char *s1, const char *s2, bool free);
extern size_t	ft_strlen(const char *s);
extern size_t	ft_strlcat(char *dst, const char *src, size_t size);
extern char		*ft_strmap(const char *s, char (*f)(char));
extern char		*ft_strmapi(const char *s, char (*f)(unsigned int, char));
extern char		*ft_strncat(char *s1, const char *s2, size_t n);
extern char		*ft_strndup(const char *s, size_t n);
extern int		ft_strnequ(const char *s1, const char *s2, size_t n);
extern char		*ft_strnew(size_t size);
extern int		ft_strncmp(const char *s1, const char *s2, size_t n);
extern char		*ft_strncpy(char *dst, const char *src, size_t n);
extern char		*ft_strnstr(const char *big, const char *little, size_t n);
extern char		*ft_strrchr(const char *s, int c);
extern char		*ft_strrev(char *const s);
extern char		*ft_strrevcpy(const char *const s);
extern int		ft_strrewrite(char *big, const char *little, const char *fill);
extern char		**ft_strsplit(const char *s, char c);
extern char		*ft_strstr(const char *big, const char *little);
extern char		*ft_strsub(char *s, unsigned int start, size_t len, bool free);
extern char		*ft_strtrim(char *s, bool free);

#endif
