NAME = utils_bonus.a
SRCS = all_in_one_bonus.c ft_atol_bonus.c seperate_str_bonus.c ft_strlen_bonus.c ft_strncmp_bonus.c free_str_bonus.c \
	ft_substr_bonus.c ft_strdup_bonus.c is_all_spaces_bonus.c is_digit_bonus.c is_space_bonus.c action_message_bonus.c

CFLAGS = -Wall -Wextra -Werror
CC = cc
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar -rc $(NAME) $(OBJS)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean re fclean