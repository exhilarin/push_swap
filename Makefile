NAME = push_swap
BONUS = checker
SRCS = push_swap.c stack.c node.c tools.c algorithm.c support.c helpers.c \
	./actions/swap.c ./actions/push.c ./actions/rotate.c ./actions/rev_rotate.c
BSRCS = ./bonus/push_swap_bonus.c ./bonus/stack_bonus.c ./bonus/node_bonus.c ./bonus/tools_bonus.c ./bonus/algorithm_bonus.c \
	 ./bonus/support_bonus.c ./bonus/helpers_bonus.c ./bonus/actions_bonus/swap_bonus.c ./bonus/actions_bonus/push_bonus.c \
	 ./bonus/actions_bonus/rotate_bonus.c ./bonus/actions_bonus/rev_rotate_bonus.c ./bonus/checker_bonus.c
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
PRINTF_PATH = ./ft_printf
PRINTF = $(PRINTF_PATH)/libftprintf.a
GNL_PATH = ./bonus/get_next_line
GNL = $(GNL_PATH)/get_next_line.c $(GNL_PATH)/get_next_line_utils.c
BONUS_UTILS_PATH= ./bonus/utils_bonus
BONUS_UTILS = $(BONUS_UTILS_PATH)/utils_bonus.a
UTILS_PATH = ./utils
UTILS = $(UTILS_PATH)/utils.a
OBJS = $(SRCS:.c=.o)
BOBJS = $(BSRCS:.c=.o)

all: $(NAME)

$(NAME): $(PRINTF) $(UTILS) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(UTILS) $(PRINTF) -o $(NAME)

bonus: $(BONUS)

$(BONUS): $(GNL) $(PRINTF) $(BONUS_UTILS) $(BOBJS)
	$(CC) $(CFLAGS) $(BOBJS) $(GNL) $(PRINTF) $(BONUS_UTILS) -o $(BONUS)

$(PRINTF):
	@if [ ! -d "$(PRINTF_PATH)" ]; then \
		git clone https://github.com/exhilarin/ft_printf.git $(PRINTF_PATH); \
	fi
	@make -C $(PRINTF_PATH)

$(BONUS_UTILS):
	@make -C $(BONUS_UTILS_PATH)

$(UTILS):
	@make -C $(UTILS_PATH)

$(GNL):
	@make -C $(GNL_PATH)

clean:
	@rm -f $(OBJS) $(BOBJS)
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

.PHONY: all clean fclean re bonus
