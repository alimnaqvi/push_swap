CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = main.c parse_args_make_list.c sort_and_display_ops.c \
	   push_swap.c utils_atoi.c utils_split.c utils_list.c # to be updated

OBJS = $(SRCS:.c=.o)

NAME = push_swap

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
