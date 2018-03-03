# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlay <vlay@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/18 21:34:53 by vlay              #+#    #+#              #
#    Updated: 2018/03/03 15:57:59 by vlay             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

INCLUDE_PATH = ../includes

INCLUDE = libft.h \
			printf.h

CFLAGS = -Werror -Wall -Wextra -I$(INCLUDE_PATH)

SRC_PATH = printf/

LIBFT_PATH = libft/

LIBFT_FILE = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c \
		ft_isascii.c ft_isdigit.c ft_islower.c ft_isupper.c \
		ft_isprint.c ft_itoa.c ft_memalloc.c ft_memccpy.c \
		ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c \
		ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putchar.c \
		ft_putendl_fd.c ft_putendl.c ft_putnbr_fd.c ft_putnbr.c \
		ft_putstr_fd.c ft_putstr.c ft_strcat.c ft_strchr.c \
		ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c \
		ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c \
		ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c \
		ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c \
		ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c \
		ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c \
		ft_tolower.c ft_toupper.c \
		ft_lstadd.c ft_lstdel.c ft_lstfilter.c \
		ft_lstdelall.c ft_lstdelone.c \
		ft_lstfrontbacksplit.c ft_lstiter.c \
		ft_lstlen.c ft_lstmap.c \
		ft_lstnew.c ft_lstpushadd.c \
		ft_lstrev.c ft_lstrotate.c \
		ft_lstreverserotate.c ft_lstpush.c \
		ft_lstsnew.c ft_lstmergesort.c \
		ft_dlstcut.c \
		ft_clstadd.c \
		ft_dtoa.c ft_intlen.c \
		ft_power.c ft_print_bits.c \
		ft_strndup.c ft_strrev.c \
		ft_strtrijoin.c ft_swap.c \
		ft_utoa.c ft_imtoa.c ft_strnrchr.c \
		ft_atoim.c ft_strpbrk.c ft_putnchar.c \
		ft_strjoinfree.c ft_putwchar.c ft_putwstr.c \
		ft_wcslen.c ft_wcscpy.c ft_wcsncpy.c \
		ft_wcsnew.c ft_wcsdup.c ft_wcsndup.c \
		ft_wcsjoinfree.c ft_strjoinpush.c ft_strchri.c \
		ft_qsort.c ft_opt.c ft_strmultijoin.c \
		ft_uintlen.c ft_intchri.c ft_intgetmin.c \
		ft_strclen.c ft_tabdel.c ft_strrchri.c \
		ft_pileadd.c ft_pileinit.c ft_piledel.c \
		ft_pilepushadd.c ft_pilepush.c \
		ft_pilecadd.c ft_pilecdel.c \
		ft_errexit.c ft_opt.c ft_lstinsert.c \
		ft_ptrswap.c get_next_line.c ft_strjoinadd.c \
		ft_btree_apply_infix.c ft_btree_apply_prefix.c ft_btree_apply_suffix.c \
		ft_btree_rev_infix.c ft_btreecreate.c ft_btreedel.c \
		ft_btreeinsert.c ft_btreejoin.c ft_btreelvlct.c \
		ft_btreesearch.c

LIBFT = $(LIBFT_FILE:%.c=$(LIBFT_PATH)%.c)

OBJ_PATH = obj/

SRC_FILE = printf.c \
						init.c \
						process.c \
						print_char.c \
						print_str.c \
						print_int.c \
						print_unsigned.c \
						print_hexa.c \
						print_octal.c \
						print_bits.c \
						print_n.c \
						flags.c \
						zero.c \
						nbprec.c \
						space.c

SRC = $(SRC_FILE:%.c=$(SRC_PATH)%.c)

OBJ = $(LIBFT:$(LIBFT_PATH)%.c=$(OBJ_PATH)%.o) $(SRC:$(SRC_PATH)%.c=$(OBJ_PATH)%.o)

INC = $(INCLUDE:%.h=$(INCLUDE_PATH)%.h)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $@ $^
	@ranlib $@

$(OBJ_PATH)%.o: $(LIBFT_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) -o $@ -c $<

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) -o $@ -c $^ $(CFLAGS)

clean:
	rm -Rf $(OBJ_PATH)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all, clean, fclean, re, norme
