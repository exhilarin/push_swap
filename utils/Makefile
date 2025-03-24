NAME = utils.a
SRCS = all_in_one.c ft_atol.c seperate_str.c ft_strlen.c ft_strncmp.c\
	ft_substr.c ft_strdup.c error.c is_digit.c action_message.c\

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