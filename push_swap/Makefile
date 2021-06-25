# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/19 17:09:40 by sashin            #+#    #+#              #
#    Updated: 2021/06/25 14:49:18 by sashin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra

SRCS		= push_swap.c dlist.c parse.c controls.c
SRCS_DIR	= srcs

OBJS		= $(SRCS:.c=.o)

LIBFT		= lib_sashin.a
LIBFT_DIR	= libft

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(addprefix $(SRCS_DIR)/, $(OBJS)) $(addprefix $(LIBFT_DIR)/, $(LIBFT))
	$(CC) $(CFLAGS) $^ -o $@

clean:
	make clean -C $(LIBFT_DIR)
	rm -rf $(addprefix $(SRCS_DIR)/, $(OBJS))

fclean:
	make fclean -C $(LIBFT_DIR)
	rm -rf $(addprefix $(SRCS_DIR)/, $(OBJS))
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
