# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nfinkel <nfinkel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/01 15:25:26 by nfinkel           #+#    #+#              #
#    Updated: 2018/02/08 11:20:13 by fsabatie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#################
##  VARIABLES  ##
#################

#	Environment
OS :=						$(shell uname)

#	Output
NAME :=						visualizer

#	Compiler
CC :=						gcc
VERSION :=					-std=c11

#	Flags:
ifneq ($(OS), Linux)
	FLAGS +=				-Wall -Wextra -Werror
endif

HEADERS :=					-I ./includes/

#	Directories
LIBFTDIR :=					./libft/
LIBMLXDIR :=				./ressources/mlx/
OBJDIR :=					./build/

SRCS_DIR :=					./srcs/

#	Sources
SRC +=						main.c errhdl.c hooks.c move.c squares.c strhdl.c

OBJECTS =					$(patsubst %.c,$(OBJDIR)%.o,$(SRCS))

SRCS +=						$(SRC)

vpath %.c $(SRCS_DIR)

#################
##    RULES    ##
#################

all: libft mlx $(NAME)

$(NAME): $(OBJECTS)
	@$(CC) $(FLAGS) $(patsubst %.c,$(OBJDIR)%.o,$(notdir $(SRCS))) -L $(LIBFTDIR) -lft -L $(LIBMLXDIR) -lmlx -framework OpenGL -framework AppKit -o $@

$(OBJECTS): | $(OBJDIR)

$(OBJDIR):
	@mkdir -p $@

$(OBJDIR)%.o: %.c
	@$(CC) $(VERSION) $(DEBUG)$(FLAGS)$(O_FLAG) $(HEADERS) -c $< -o $@

libft:
	@cd $(LIBFTDIR) && make

mlx:
	@cd $(LIBMLXDIR) && make

clean:
	@/bin/rm -rf $(OBJDIR)
	@cd $(LIBFTDIR) && make clean
	@cd $(LIBMLXDIR) && make clean


fclean: clean
	@/bin/rm -f $(NAME)
	@cd $(LIBFTDIR) && make fclean
	@cd $(LIBMLXDIR) && make fclean

re: fclean all

.PHONY: all clean fclean libft mlx re
