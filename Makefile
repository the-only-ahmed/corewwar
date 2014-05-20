# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: team sudo <sballet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/10 21:28:36 by sudo              #+#    #+#              #
#    Updated: 2014/02/01 16:27:16 by sudo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = asm

SRC = ./srcs/asm/arg.c ./srcs/asm/check.c ./srcs/asm/error.c ./srcs/asm/list.c\
		./srcs/asm/listlabel.c ./srcs/asm/main.c ./srcs/asm/op.c ./srcs/asm/put.c\
		./srcs/asm/truc.c ./srcs/asm/type.c ./srcs/asm/get_next_line.c

HEAD = ./srcs/asm/asm.h ./srcs/asm/op.h ./srcs/asm/get_next_line.h

OBJ = arg.o check.o error.o list.o listlabel.o main.o op.o put.o\
		truc.o type.o get_next_line.o

FLAGS = -Wall -Wextra -Werror -g3

all: $(NAME)

$(NAME):
	@make -C libft
	@gcc $(FLAGS) -I libft/includes -c $(SRC)
	@gcc $(OBJ) -L libft -lft -o $(NAME)
	mv $(OBJ) ./obj/

clean:
	@make -C libft clean
	cd ./obj;rm -f $(OBJ);cd ..

fclean: clean
	@make -C libft fclean
	rm -f $(NAME)

prog: fclean all

re: fclean all

.PHONY: all re fclean
