# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlay <vlay@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/18 21:06:30 by vlay              #+#    #+#              #
#    Updated: 2018/02/24 21:16:32 by vlay             ###   ########.fr        #
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

SRC_FILE = main.c \
					map.c \
					piece.c \
					place.c

SRC = $(SRC_FILE:%.c=$(SRC_PATH)%.c)

OBJ = $(SRC:$(SRC_PATH)%.c=$(OBJ_PATH)%.o)

all: $(NAME)

$(NAME): $(LIBFT_PATH)$(LIBFT_NAME) $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ) -I$(INCLUDE_PATH) -L$(LIBFT_PATH) -lft

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(LIBFT_PATH)$(LIBFT_NAME)
	@mkdir -p $(OBJ_PATH)
	$(CC) -o $@ -c $< -I$(INCLUDE_PATH) $(CFLAGS)

$(LIBFT_PATH)$(LIBFT_NAME):
	make -C $(LIBFT_PATH)

clean:
	rm -Rf $(OBJ_PATH)
	make clean -C $(LIBFT_PATH)

fclean:	clean
	rm -f $(NAME) $(CHECKER)
	make fclean -C $(LIBFT_PATH)

re:	fclean all

.PHONY: all, clean, fclean, re
