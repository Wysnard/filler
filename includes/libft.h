/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlay <vlay@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 17:06:53 by vlay              #+#    #+#             */
/*   Updated: 2018/02/25 16:43:43 by vlay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>
# include <wchar.h>
# include <stdint.h>
# include "printf.h"

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

typedef	struct		s_pile
{
	t_list			*first;
	void			*info;
	size_t			info_size;
}					t_pile;

typedef	struct		s_btree
{
	struct s_btree	*right;
	struct s_btree	*left;
	void			*content;
	size_t			content_size;
}					t_btree;

# define BUFF_SIZE 32

typedef struct		s_clist
{
	int				fd;
	int				offset;
	char			buff[BUFF_SIZE + 1];
	struct s_clist	*next;
}					t_clist;

int					get_next_line(const int fd, char **line);

void				ft_putchar(char c);
void				ft_putstr(char const *s);
size_t				ft_strlen(const char *s);

void				*ft_memset (void *s, int c, size_t len);
void				ft_bzero(void *s, size_t len);
void				*ft_memcpy(void *dest, const void *src, size_t len);
void				*ft_memccpy(void *dest, const void *src, int c, size_t len);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);

char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t len);
char				*ft_strdup(const char *s);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t n);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *meule_de_foin, const char *aiguille);
char				*ft_strnstr(const char	*meule_de_foin,
					const char *aiguille, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *nptr);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_islower(int c);
int					ft_isupper(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);

void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(const char *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putendl(char const *s);
void				ft_putnbr(int nb);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);

t_list				*ft_lstnew(void const *content, size_t content_size);
t_list				*ft_lstsnew(void *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstpushadd(t_list **alst, t_list *new);
void				ft_lstrev(t_list **list);
int					ft_lstrotate(t_list **alst);
int					ft_lstreverserotate(t_list **alst);
size_t				ft_lstlen(t_list *list);
void				ft_lstfrontbacksplit(t_list *source,
					t_list **frontref, t_list **backref);
void				ft_lstdelall(t_list **list);
void				ft_lstpush(t_list **alst, t_list *new);
void				ft_lstinsert(t_list **alst, t_list *new,
					int (*cmpf)(void *, void *));
t_list				*ft_lstfilter(t_list *list,
					int (*f)(t_list *elem), void (*del)(void *, size_t));
void				ft_lstmergesort(t_list **list, int (*cmpf)(void *, void *));

void				ft_dlstcut(t_list *list);

void				ft_clstadd(t_list **list, t_list *new);

void				ft_pileadd(t_pile *pile, void *info, size_t content_size);
void				*ft_piledel(t_pile *pile);
t_pile				*ft_pileinit(void);
void				ft_pilepushadd(t_pile *pile, void *info,
					size_t content_size);

void				ft_pilecadd(t_pile *pile, void *info, size_t content_size);
void				*ft_pilecdel(t_pile *pile);

t_btree				*ft_btreecreate(void *item, size_t content_size);
void				ft_btreedel(t_btree *tr);
t_btree				*ft_btreejoin(t_btree *gauche, t_btree *droite, void *item);
void				ft_btree_apply_prefix(t_btree *root,
						void (*applyf)(void *));
void				ft_btree_apply_infix(t_btree *root, void(*applyf)(void *));
void				ft_btree_apply_suffix(t_btree *root, void(*applyf)(void *));
void				ft_btreeinsert(t_btree **root, void *item,
						size_t content_size, int (*cmpf)(void *, void *));
int					ft_btreelvlct(t_btree *root);
void				ft_btree_rev_infix(t_btree *root, void(*applyf)(void *));
void				*ft_btreesearch(t_btree *root,
						void *data_ref, int (*cmpf)(void *, void *));

char				*ft_strndup(const char *s, size_t n);
int					ft_power(int nb, int power);
char				*ft_convert_base(char *nbr, char *base_from, char *base_to);
void				ft_strrev(char *s);
char				*ft_utoa(uintmax_t nbr, char const *base_chr);
char				*ft_dtoa(double nbr, size_t	size);
void				ft_print_bits(unsigned long long int octet, size_t size);
char				*ft_strtrijoin(char *s1, char *s2, char *s3);
int					ft_intlen(intmax_t nb, int base);
void				ft_swap(uintmax_t *s1, uintmax_t *s2);
size_t				ft_sqr(int	nb);
char				*ft_imtoa_base(intmax_t nbr, char *base_to);
char				*ft_strnrchr(const char *s, int c, size_t n);
intmax_t			ft_atoim(const char *nptr);
char				*ft_strpbrk(const char *s, const char *accept);
void				ft_putnchar(char c, int n, int fd);
char				*ft_strjoinfree(char *s1, char *s2);
void				ft_putwchar_fd(wchar_t chr, int fd);
void				ft_putwchar(wchar_t chr);
void				ft_putwstr_fd(wchar_t *wstr, int fd);
void				ft_putwstr(wchar_t *wstr);
size_t				ft_wcslen(wchar_t	*wstr);
wchar_t				*ft_wcscpy(wchar_t *dest, const wchar_t *src);
wchar_t				*ft_wcsncpy(wchar_t *dest, const wchar_t *src, size_t n);
wchar_t				*ft_wcsnew(size_t len);
wchar_t				*ft_wcsdup(wchar_t	*wcs);
wchar_t				*ft_wcsndup(wchar_t	*wcs, size_t n);
wchar_t				*ft_wcsjoinfree(wchar_t *w1, wchar_t *w2);
char				*ft_strjoinpush(char *s1, char *s2);
size_t				ft_strchri(char *str, int c);
void				ft_ptrswap(void **p1, void **p2);
void				ft_errexit(char *str);
char				*ft_strjoinadd(char **s1, char *s2);
void				ft_qsort(int tableau[], int begin, int end);
char				*ft_opt(int argc, char **arg, char *opt);
char				*ft_strmultijoin(size_t nbarg, ...);
size_t				ft_uintlen(uintmax_t nb, unsigned base);
size_t				ft_intchri(int *str, int c, size_t len);
intmax_t			ft_intgetmin(unsigned nb, ...);
size_t				ft_strclen(char *str, int c);
void				ft_tabdel(char **tab);

void				ft_pileadd(t_pile *pile, void *info, size_t content_size);
t_pile				*ft_pileinit(void);
void				*ft_piledel(t_pile *pile);
void				ft_pilepushadd(t_pile *pile,
					void *info, size_t content_size);
void				ft_pilepush(t_pile *pile, void *info, size_t content_size);

int					ft_printf(const char *arg1, ...);

#endif
