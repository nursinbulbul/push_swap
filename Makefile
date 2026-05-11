NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -I.

SRCS =	algorithms/selection_sort.c \
		algorithms/chunk_based_sort.c \
		algorithms/radix_sort.c \
		algorithms/adaptive.c \
		algorithms/few_sort.c \
		operations/push.c \
		operations/swap.c \
		operations/rotate.c \
		operations/reverse_rotate.c \
		operations/printcontrol.c \
		operations/printcontrol2.c \
		utils/algorithm_utils.c \
		utils/bench_utils.c \
		utils/main_utils.c \
		utils/node_utils.c \
		utils/stack_utils.c \
		utils/selection_utils.c\
		bench_print.c \
		error.c \
		main.c \
		parsing.c 

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re