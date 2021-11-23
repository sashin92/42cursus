# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sashin <sashin@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/23 18:20:18 by sashin            #+#    #+#              #
#    Updated: 2021/11/23 18:34:15 by sashin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= philo

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra

INCLUDES	= includes

SRCS		= philosophers.c utils.c
SRCS_DIR	= srcs

OBJS		= $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@ -I $(INCLUDES)

all: $(NAME)

$(NAME): $(addprefix $(SRCS_DIR)/, $(OBJS))
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -rf $(addprefix $(SRCS_DIR)/, $(OBJS))

fclean:
	rm -rf $(addprefix $(SRCS_DIR)/, $(OBJS))
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
