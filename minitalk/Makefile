NAME		= krome
SERVER		= enzins

CC			= gcc

CLI_SRCS	= client.c
SER_SRCS	= server.c



all: $(NAME) $(SERVER)

$(NAME): $(CLI_SRCS)
	$(CC) $(CFLAGS) -o $^ -c $@

$(SERVER): $(SER_SRCS)
	$(CC) $(CFLAGS) -o $^ -c $@

clean:
	rm -rf $(NAME) $(SERVER)

fclean: clean

re: fclean all

.PHONY: all clean fclean re