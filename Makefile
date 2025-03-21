NAME= push_swap
SRCS= push_swap.c take_argv.c node.c swap.c tools.c
CC= cc
CFLAGS= -Wall -Wextra -Werror -g
PRINTF_PATH = ./ft_printf
PRINTF = $(PRINTF_PATH)/libftprintf.a
UTILS_PATH = ./utils
UTILS= $(UTILS_PATH)/utils.a
OBJS= $(SRCS:.c=.o)

all: $(NAME) clean
	@clear

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

clean:
	@rm -f $(OBJS) $(PRINTF)
	@make clean -C $(PRINTF_PATH)
	@rm -f $(OBJS) $(UTILS)
	@make clean -C $(UTILS_PATH)

fclean: clean
	@rm -rf $(NAME) $(PRINTF)
	@make fclean -C $(PRINTF_PATH)
	@rm -f $(NAME) $(UTILS)
	@make fclean -C $(UTILS_PATH)
	@rm -rf ft_printf
	@rm -rf libft

re: fclean all

.PHONY: all clean re fclean