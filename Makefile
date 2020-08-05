# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: i18316588 <i18316588@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/30 12:29:44 by ocathern          #+#    #+#              #
#    Updated: 2020/08/04 07:32:06 by i18316588        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = printf

LNAM = libft.a

LIBF = ./includes/libft

INCL = ./src/printf.h

SRCS = ./src/main.c ./src/flags.c ./src/handler.c ./src/istrue.c ./src/setup.c\
./src/logger.c ./src/int.c ./src/utils.c ./src/intgeneral.c

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