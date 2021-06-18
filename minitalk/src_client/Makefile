NAME		= client

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra

SRCS		= client.c
TOOL_SRCS	= tools.c ft_itoa.c
OBJS		= $(SRCS:.c=.o)
TOOL_OBJS	= $(TOOL_SRCS:.c=.o)
TOOL_DIR	= ../tools/

all: $(NAME)

$(NAME): $(OBJS) $(addprefix $(TOOL_DIR), $(TOOL_OBJS))
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -rf $(OBJS) $(addprefix $(TOOL_DIR), $(TOOL_OBJS))

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re