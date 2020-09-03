NAME	= libftprintf.a

SRCDIR = ./src/
SRCNAMES = $(shell ls $(SRCDIR) | grep -E ".+\.c")
SRC = $(addprefix $(SRCDIR), $(SRCNAMES))
OBJ		= $(SRC:.c=.o)

INC     = ./include
LIBFT	= ./include/libft

CC		= gcc
# CFLAGS  = -Wall -Wextra -Werror
CFLAGS  = -Wall -Wextra
AR      = ar
ARFLAGS = rcs

all: $(NAME)

$(NAME): $(OBJ)
	@$(AR) rc $(NAME) $(OBJ)

%.o: %.c
	@$(CC) -o $@ $(CFLAGS) -I $(INC) -c $<

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all