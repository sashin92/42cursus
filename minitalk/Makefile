NAME			= minitalk
CLIENT			= client
SERVER			= server
CLIENT_DIR		= src_client
SERVER_DIR		= src_server

CC				= gcc
CFLAGS			= -Wall -Werror -Wextra

all:
	make -C $(CLIENT_DIR)
	cp $(CLIENT_DIR)/$(CLIENT) .
	make -C $(SERVER_DIR)
	cp $(SERVER_DIR)/$(SERVER) .

client:
	make -C $(CLIENT_DIR)
	cp $(CLIENT_DIR)/$(CLIENT) .

server:
	make -C $(SERVER_DIR)
	cp $(SERVER_DIR)/$(SERVER) .

clean:
	make clean -C $(CLIENT_DIR)
	make clean -C $(SERVER_DIR)

fclean:
	make fclean -C $(CLIENT_DIR)
	make fclean -C $(SERVER_DIR)
	@echo '---------------------------------------------------'
	rm -rf $(CLIENT)
	rm -rf $(SERVER)

re: fclean all

.PHONY: all clean fclean re client server