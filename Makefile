NAME = push_swap
SRCS = push_swap.c stack.c node.c tools.c algorithm.c support.c helpers.c \
	./actions/swap.c ./actions/push.c ./actions/rotate.c ./actions/rev_rotate.c
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
PRINTF_PATH = ./ft_printf
PRINTF = $(PRINTF_PATH)/libftprintf.a
UTILS_PATH = ./utils
UTILS = $(UTILS_PATH)/utils.a
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(PRINTF) $(UTILS) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(UTILS) $(PRINTF) -o $(NAME)

$(PRINTF):
	@if [ ! -d "$(PRINTF_PATH)" ]; then \
		git clone https://github.com/exhilarin/ft_printf.git $(PRINTF_PATH); \
	fi
	@make -C $(PRINTF_PATH)

$(UTILS):
	@make -C $(UTILS_PATH)

clean:
	@rm -f $(OBJS)
	@make clean -C $(PRINTF_PATH)
	@make clean -C $(UTILS_PATH)
	@rm -rf $(PRINTF) $(UTILS)

fclean: clean
	@rm -rf $(NAME) $(PRINTF)
	@make fclean -C $(PRINTF_PATH)
	@rm -f $(NAME) $(UTILS)
	@make fclean -C $(UTILS_PATH)
	@rm -rf ft_printf
	@rm -rf libft

re: fclean all

.PHONY: all clean fclean re
