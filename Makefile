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

SRCDIR = ./src/
SRCNAMES = $(shell ls $(SRCDIR) | grep -E ".+\.c")
SRC = $(addprefix $(SRCDIR), $(SRCNAMES))
INC = ./include/
BUILDDIR = ./objs/
BUILDOBJS = $(addprefix $(BUILDDIR), $(SRCNAMES:.c=.o))

LIBDIR = ./include/libft/
LIBFT = ./include/libft/libft.a
LIBINC = ./include/libft/

CC = gcc
# CFLAGS = -Wall -Werror -Wextra
CFLAGS = -Wall -Wextra

DEBUG = -g

all: $(BUILDDIR) $(LIBFT) $(NAME)

$(BUILDDIR):
	mkdir -p $(BUILDDIR)

$(BUILDDIR)%.o:$(SRCDIR)%.c
	$(CC) $(CFLAGS) -I$(LIBINC) -I$(INC) -o $@ -c $<

$(NAME): $(BUILDOBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(BUILDOBJS) $(LIBFT)

$(LIBFT):
	make -C $(LIBDIR)

clean:
	rm -rf $(BUILDDIR)
	make -C $(LIBDIR) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBDIR) fclean

re: fclean all

.PHONY: all fclean clean re