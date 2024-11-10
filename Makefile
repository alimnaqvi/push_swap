CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = push_swap.c # to be completed
OBJS = $(SRCS:.c=.o)

NAME = push_swap # or should it be a different name?

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
