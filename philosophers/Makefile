# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/23 18:20:18 by sashin            #+#    #+#              #
#    Updated: 2021/12/02 17:22:43 by sashin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= philo

CC				= gcc
CFLAGS			= -Wall -Werror -Wextra
CDEBUG			= -fsanitize=address -g

INCLUDES_DIR	= includes

SRCS			= philosophers.c utils.c error.c monitor.c thread.c
SRCS_DIR		= srcs

OBJS			= $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) $(CDEBUG) -c $^ -o $@ -I $(INCLUDES_DIR)

all: $(NAME)

$(NAME): $(addprefix $(SRCS_DIR)/, $(OBJS))
	$(CC) $(CFLAGS) $(CDEBUG) $^ -o $@

clean:
	rm -rf $(addprefix $(SRCS_DIR)/, $(OBJS))

fclean:
	rm -rf $(addprefix $(SRCS_DIR)/, $(OBJS))
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
