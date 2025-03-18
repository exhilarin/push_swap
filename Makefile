NAME= push_swap
SRCS= push_swap.c take_argv.c utils.c
CC= cc
CFLAGS= -Wall -Wextra -Werror -g
PRINTF_PATH = ./ft_printf
PRINTF = $(PRINTF_PATH)/libftprintf.a
LIBFT_PATH = ./libft
LIBFT= $(LIBFT_PATH)/libft.a
OBJS= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(PRINTF) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) -o $(NAME)

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

$(LIBFT):
	@echo "Checking libft repository..."
	@if [ ! -d "$(LIBFT_PATH)" ]; then \
		echo "Cloning libft repository..."; \
		git clone git@github.com:ilyasguney/libft.git $(LIBFT_PATH); \
	else \
		echo "libft repository already exists, skipping clone."; \
	fi
	@echo "Building libft library..."
	@make -C $(LIBFT_PATH)

clean:
	@rm -f $(OBJS) $(PRINTF)
	@make clean -C $(PRINTF_PATH)
	@rm -f $(OBJS) $(LIBFT)
	@make clean -C $(LIBFT_PATH)

fclean: clean
	@rm -rf $(NAME) $(PRINTF)
	@make fclean -C $(PRINTF_PATH)
	@rm -f $(NAME) $(LIBFT)
	@make fclean -C $(LIBFT_PATH)
	@rm -rf ft_printf
	@rm -rf libft

re: fclean all

.PHONY: all clean re fclean