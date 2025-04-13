NAME= push_swap
SRCS= push_swap.c stack.c node.c tools.c algorithm.c support.c helpers.c \
	./actions/swap.c ./actions/push.c ./actions/rotate.c ./actions/rev_rotate.c
BONUS_SRCS= push_swap_bonus.c stack_bonus.c node_bonus.c tools_bonus.c algorithm_bonus.c support_bonus.c helpers_bonus.c \
	./actions/swap_bonus.c ./actions/push_bonus.c ./actions/rotate_bonus.c ./actions/rev_rotate_bonus.c
CC= cc
CFLAGS= -Wall -Wextra -Werror -g
PRINTF_PATH = ./ft_printf
PRINTF = $(PRINTF_PATH)/libftprintf.a
UTILS_PATH = ./utils
UTILS= $(UTILS_PATH)/utils.a
OBJS= $(SRCS:.c=.o)
BOBJS= $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(PRINTF) $(UTILS) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(UTILS) $(PRINTF) -o $(NAME)

$(PRINTF):
	@echo "Checking printf repository..."
	@if [ ! -d "$(PRINTF_PATH)" ]; then \
		echo "Cloning printf repository..."; \
		git clone https://github.com/ilyasguney/printf.git $(PRINTF_PATH); \
	else \
		echo "printf repository already exists, skipping clone."; \
	fi
	@echo "Building printf library..."
	@make -C $(PRINTF_PATH)

$(UTILS):
	@make -C $(UTILS_PATH)

bonus:	$(NAME)
	
$(BONUS): $(PRINTF) $(UTILS) $(BOBJS)
	${CC} $(CFLAGS) $(BOBJS) $(UTILS) $(PRINTF) -o $(NAME)

	@echo "Bonus target completed."
	@echo "Building bonus target..."
	@make -C $(PRINTF_PATH) bonus
	@make -C $(UTILS_PATH) bonus

clean:
	@rm -f $(OBJS) $(BOBJS)
	@make clean -C $(PRINTF_PATH)
	@make clean -C $(UTILS_PATH)
	@rm -rf $(PRINTF) $(UTILS)
	@rm -rf libftprintf.a
	@rm -rf libft.a

fclean: clean
	@rm -rf $(NAME) $(PRINTF)
	@make fclean -C $(PRINTF_PATH)
	@rm -f $(NAME) $(UTILS)
	@make fclean -C $(UTILS_PATH)
	@rm -rf ft_printf
	@rm -rf libft

re: fclean all

.PHONY: all clean fclean re