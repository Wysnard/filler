/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <vlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 21:24:45 by vlay              #+#    #+#             */
/*   Updated: 2017/12/18 21:20:28 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include "libft.h"
# define NBPRT	12

typedef	struct	s_file
{
	intmax_t	ct;
	char		flags[20];
	uintmax_t	nb;
	intmax_t	precision;
	enum
	{
		none,
		hh,
		h,
		l,
		ll,
		j,
		z
	}			convert;
}				t_file;

int				ft_printf(const char *arg1, ...);

void			ft_init_flags(t_file *file);
int				ft_process(char **start, t_file *file, va_list *ap);
int				ft_flags(char **start, t_file *file, va_list *ap);
void			ft_putzero(char **str, size_t *i, char *prefix, t_file *file);
void			ft_nbprec(char **str, intmax_t i);
void			ft_putspace(char **str, size_t *i, int mode);
void			ft_putwspace(wchar_t **str, size_t *i);

int				ft_print_char(va_list *ap, t_file *file);
int				ft_print_str(va_list *ap, t_file *file);
int				ft_print_int(va_list *ap, t_file *file);
int				ft_print_unsigned(va_list *ap, t_file *file);
int				ft_print_hexa(va_list *ap, t_file *file);
int				ft_print_exa(va_list *ap, t_file *file);
int				ft_print_octal(va_list *ap, t_file *file);
int				ft_print_pointer(va_list *ap, t_file *file);
int				ft_print_wstr(va_list *ap, t_file *file);
int				ft_print_perc(va_list *ap, t_file *file);
int				ft_print_b(va_list *ap, t_file *file);
int				ft_print_n(va_list *ap, t_file *file);

uintmax_t		ft_get_type_u(va_list *ap, t_file *file);
intmax_t		ft_get_type_int(va_list *ap, t_file *file);
size_t			ft_wstrlen(wchar_t	*wstr);
size_t			ft_wcharlen(wchar_t	wc);

#endif
