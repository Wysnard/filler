# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlay <vlay@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/18 21:06:30 by vlay              #+#    #+#              #
#    Updated: 2018/03/03 16:00:22 by vlay             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = vlay.filler

CC = gcc

CFLAGS = -Wall -Wextra -Iincludes

SRC_PATH = srcs/

LIBFT_NAME = libft.a

LIBFT_PATH = libft/

OBJ_PATH = obj/

INCLUDE_PATH = includes/

INCLUDE = filler.h

SRC_FILE = main.c \
					map.c \
					piece.c \
					place.c \
					distcalc.c \
					win.c

SRC = $(SRC_FILE:%.c=$(SRC_PATH)%.c)

OBJ = $(SRC:$(SRC_PATH)%.c=$(OBJ_PATH)%.o)

INC = $(INCLUDE:%.h=$(INCLUDE_PATH)%.h)

all: $(NAME)

$(NAME): $(LIBFT_PATH)$(LIBFT_NAME) $(OBJ) $(INC)
	$(CC) $(CFLAGS) -o $@ $(OBJ) -I$(INCLUDE_PATH) -L$(LIBFT_PATH) -lft

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(LIBFT_PATH)$(LIBFT_NAME) $(INCLUDE_PATH)$(INCLUDE)
	@mkdir -p $(OBJ_PATH)
	$(CC) -o $@ -c $< -I$(INCLUDE_PATH) $(CFLAGS)

$(LIBFT_PATH)$(LIBFT_NAME): $(INCLUDE_PATH)libft.h
	make -C $(LIBFT_PATH)

clean:
	rm -Rf $(OBJ_PATH)
	make clean -C $(LIBFT_PATH)

fclean:	clean
	rm -f $(NAME) $(CHECKER)
	make fclean -C $(LIBFT_PATH)

re:	fclean all

.PHONY: all, clean, fclean, re
