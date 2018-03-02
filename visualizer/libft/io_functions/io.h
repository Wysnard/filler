/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 18:39:27 by nfinkel           #+#    #+#             */
/*   Updated: 2018/01/25 13:27:47 by nfinkel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IO_H
# define IO_H

# include "../includes/dependencies.h"

extern int			ft_asprintf(char **ret, const char *format, ...);
extern int			ft_dprintf(int fd, const char *format, ...);
extern int			ft_fprintf(FILE *stream, const char *format, ...);
extern int			ft_printf(const char *format, ...);
extern int			ft_snprintf(char *str, size_t size, const char *format,
					...);
extern int			ft_sprintf(char *str, const char *format, ...);
extern int			ft_vasprintf(char **ret, const char *format, va_list ap);
extern int			ft_vdprintf(int fd, const char *format, va_list ap);
extern int			ft_vfprintf(FILE *stream, const char *format, va_list ap);
extern int			ft_vprintf(const char *format, va_list ap);
extern int			ft_vsprintf(char *str, const char *format, va_list ap);
extern int			ft_vsnprintf(char *str, size_t size, const char *format,
					va_list ap);

extern void			ft_fatal(const char *s);
extern void			ft_putchar(char c);
extern void			ft_putchar_fd(char c, int fd);
extern void			ft_putendl(const char *s);
extern void			ft_putendl_fd(const char *s, int fd);
extern void			ft_putnbr(int n);
extern void			ft_putnbr_fd(int n, int fd);
extern void			ft_putstr(const char *s);
extern void			ft_putstr_fd(const char *s, int fd);

extern int			get_next_line(const int fd, char **line);

#endif
