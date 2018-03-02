# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/28 18:20:14 by nfinkel           #+#    #+#              #
#    Updated: 2018/02/03 14:10:38 by nfinkel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#################
##  VARIABLES  ##
#################

#	Environment
OS :=						$(shell uname)

#	Output
NAME :=						libft.a
DYN_NAME :=					${NAME:a=so}

#	Compiler
CC :=						gcc
VERSION :=					-std=c11

ifneq ($(OS), Linux)
	FLAGS +=				-Wall -Wextra -Werror
endif

DYN_FLAG :=					-shared
HEADERS :=					-I ./includes/

#	Directories
OBJDIR :=					./build/
DYN_OBJDIR :=				./dyn_build/

API_DIR :=					./api_functions/
CHARACTER_DIR :=			./character_functions/
DLIST_DIR :=				./dlist_functions/
INPUT_OUTPUT_DIR :=			./io_functions/
LINKEDLIST_DIR :=			./linkedlist_functions/
MATH_DIR :=					./math_functions/
MEMORY_DIR :=				./memory_functions/
PRINTF_DIR :=				./ft_printf/
STRING_DIR :=				./string_functions/
VECTOR_DIR :=				./vector_functions/

#	Sources
API +=						ft_ctime.c ft_getenv.c
CHARACTER +=				ft_isalpha.c ft_isdigit.c ft_isprint.c
CHARACTER +=				ft_isalnum.c ft_isascii.c ft_toupper.c
CHARACTER +=				ft_islower.c ft_isupper.c ft_tolower.c
DLIST +=					ft_dlstadd.c ft_dlstappend.c ft_dlstnew.c
INPUT_OUTPUT +=				ft_asprintf.c ft_vasprintf.c ft_vsprintf.c
INPUT_OUTPUT +=				ft_dprintf.c ft_vdprintf.c ft_printf.c ft_vprintf.c
INPUT_OUTPUT +=				ft_snprintf.c ft_vsnprintf.c ft_sprintf.c
INPUT_OUTPUT +=				ft_fprintf.c ft_vfprintf.c ft_fatal.c
INPUT_OUTPUT +=				ft_putchar.c ft_putchar_fd.c ft_putendl.c
INPUT_OUTPUT +=				ft_putnbr.c ft_putnbr_fd.c ft_putendl_fd.c
INPUT_OUTPUT +=				ft_putstr.c ft_putstr_fd.c get_next_line.c
LINKEDLIST +=				ft_lstnew.c ft_lstadd.c ft_lstappend.c
LINKEDLIST +=				ft_lstdel.c ft_lstdelone.c
LINKEDLIST +=				ft_lstfree.c ft_lstsnipe.c
LINKEDLIST += 				ft_lstiter.c ft_lstmap.c
LINKEDLIST +=				ft_lstgetnode.c ft_lstsize.c
MATH +=						ft_nextpower2.c
MEMORY +=					ft_bzero.c ft_memmove.c
MEMORY +=					ft_cleanup.c ft_memdel.c
MEMORY +=					ft_memalloc.c ft_memset.c ft_realloc.c
MEMORY +=					ft_memcpy.c ft_memccpy.c ft_memnccpy.c
MEMORY +=					ft_memchr.c ft_memcmp.c
PRINTF +=					pf_ansi_color.c pf_fill_buffer.c
PRINTF +=					pf_buff_format.c pf_get_flags.c
PRINTF +=					pf_output_char.c pf_output_string.c
PRINTF +=					pf_output_extras.c pf_output_noprint.c
PRINTF +=					pf_output_double.c pf_output_pointer.c
PRINTF +=					pf_output_signed.c pf_output_unsigned.c
STRING +=					ft_atoi.c ft_itoa.c
STRING +=					ft_intlen.c ft_strlen.c
STRING +=					ft_strcat.c ft_strncat.c ft_strlcat.c
STRING +=					ft_strchr.c ft_strrchr.c
STRING +=					ft_strclr.c ft_strdel.c ft_strnew.c
STRING +=					ft_strcmp.c ft_strncmp.c
STRING +=					ft_strcpy.c ft_strncpy.c ft_strdup.c ft_strndup.c
STRING +=					ft_strequ.c ft_strnequ.c
STRING +=					ft_striter.c ft_striteri.c
STRING +=					ft_strjoin.c ft_strsub.c ft_strtrim.c
STRING +=					ft_strmap.c ft_strmapi.c
STRING +=					ft_strstr.c ft_strnstr.c
STRING +=					ft_strrev.c ft_strrevcpy.c
STRING +=					ft_strsplit.c ft_strrewrite.c
VECTOR +=					ft_vecalloc.c ft_vecbegin.c ft_vecend.c
VECTOR +=					ft_vecpush.c ft_vecnpush.c ft_vecgrow.c
VECTOR +=					ft_vecclear.c ft_vecdel.c

DYN_OBJECTS =				$(patsubst %.c,$(DYN_OBJDIR)%.o,$(SRCS))
OBJECTS =					$(patsubst %.c,$(OBJDIR)%.o,$(SRCS))

SRCS +=						$(API)
SRCS +=						$(CHARACTER)
SRCS +=						$(DLIST)
SRCS +=						$(INPUT_OUTPUT)
SRCS +=						$(LINKEDLIST)
SRCS +=						$(MATH)
SRCS +=						$(MEMORY)
SRCS +=						$(PRINTF)
SRCS +=						$(STRING)
SRCS +=						$(VECTOR)

vpath %.c $(API_DIR)
vpath %.c $(CHARACTER_DIR)
vpath %.c $(DLIST_DIR)
vpath %.c $(INPUT_OUTPUT_DIR)
vpath %.c $(LINKEDLIST_DIR)
vpath %.c $(MATH_DIR)
vpath %.c $(MEMORY_DIR)
vpath %.c $(PRINTF_DIR)
vpath %.c $(STRING_DIR)
vpath %.c $(VECTOR_DIR)

#################
##    RULES    ##
#################

all: $(NAME)

$(NAME): $(OBJECTS)
	@ar rcs $@ $(patsubst %.c,$(OBJDIR)%.o,$(notdir $(SRCS)))
	@ranlib $@

$(OBJECTS): | $(OBJDIR)

$(OBJDIR):
	@mkdir -p $@

$(OBJDIR)%.o: %.c
	@$(CC) $(VERSION) $(DEBUG)$(FLAGS) $(HEADERS) -c $< -o $@

$(DYN_OBJECTS): | $(DYN_OBJDIR)

$(DYN_OBJDIR):
	@mkdir -p $@

$(DYN_OBJDIR)%.o: %.c
	@$(CC) $(VERSION) $(FLAGS) $(HEADERS) -fpic -c $< -o $@

clean:
	@/bin/rm -rf $(OBJDIR)
	@/bin/rm -rf $(DYN_OBJDIR)

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f $(DYN_NAME)

noflags: FLAGS :=
noflags: re

re: fclean all

so: fclean $(DYN_OBJECTS)
	@$(CC) $(VERSION) $(DYN_FLAG) -o $(DYN_NAME) $(patsubst %.c,$(DYN_OBJDIR)%.o,$(notdir $(SRCS)))

.PHONY: all cat clean fclean noflags re so
