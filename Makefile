# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nblackie <nblackie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/30 12:29:44 by ocathern          #+#    #+#              #
#    Updated: 2020/09/01 19:18:04 by nblackie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = printf

LNAM = libft.a

LIBF = ./includes/libft

INCL = ./src/printf.h

SRCS = ./src/main.c ./src/flags.c ./src/handler.c ./src/istrue.c ./src/setup.c\
./src/logger.c ./src/utils.c ./src/general.c ./src/int.c ./src/unsignedint.c\
./src/signedint.c src/octal.c ./src/octalcore.c ./src/hex.c ./src/hexcore.c\
./src/char.c ./src/float.c
OBJ =  $(subst .c,.o,$(SRCS))

CCFL = gcc

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBF) re
	@$(CCFL) -L $(LIBF) -lft $(SRCS) -I $(LIBF) -I $(INCL) -o $(NAME) -g
%.o: %.c
	@$(CCFL) -I $(INCL) $< -c -o $@ -g

clean:
	@make -C $(LIBF) clean
	@/bin/rm -f ./src/*.o

fclean: clean
	@make -C $(LIBF) fclean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re