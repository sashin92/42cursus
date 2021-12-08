# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/08 16:21:09 by sashin            #+#    #+#              #
#    Updated: 2021/12/08 17:05:09 by sashin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= minishell

CC				= gcc
CFLAGS			= -Wall -Werror -Wextra
# CDEBUG			= -fsanitize=address -g
READLINE		= -lreadline

INCLUDES_DIR	= includes

SRCS			= main.c
SRCS_DIR		= srcs

OBJS			= $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@ -I $(INCLUDES_DIR)

all: $(NAME)

$(NAME): $(addprefix $(SRCS_DIR)/, $(OBJS))
	$(CC) $(CFLAGS) $(CDEBUG) $(READLINE) $^ -o $@

clean:
	rm -rf $(addprefix $(SRCS_DIR)/, $(OBJS))

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re