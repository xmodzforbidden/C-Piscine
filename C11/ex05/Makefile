NAME=do-op
CC=cc
CFLAGS= -Wall -Wextra -Werror
SRCS= srcs/ft_do_op.c srcs/mod.c srcs/add.c srcs/ft_putnbr.c srcs/mult.c srcs/div.c srcs/ft_selecte_op.c srcs/sub.c srcs/ft_atoi.c srcs/main.c
HEAD= include
OBJS= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

fclean: clean
	rm -f $(NAME)

clean:
	rm -f $(OBJS)

re: fclean all

.PHONY: re clean fclean all
	
